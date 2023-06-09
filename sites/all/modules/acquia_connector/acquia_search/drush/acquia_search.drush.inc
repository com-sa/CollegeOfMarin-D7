<?php

/**
 * @file
 * Drush integration for acquia_search.
 */

use Drupal\acquia_search\ApacheSolrEnvironment;

/**
 * Implements hook_drush_command().
 */
function acquia_search_drush_command() {
  $items = [];

  $items['solr-set-derived-key'] = [
    'callback' => 'acquia_search_set_derived_key_for_env',
    'description' => dt('Sets an environment to be active for Acquia search using a specific derived key.
      You should use your Acquia Identifier and Network Key to set this value.'),
    'options' => [
      'env-id' => [
        'description' => 'Apache Solr environment id.',
      ],
      'acquia-id' => [
        'description' => 'Acquia Network Subscription ID.',
      ],
      'acquia-key' => [
        'description' => 'Acquia Network Subscription Key.',
      ],
    ],
    'examples' => [
      'drush solr-set-derived-key --env-id=acquia_search_server_1_1 --acquia-id=AAAA-12345 --acquia-key=abcdefgijklmnopqrstuvw12345' => 'Set this environment to use the following keys.',
    ],
  ];
  return $items;
}

/**
 * Implements hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 */
function acquia_search_drush_help($section) {
  switch ($section) {
    case 'drush:solr-set-derived-key':
      return dt("Sets an environment to be active for Acquia search using a specific derived key.
      You should use your Acquia Identifier and Network Key to set this value.");
  }
}

/**
 * Drush callback.
 *
 * Set the derived key for a specific environment, using an id and key.
 *
 * Also set the url to point to the acquia service to make it easier for
 * customers to set any environment as an acquia environment.
 */
function acquia_search_set_derived_key_for_env() {
  drush_print(dt("This command was specific to Search v2. It can be safely removed."));
  return TRUE;

  // The following code is kept for future use. Specifically, adding the ability
  // for users to specify different subscriptions per search server.
  acquia_search_include();
  // Environment id.
  $env_id = drush_get_option('env-id');
  // Check on bool, because drush sets the var as true if no value is given.
  if (empty($env_id) || is_bool($env_id)) {
    return drush_set_error('DRUSH_VARIABLE_ERROR', dt('No apachesolr environment id specified'));
  }
  $environment = new ApacheSolrEnvironment($env_id);
  // Deny overridding the default acquia environments.
  if ($env_id == 'acquia_search_server_1' || $env_id == 'acquia_search_server_3') {
    return drush_set_error('DRUSH_VARIABLE_ERROR', dt('Modifying the original Acquia Search subscription is not allowed. Please use another environment'));
  }
  // Check if the environment is valid.
  if (empty($environment)) {
    return drush_set_error('DRUSH_ACQUIA_ERROR', dt('The specified environment does not exist'));
  }
  // Acquia network subscription id.
  $acquia_id = drush_get_option('acquia-id');
  // Check on bool, because drush sets the var as true if no value is given.
  if (empty($acquia_id) || is_bool($acquia_id)) {
    return drush_set_error('DRUSH_VARIABLE_ERROR', dt('No Acquia network subscription id specified'));
  }
  // Acquia network subscription key.
  $acquia_key = drush_get_option('acquia-key');
  // Check on bool, because drush sets the var as true if no value is given.
  if (empty($acquia_key) || !is_string($acquia_key)) {
    return drush_set_error('DRUSH_VARIABLE_ERROR', dt('No Acquia network subscription key specified'));
  }

  // We do not want to send a heartbeat to the server, we only need subscription
  // data.
  $params = [
    'active' => FALSE,
    'no_heartbeat' => 1,
  ];
  $subscription = acquia_agent_get_subscription($params, $acquia_id, $acquia_key);
  // Check if the subscription was valid.
  if (!is_array($subscription)) {
    return drush_set_error('DRUSH_ACQUIA_ERROR', dt('Could not fetch data for specified subscription.'));
  }

  // We use a salt from acquia.com in key derivation since this is a shared
  // value that we could change on the AN side if needed to force any
  // or all clients to use a new derived key.
  $salt = $subscription['derived_key_salt'] ?? '';
  if (empty($salt)) {
    return drush_set_error('DRUSH_ACQUIA_ERROR', dt('Could not get a salt.'));
  }
  $derived_key = AcquiaSearchAuth::createDerivedKey($salt, $acquia_id, $acquia_key);
  if (!empty($derived_key)) {
    $environment['url'] = 'http://search.acquia.com/solr/' . $acquia_id;
    // We want to show that this specific environment was connected to Acquia.
    // If you update the key, make sure the name is not altered twice.
    if (!strpos($environment['name'], '(connected to Acquia)')) {
      $environment['name'] = $environment['name'] . ' (connected to Acquia)';
    }

    apachesolr_environment_save($environment);
    apachesolr_environment_variable_set($env_id, 'acquia_search_key', $derived_key);
  }
  else {
    return drush_set_error('DRUSH_ACQUIA_ERROR', dt('Could not generate a derived key.'));
  }
}

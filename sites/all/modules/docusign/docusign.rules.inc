<?php


/**
 * Implements hook_rules_event_info()
 */
function docusign_rules_event_info() {
  $events = array();

  $events['docusign_rules_envelope_status_changed'] = array(
    'label' => t('A Docusign Envelope Status Has Changed.'),
    'group' => t('Docusign'),
    'variables' => array(
      'user' => array(
        'type' => 'user',
        'label' => t('User Associated with the Envelope'),
      ),
      'envelope_id' => array(
        'type' => 'text',
        'label' => t('The Envelope ID'),
      ),
      'old_status' => array(
        'type' => 'text',
        'label' => t('The Old Status'),
      ),
      'new_status' => array(
        'type' => 'text',
        'label' => t('The New Status'),
      ),
    ),
  );

  $events['docusign_invocation_error'] = array(
    'label' => t('A Docusign API invocation failed.'),
    'group' => t('Docusign'),
    'variables' => array(
      'user' => array(
        'type' => 'user',
        'label' => t('The logged in user'),
      ),
      'time' => array(
        'type' => 'date',
        'label' => t('The Error Time'),
      ),
    ),
  );

  return $events;
}



/**
 * Implements hook_rules_condition_info().
 */
function docusign_rules_condition_info() {

  $conditions = array();

  return $conditions;
}

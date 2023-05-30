<?php
/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function college_marin_form_install_configure_form_alter(&$form, $form_state) {
	$form = college_marin_configure_form($form);
}

function college_marin_configure_form($form) {

	$form['site_information']['#weight'] = -10;
	$form['site_information']['#collapsible'] = TRUE;
	$form['site_information']['#collapsed'] = TRUE;

	$host = $_SERVER['HTTP_HOST'];
	$host = explode(".",$host);
	$host = array_shift($host);
	$form['site_information']['site_name']['#default_value'] = ucwords( str_replace('-', ' ', $host));

	$form['site_information']['site_mail']['#default_value'] = "webmaster@marin.edu";

	$form['admin_account']['#weight'] = -20;
	$form['admin_account']['account']['name']['#default_value'] = "admin";
  	$form['admin_account']['account']['mail']['#default_value'] = "webmaster@marin.edu";

  	//$form['admin_account']['account']['pass']['#default_value'] = "12345";
  	/*$form['admin_account']['account']['pass']["#attributes"] = array(
	  	'value' => 'llll'
  	);*/

	$form['server_settings']['site_default_country']['#default_value'] = 'US';
	$form['server_settings']['date_default_timezone']['#default_value'] = 'America/Los_Angeles';

	$form['update_notifications']['update_status_module']['#default_value'] = array(1);

	$form['theme_settings'] = array(
		'#type' => 'fieldset',
		'#title' => t('Theme settings'),
		'#weight' => -11,
		'#collapsible' => TRUE,
		'#collapsed' => FALSE,
	);


	//$themes = college_marin_install_theme_settings();
	$theme_choices = array_map(function($theme) {
		return ucwords($theme['name']);
	}, college_marin_install_theme_settings());
	//foreach ($themes as $theme) { $theme_choices[strtolower($theme["name"])] = ucfirst($theme["name"]); }

	$form['theme_settings']['theme_choice'] = array(
		'#type' => 'radios',
	    '#title' => t('Select Theme'),
	    '#default_value' => 0,
	    '#options' => $theme_choices,
	    //'#description' => t('When a poll is closed, visitors can no longer vote for it.'),
	);

	hide( $form['server_settings'] );
	hide( $form['update_notifications'] );

	$form['#submit'][] = 'college_marin_configure_form_submit';

	return $form;
}

function college_marin_configure_form_submit(&$form, &$form_state) {

	/* init clean urls, we do this here as it
	needs to be later in the install process */
	variable_set('clean_url', 1);


	// anon users can't use wysiwyg
	// this seems to have to be done late in the install
	user_role_revoke_permissions(1, array( 'use text format wysiwyg' ));

	/* doing this here to ensure that
	webform and pathauto are installed */

	if ( module_exists('webform') && module_exists('pathauto') ) {
		variable_set('pathauto_node_webform_pattern', 'form/[node:title]');
	}

	/* set up google analytics */
	variable_set('googleanalytics_account', 'UA-9809599-1' );
	variable_set('googleanalytics_cache', 0);
	variable_set('googleanalytics_codesnippet_after', '');
	variable_set('googleanalytics_codesnippet_before', '');
	variable_set('googleanalytics_cross_domains', '');
	variable_set('googleanalytics_custom', 0);
	variable_set('googleanalytics_domain_mode', 0);
	variable_set('googleanalytics_js_scope', 'footer');
	variable_set('googleanalytics_pages', GOOGLEANALYTICS_PAGES);
	variable_set('googleanalytics_privacy_donottrack', 1);
	variable_set('googleanalytics_roles', array());
	variable_set('googleanalytics_site_search', FALSE);
	variable_set('googleanalytics_trackadsense', FALSE);
	variable_set('googleanalytics_trackdoubleclick', FALSE);
	variable_set('googleanalytics_tracker_anonymizeip', 0);
	variable_set('googleanalytics_trackfiles', 1);
	variable_set('googleanalytics_trackfiles_extensions', GOOGLEANALYTICS_TRACKFILES_EXTENSIONS);
	variable_set('googleanalytics_trackmailto', 1);
	variable_set('googleanalytics_trackmessages', array());
	variable_set('googleanalytics_trackoutbound', 1);
	variable_set('googleanalytics_visibility_pages', 0);
	variable_set('googleanalytics_visibility_roles', 0);

	variable_set('theme_choice', $form_state['values']['theme_choice']);


	$theme_choice = $form_state['values']['theme_choice'];
	if ( array_key_exists( $theme_choice, college_marin_install_theme_settings() ) ) {
		variable_set('theme_name', $theme_choice);
		college_marin_install_default( $theme_choice );
	}

}

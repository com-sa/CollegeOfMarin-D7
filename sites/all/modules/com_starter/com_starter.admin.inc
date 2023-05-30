<?php

/**
 * Implements hook_admin.
*/
function com_starter_admin() { 
	$form = array();

	$form['com_starter_settings'] = array(
		'#deafult_tab' => 'edit-',
		'#type' => 'vertical_tabs',
	);

	$form['com_starter_settings']['com_starter_services'] = array(
		'#title' => t('Services'), 
		'#type' => 'fieldset', 
		'#weight' => -10, 
	);
	
	$form['com_starter_settings']['com_starter_services']['social'] = array(
		'#title' => t('Social'), 
		'#type' => 'fieldset', 
		'#weight' => 0, 
	);	
	
	//$social_defaults = com_starter_social_default();
	
	$form['com_starter_settings']['com_starter_services']['social']['social_media_facebook'] = array(
		'#type' => 'textfield',
		'#title' => t('Facebook'),
		'#default_value' => variable_get('social_media_facebook'),
		'#description' => t('Link to your individual Facebook account.'),
		'#weight' => 0
	);	

	$form['com_starter_settings']['com_starter_services']['social']['social_media_twitter'] = array(
		'#type' => 'textfield',
		'#title' => t('Twitter'),
		'#default_value' => variable_get('social_media_twitter' ),
		'#description' => t('Link to your individual Twitter account.'),
		'#weight' => 5
	);

	$form['com_starter_settings']['com_starter_services']['social']['social_media_youtube'] = array(
		'#type' => 'textfield',
		'#title' => t('Youtube'),
		'#default_value' => variable_get('social_media_youtube' ),
		'#description' => t('Link to your individual YouYube account.'),
		'#weight' => 10
	);
	
	$form['com_starter_settings']['com_starter_services']['social']['social_media_instagram'] = array(
		'#type' => 'textfield',
		'#title' => t('Instagram'),
		'#default_value' => variable_get('social_media_instagram' ),
		'#description' => t('Link to your individual Instagram account.'),
		'#weight' => 25
	);
	
	$form['com_starter_settings']['com_starter_services']['social']['social_media_linkedin'] = array(
		'#type' => 'textfield',
		'#title' => t('LinkedIn'),
		'#default_value' => variable_get('social_media_linkedin'),
		'#description' => t('Link to your individual LinkedIn account.'),
		'#weight' => 15
	);			
	
	$form['com_starter_settings']['com_starter_services']['social']['social_media_googleplus'] = array(
		'#type' => 'textfield',
		'#title' => t('Google+'),
		'#default_value' => variable_get('social_media_googleplus' ),
		'#description' => t('Link to your individual Google+ account.'),
		'#weight' => 20
	);
	
	$form['com_starter_settings']['com_starter_services']['google'] = array(
		'#title' => t('Google Analytics'), 
		'#type' => 'fieldset', 
		'#weight' => 10, 
	);			

	$form['com_starter_settings']['com_starter_services']['google']['googleanalytics_account'] = array(
		'#type' => 'textfield',
		'#title' => t('Google Analytics'),
		//'#title_display' => 'invisible',
		'#default_value' => variable_get('googleanalytics_account'),
		'#description' => t('Add <a href="http://www.google.com/analytics/" target="_blank">Google Analytics</a> account here for web site monitoring.'),
		'#weight' => 0
	);

	$form['com_starter_settings']['com_starter_services']['google']['googlesearch_cx'] = array(
		'#type' => 'textfield',
		'#title' => t('Google Site Search'),
		'#default_value' => variable_get('googlesearch_cx'),
		'#description' => t('Add <a href="https://cse.google.com/" target="_blank">Google Custom Site Search</a> account here to enable it.'),
		'#weight' => 10
	);
	
	return system_settings_form($form);
}

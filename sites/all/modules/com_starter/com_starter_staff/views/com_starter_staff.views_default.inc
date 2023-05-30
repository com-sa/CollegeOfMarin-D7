<?php

function com_starter_staff_views_default_views() {

	$views = array();

	$view = new view();
	$view->name = 'staff';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'node';
	$view->human_name = 'Staff';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
	
	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Staff';
	$handler->display->display_options['css_class'] = 'row';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'some';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['style_options']['row_class'] = 'column medium-6 large-3 clearfix';
	$handler->display->display_options['row_plugin'] = 'fields';
	/* Field: Content: Graphic */
	$handler->display->display_options['fields']['field_staff_graphic']['id'] = 'field_staff_graphic';
	$handler->display->display_options['fields']['field_staff_graphic']['table'] = 'field_data_field_staff_graphic';
	$handler->display->display_options['fields']['field_staff_graphic']['field'] = 'field_staff_graphic';
	$handler->display->display_options['fields']['field_staff_graphic']['label'] = '';
	$handler->display->display_options['fields']['field_staff_graphic']['element_type'] = '0';
	$handler->display->display_options['fields']['field_staff_graphic']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_staff_graphic']['element_wrapper_class'] = 'staff-graphic';
	$handler->display->display_options['fields']['field_staff_graphic']['element_default_classes'] = FALSE;
	$handler->display->display_options['fields']['field_staff_graphic']['click_sort_column'] = 'fid';
	$handler->display->display_options['fields']['field_staff_graphic']['settings'] = array(
	  'image_style' => '250x250',
	  'image_link' => 'content',
	);
	/* Field: Name */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'node';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['ui_name'] = 'Name';
	$handler->display->display_options['fields']['title']['label'] = '';
	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
	$handler->display->display_options['fields']['title']['element_type'] = '0';
	$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
	$handler->display->display_options['fields']['title']['element_wrapper_class'] = 'staff-name';
	/* Field: Position */
	$handler->display->display_options['fields']['field_position']['id'] = 'field_position';
	$handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
	$handler->display->display_options['fields']['field_position']['field'] = 'field_position';
	$handler->display->display_options['fields']['field_position']['ui_name'] = 'Position';
	$handler->display->display_options['fields']['field_position']['label'] = '';
	$handler->display->display_options['fields']['field_position']['element_type'] = '0';
	$handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_position']['element_wrapper_class'] = 'staff-position';
	$handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
	/* Field: Phone Number */
	$handler->display->display_options['fields']['field_phone_number']['id'] = 'field_phone_number';
	$handler->display->display_options['fields']['field_phone_number']['table'] = 'field_data_field_phone_number';
	$handler->display->display_options['fields']['field_phone_number']['field'] = 'field_phone_number';
	$handler->display->display_options['fields']['field_phone_number']['ui_name'] = 'Phone Number';
	$handler->display->display_options['fields']['field_phone_number']['label'] = '';
	$handler->display->display_options['fields']['field_phone_number']['alter']['make_link'] = TRUE;
	$handler->display->display_options['fields']['field_phone_number']['alter']['path'] = 'tel:[field_phone_number-value]';
	$handler->display->display_options['fields']['field_phone_number']['element_type'] = '0';
	$handler->display->display_options['fields']['field_phone_number']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_phone_number']['element_wrapper_class'] = 'staff-phone';
	$handler->display->display_options['fields']['field_phone_number']['element_default_classes'] = FALSE;
	/* Field: Email */
	$handler->display->display_options['fields']['field_email']['id'] = 'field_email';
	$handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
	$handler->display->display_options['fields']['field_email']['field'] = 'field_email';
	$handler->display->display_options['fields']['field_email']['ui_name'] = 'Email';
	$handler->display->display_options['fields']['field_email']['label'] = '';
	$handler->display->display_options['fields']['field_email']['alter']['alter_text'] = TRUE;
	$handler->display->display_options['fields']['field_email']['alter']['text'] = '<a href="[field_email-email]" data-email>[field_email-email]</a>';
	$handler->display->display_options['fields']['field_email']['element_type'] = '0';
	$handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_email']['element_wrapper_class'] = 'staff-email';
	$handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
	$handler->display->display_options['fields']['field_email']['empty'] = '[title]';
	$handler->display->display_options['fields']['field_email']['type'] = 'email_plain';
	/* Sort criterion: Content: Title */
	$handler->display->display_options['sorts']['title']['id'] = 'title';
	$handler->display->display_options['sorts']['title']['table'] = 'node';
	$handler->display->display_options['sorts']['title']['field'] = 'title';
	/* Filter criterion: Content: Published */
	$handler->display->display_options['filters']['status']['id'] = 'status';
	$handler->display->display_options['filters']['status']['table'] = 'node';
	$handler->display->display_options['filters']['status']['field'] = 'status';
	$handler->display->display_options['filters']['status']['value'] = 1;
	$handler->display->display_options['filters']['status']['group'] = 1;
	$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
	/* Filter criterion: Content: Type */
	$handler->display->display_options['filters']['type']['id'] = 'type';
	$handler->display->display_options['filters']['type']['table'] = 'node';
	$handler->display->display_options['filters']['type']['field'] = 'type';
	$handler->display->display_options['filters']['type']['value'] = array(
	  'staff' => 'staff',
	);
	
	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['path'] = 'staff';

		
	$views[$view->name] = $view;
	return $views;	
}
<?php 

function com_starter_events_views_default_views() {

	$views = array();

	$view = new view();
	$view->name = 'events';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'node';
	$view->human_name = 'Events';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
	
	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'input_required';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['style_options']['row_class'] = 'row';
	$handler->display->display_options['style_options']['default_row_class'] = FALSE;
	$handler->display->display_options['style_options']['row_class_special'] = FALSE;
	$handler->display->display_options['row_plugin'] = 'fields';
	/* Field: Content: Path */
	$handler->display->display_options['fields']['path']['id'] = 'path';
	$handler->display->display_options['fields']['path']['table'] = 'node';
	$handler->display->display_options['fields']['path']['field'] = 'path';
	$handler->display->display_options['fields']['path']['label'] = '';
	$handler->display->display_options['fields']['path']['exclude'] = TRUE;
	$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
	/* Field: Month */
	$handler->display->display_options['fields']['field_date']['id'] = 'field_date';
	$handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
	$handler->display->display_options['fields']['field_date']['field'] = 'field_date';
	$handler->display->display_options['fields']['field_date']['ui_name'] = 'Month';
	$handler->display->display_options['fields']['field_date']['label'] = '';
	$handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
	$handler->display->display_options['fields']['field_date']['alter']['alter_text'] = TRUE;
	$handler->display->display_options['fields']['field_date']['alter']['text'] = '<span class="month">[field_date]</span>';
	$handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_date']['settings'] = array(
	  'format_type' => 'com_starter_short_month',
	  'fromto' => 'both',
	  'multiple_number' => '',
	  'multiple_from' => '',
	  'multiple_to' => '',
	  'show_remaining_days' => 0,
	  'show_repeat_rule' => 'show',
	);
	/* Field: Day */
	$handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
	$handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
	$handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
	$handler->display->display_options['fields']['field_date_1']['ui_name'] = 'Day';
	$handler->display->display_options['fields']['field_date_1']['label'] = '';
	$handler->display->display_options['fields']['field_date_1']['exclude'] = TRUE;
	$handler->display->display_options['fields']['field_date_1']['alter']['alter_text'] = TRUE;
	$handler->display->display_options['fields']['field_date_1']['alter']['text'] = '<span class="day">[field_date_1]</span>';
	$handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_date_1']['settings'] = array(
	  'format_type' => 'com_starter_day',
	  'fromto' => 'both',
	  'multiple_number' => '',
	  'multiple_from' => '',
	  'multiple_to' => '',
	  'show_remaining_days' => 0,
	  'show_repeat_rule' => 'show',
	);
	/* Field: Time */
	$handler->display->display_options['fields']['field_date_2']['id'] = 'field_date_2';
	$handler->display->display_options['fields']['field_date_2']['table'] = 'field_data_field_date';
	$handler->display->display_options['fields']['field_date_2']['field'] = 'field_date';
	$handler->display->display_options['fields']['field_date_2']['ui_name'] = 'Time';
	$handler->display->display_options['fields']['field_date_2']['label'] = '';
	$handler->display->display_options['fields']['field_date_2']['exclude'] = TRUE;
	$handler->display->display_options['fields']['field_date_2']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_date_2']['settings'] = array(
	  'format_type' => 'com_starter_time',
	  'fromto' => 'both',
	  'multiple_number' => '',
	  'multiple_from' => '',
	  'multiple_to' => '',
	  'show_remaining_days' => 0,
	  'show_repeat_rule' => 'show',
	);
	/* Field: Title */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'node';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['ui_name'] = 'Title';
	$handler->display->display_options['fields']['title']['label'] = '';
	$handler->display->display_options['fields']['title']['exclude'] = TRUE;
	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
	$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
	/* Field: Location */
	$handler->display->display_options['fields']['field_location']['id'] = 'field_location';
	$handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
	$handler->display->display_options['fields']['field_location']['field'] = 'field_location';
	$handler->display->display_options['fields']['field_location']['ui_name'] = 'Location';
	$handler->display->display_options['fields']['field_location']['label'] = '';
	$handler->display->display_options['fields']['field_location']['exclude'] = TRUE;
	$handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
	/* Field: Body */
	$handler->display->display_options['fields']['body']['id'] = 'body';
	$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
	$handler->display->display_options['fields']['body']['field'] = 'body';
	$handler->display->display_options['fields']['body']['ui_name'] = 'Body';
	$handler->display->display_options['fields']['body']['label'] = '';
	$handler->display->display_options['fields']['body']['exclude'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['max_length'] = '500';
	$handler->display->display_options['fields']['body']['alter']['ellipsis'] = FALSE;
	$handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'Continue Reading';
	$handler->display->display_options['fields']['body']['alter']['more_link_path'] = '[path]';
	$handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
	$handler->display->display_options['fields']['body']['element_type'] = '0';
	$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
	$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
	$handler->display->display_options['fields']['body']['settings'] = array(
	  'trim_length' => '500',
	);
	/* Field: Global: Custom text */
	$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
	$handler->display->display_options['fields']['nothing']['table'] = 'views';
	$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
	$handler->display->display_options['fields']['nothing']['label'] = '';
	$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="column large-1 medium-2 small-3 date">
									    [field_date]
									    [field_date_1]
									</div>
									<div class="column large-11 medium-10 small-9">
									    <h3>[title]</h3>
									   <div class="row">
									        <div class="column small-6 time">[field_date_2]</div>
									        <div class="column small-6 location">[field_location]</div>
									    </div>
									    <div class="body">[body]</div>
									</div>';
	$handler->display->display_options['fields']['nothing']['element_type'] = '0';
	$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
	$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
	/* Sort criterion: Content: Post date */
	$handler->display->display_options['sorts']['created']['id'] = 'created';
	$handler->display->display_options['sorts']['created']['table'] = 'node';
	$handler->display->display_options['sorts']['created']['field'] = 'created';
	$handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
	  'event' => 'event',
	);
	
	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['defaults']['title'] = FALSE;
	$handler->display->display_options['title'] = 'Events';
	$handler->display->display_options['path'] = 'events';
	
	/* Display: Block */
	$handler = $view->new_display('block', 'Block', 'feed');
	$handler->display->display_options['defaults']['title'] = FALSE;
	$handler->display->display_options['title'] = 'Upcoming Events';
	$handler->display->display_options['defaults']['use_ajax'] = FALSE;
	$handler->display->display_options['use_ajax'] = TRUE;
	$handler->display->display_options['defaults']['exposed_form'] = FALSE;
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['defaults']['pager'] = FALSE;
	$handler->display->display_options['pager']['type'] = 'some';
	$handler->display->display_options['pager']['options']['items_per_page'] = '3';
	$handler->display->display_options['defaults']['header'] = FALSE;
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	$handler->display->display_options['header']['area']['content'] = '<ul class="tab-controller row">
	    <li data-trigger="1" class="column small-6 active">Important</li>	
	    <li data-trigger="All" class="column small-6">Upcoming</li>
	</ul>';
	$handler->display->display_options['header']['area']['format'] = 'wysiwyg';
	$handler->display->display_options['defaults']['footer'] = FALSE;
	/* Footer: Global: Text area */
	$handler->display->display_options['footer']['area']['id'] = 'area';
	$handler->display->display_options['footer']['area']['table'] = 'views';
	$handler->display->display_options['footer']['area']['field'] = 'area';
	$handler->display->display_options['footer']['area']['content'] = '<a href="/events" class="button">See All Events</a>';
	$handler->display->display_options['footer']['area']['format'] = 'wysiwyg';
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: Content: Path */
	$handler->display->display_options['fields']['path']['id'] = 'path';
	$handler->display->display_options['fields']['path']['table'] = 'node';
	$handler->display->display_options['fields']['path']['field'] = 'path';
	$handler->display->display_options['fields']['path']['label'] = '';
	$handler->display->display_options['fields']['path']['exclude'] = TRUE;
	$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
	/* Field: Month */
	$handler->display->display_options['fields']['field_date']['id'] = 'field_date';
	$handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
	$handler->display->display_options['fields']['field_date']['field'] = 'field_date';
	$handler->display->display_options['fields']['field_date']['ui_name'] = 'Month';
	$handler->display->display_options['fields']['field_date']['label'] = '';
	$handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
	$handler->display->display_options['fields']['field_date']['alter']['alter_text'] = TRUE;
	$handler->display->display_options['fields']['field_date']['alter']['text'] = '<span class="month">[field_date]</span>';
	$handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_date']['settings'] = array(
	  'format_type' => 'com_starter_short_month',
	  'fromto' => 'both',
	  'multiple_number' => '',
	  'multiple_from' => '',
	  'multiple_to' => '',
	  'show_remaining_days' => 0,
	  'show_repeat_rule' => 'show',
	);
	/* Field: Day */
	$handler->display->display_options['fields']['field_date_1']['id'] = 'field_date_1';
	$handler->display->display_options['fields']['field_date_1']['table'] = 'field_data_field_date';
	$handler->display->display_options['fields']['field_date_1']['field'] = 'field_date';
	$handler->display->display_options['fields']['field_date_1']['ui_name'] = 'Day';
	$handler->display->display_options['fields']['field_date_1']['label'] = '';
	$handler->display->display_options['fields']['field_date_1']['exclude'] = TRUE;
	$handler->display->display_options['fields']['field_date_1']['alter']['alter_text'] = TRUE;
	$handler->display->display_options['fields']['field_date_1']['alter']['text'] = '<span class="day">[field_date_1]</span>';
	$handler->display->display_options['fields']['field_date_1']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_date_1']['settings'] = array(
	  'format_type' => 'com_starter_day',
	  'fromto' => 'both',
	  'multiple_number' => '',
	  'multiple_from' => '',
	  'multiple_to' => '',
	  'show_remaining_days' => 0,
	  'show_repeat_rule' => 'show',
	);
	/* Field: Time */
	$handler->display->display_options['fields']['field_date_2']['id'] = 'field_date_2';
	$handler->display->display_options['fields']['field_date_2']['table'] = 'field_data_field_date';
	$handler->display->display_options['fields']['field_date_2']['field'] = 'field_date';
	$handler->display->display_options['fields']['field_date_2']['ui_name'] = 'Time';
	$handler->display->display_options['fields']['field_date_2']['label'] = '';
	$handler->display->display_options['fields']['field_date_2']['exclude'] = TRUE;
	$handler->display->display_options['fields']['field_date_2']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_date_2']['settings'] = array(
	  'format_type' => 'com_starter_time',
	  'fromto' => 'both',
	  'multiple_number' => '',
	  'multiple_from' => '',
	  'multiple_to' => '',
	  'show_repeat_rule' => 'show',
	);
	/* Field: Location */
	$handler->display->display_options['fields']['field_location']['id'] = 'field_location';
	$handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
	$handler->display->display_options['fields']['field_location']['field'] = 'field_location';
	$handler->display->display_options['fields']['field_location']['ui_name'] = 'Location';
	$handler->display->display_options['fields']['field_location']['label'] = '';
	$handler->display->display_options['fields']['field_location']['exclude'] = TRUE;
	$handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
	/* Field: Title */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'node';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['ui_name'] = 'Title';
	$handler->display->display_options['fields']['title']['label'] = '';
	$handler->display->display_options['fields']['title']['exclude'] = TRUE;
	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
	$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
	/* Field: Date */
	$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
	$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
	$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
	$handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Date';
	$handler->display->display_options['fields']['nothing_1']['label'] = '';
	$handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
	$handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_date]
											[field_date_1] ';
	$handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
	/* Field: Title and Info */
	$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
	$handler->display->display_options['fields']['nothing']['table'] = 'views';
	$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
	$handler->display->display_options['fields']['nothing']['ui_name'] = 'Title and Info';
	$handler->display->display_options['fields']['nothing']['label'] = '';
	$handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
	$handler->display->display_options['fields']['nothing']['alter']['text'] = '<h6 class="title>[title]</h6>
											<div class="info"><span class="time">[field_date_2]</span> <span class="location">[field_location]</span></div>';
	$handler->display->display_options['fields']['nothing']['element_type'] = '0';
	$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'column medium-8';
	/* Field: Output */
	$handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
	$handler->display->display_options['fields']['nothing_2']['table'] = 'views';
	$handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
	$handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Output';
	$handler->display->display_options['fields']['nothing_2']['label'] = '';
	$handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<div class="column small-2 date">[nothing_1]</div>
											<div class="column small-10 title-info">[nothing]</div>';
	$handler->display->display_options['fields']['nothing_2']['element_type'] = '0';
	$handler->display->display_options['fields']['nothing_2']['element_label_type'] = '0';
	$handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['nothing_2']['element_wrapper_type'] = '0';
	$handler->display->display_options['fields']['nothing_2']['element_default_classes'] = FALSE;
	$handler->display->display_options['defaults']['filter_groups'] = FALSE;
	$handler->display->display_options['defaults']['filters'] = FALSE;
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
	  'event' => 'event',
	);
	/* Filter criterion: Content: Promoted to front page */
	$handler->display->display_options['filters']['promote']['id'] = 'promote';
	$handler->display->display_options['filters']['promote']['table'] = 'node';
	$handler->display->display_options['filters']['promote']['field'] = 'promote';
	$handler->display->display_options['filters']['promote']['value'] = '1';
	$handler->display->display_options['filters']['promote']['exposed'] = TRUE;
	$handler->display->display_options['filters']['promote']['expose']['operator_id'] = '';
	$handler->display->display_options['filters']['promote']['expose']['label'] = 'Important';
	$handler->display->display_options['filters']['promote']['expose']['operator'] = 'promote_op';
	$handler->display->display_options['filters']['promote']['expose']['identifier'] = 'promote';
	$handler->display->display_options['filters']['promote']['expose']['remember_roles'] = array(
	  2 => '2',
	  1 => 0,
	  3 => 0,
	  4 => 0,
	);


	/* Display: Events CSV */
	$handler = $view->new_display('views_data_export', 'Events CSV', 'views_data_export_1');
	$handler->display->display_options['pager']['type'] = 'some';
	$handler->display->display_options['pager']['options']['items_per_page'] = '0';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['style_plugin'] = 'views_data_export_csv';
	$handler->display->display_options['style_options']['provide_file'] = 1;
	$handler->display->display_options['style_options']['parent_sort'] = 0;
	$handler->display->display_options['style_options']['quote'] = 1;
	$handler->display->display_options['style_options']['trim'] = 1;
	$handler->display->display_options['style_options']['replace_newlines'] = 0;
	$handler->display->display_options['style_options']['newline_token'] = '1';
	$handler->display->display_options['style_options']['header'] = 1;
	$handler->display->display_options['style_options']['keep_html'] = 0;
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: Content: Path */
	$handler->display->display_options['fields']['path']['id'] = 'path';
	$handler->display->display_options['fields']['path']['table'] = 'node';
	$handler->display->display_options['fields']['path']['field'] = 'path';
	$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['path']['absolute'] = TRUE;
	/* Field: Title */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'node';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['ui_name'] = 'Title';
	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
	$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
	/* Field: Content: Date */
	$handler->display->display_options['fields']['field_date']['id'] = 'field_date';
	$handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
	$handler->display->display_options['fields']['field_date']['field'] = 'field_date';
	$handler->display->display_options['fields']['field_date']['alter']['alter_text'] = TRUE;
	$handler->display->display_options['fields']['field_date']['alter']['text'] = '<span class="month">[field_date]</span>';
	$handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_date']['type'] = 'date_plain';
	$handler->display->display_options['fields']['field_date']['settings'] = array(
	  'format_type' => 'long',
	  'fromto' => 'both',
	  'multiple_number' => '',
	  'multiple_from' => '',
	  'multiple_to' => '',
	  'show_remaining_days' => 0,
	);
	/* Field: Content: Presenter */
	$handler->display->display_options['fields']['field_presenter']['id'] = 'field_presenter';
	$handler->display->display_options['fields']['field_presenter']['table'] = 'field_data_field_presenter';
	$handler->display->display_options['fields']['field_presenter']['field'] = 'field_presenter';
	/* Field: Content: Contact */
	$handler->display->display_options['fields']['field_contact']['id'] = 'field_contact';
	$handler->display->display_options['fields']['field_contact']['table'] = 'field_data_field_contact';
	$handler->display->display_options['fields']['field_contact']['field'] = 'field_contact';
	/* Field: Content: Fee */
	$handler->display->display_options['fields']['field_fee']['id'] = 'field_fee';
	$handler->display->display_options['fields']['field_fee']['table'] = 'field_data_field_fee';
	$handler->display->display_options['fields']['field_fee']['field'] = 'field_fee';
	/* Field: Location */
	$handler->display->display_options['fields']['field_location']['id'] = 'field_location';
	$handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
	$handler->display->display_options['fields']['field_location']['field'] = 'field_location';
	$handler->display->display_options['fields']['field_location']['ui_name'] = 'Location';
	$handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
	/* Field: Body */
	$handler->display->display_options['fields']['body']['id'] = 'body';
	$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
	$handler->display->display_options['fields']['body']['field'] = 'body';
	$handler->display->display_options['fields']['body']['ui_name'] = 'Body';
	$handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['max_length'] = '500';
	$handler->display->display_options['fields']['body']['alter']['ellipsis'] = FALSE;
	$handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'Continue Reading';
	$handler->display->display_options['fields']['body']['alter']['more_link_path'] = '[path]';
	$handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
	$handler->display->display_options['fields']['body']['element_type'] = '0';
	$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
	$handler->display->display_options['fields']['body']['type'] = 'text_plain';
	$handler->display->display_options['fields']['body']['settings'] = array(
	  'trim_length' => '500',
	);
	$handler->display->display_options['defaults']['filter_groups'] = FALSE;
	$handler->display->display_options['defaults']['filters'] = FALSE;
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
	  'event' => 'event',
	);
	/* Filter criterion: Content: Date (field_date) */
	$handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
	$handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
	$handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
	$handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
	$handler->display->display_options['filters']['field_date_value']['granularity'] = 'minute';
	$handler->display->display_options['filters']['field_date_value']['default_date'] = 'now';
	$handler->display->display_options['filters']['field_date_value']['year_range'] = '-0:+3';
	$handler->display->display_options['path'] = 'feeds';




	$views[$view->name] = $view;
	return $views;
}
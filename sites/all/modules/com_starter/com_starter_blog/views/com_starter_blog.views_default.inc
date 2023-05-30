<?php 

function com_starter_blog_views_default_views() {

	$views = array();



	/* BLOG */
	$view = new view();
	$view->name = 'blog';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'node';
	$view->human_name = 'Blog';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
	
	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '20';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['pager']['options']['id'] = '0';
	$handler->display->display_options['pager']['options']['quantity'] = '9';
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['style_options']['grouping'] = array(
	  0 => array(
	    'field' => 'created',
	    'rendered' => 1,
	    'rendered_strip' => 1,
	  ),
	);
	$handler->display->display_options['style_options']['row_class'] = 'row';
	$handler->display->display_options['row_plugin'] = 'fields';
	$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
	/* Field: Content: Path */
	$handler->display->display_options['fields']['path']['id'] = 'path';
	$handler->display->display_options['fields']['path']['table'] = 'node';
	$handler->display->display_options['fields']['path']['field'] = 'path';
	$handler->display->display_options['fields']['path']['label'] = '';
	$handler->display->display_options['fields']['path']['exclude'] = TRUE;
	$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
	/* Field: Content: Thumbnail */
	$handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
	$handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
	$handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
	$handler->display->display_options['fields']['field_thumbnail']['label'] = '';
	$handler->display->display_options['fields']['field_thumbnail']['element_type'] = '0';
	$handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
	$handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
	  'image_style' => '250x250',
	  'image_link' => 'content',
	);
	/* Field: Content: Title */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'node';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['label'] = '';
	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
	$handler->display->display_options['fields']['title']['element_type'] = 'h4';
	$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
	$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
	/* Field: Content: Body */
	$handler->display->display_options['fields']['body']['id'] = 'body';
	$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
	$handler->display->display_options['fields']['body']['field'] = 'body';
	$handler->display->display_options['fields']['body']['label'] = '';
	$handler->display->display_options['fields']['body']['alter']['max_length'] = '100';
	$handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'Continue Reading';
	$handler->display->display_options['fields']['body']['alter']['more_link_path'] = '[path]';
	$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['html'] = TRUE;
	$handler->display->display_options['fields']['body']['element_type'] = '0';
	$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
	$handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
	$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
	$handler->display->display_options['fields']['body']['settings'] = array(
	  'trim_length' => '200',
	);
	$handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
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
	  'article' => 'article',
	);
	/* Filter criterion: Content: Post date */
	$handler->display->display_options['filters']['created']['id'] = 'created';
	$handler->display->display_options['filters']['created']['table'] = 'node';
	$handler->display->display_options['filters']['created']['field'] = 'created';
	$handler->display->display_options['filters']['created']['operator'] = '<=';
	$handler->display->display_options['filters']['created']['value']['value'] = 'now';
	$handler->display->display_options['filters']['created']['value']['type'] = 'offset';
	
	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['defaults']['title'] = FALSE;
	$handler->display->display_options['title'] = 'Latest Blog Posts';
	$handler->display->display_options['defaults']['style_plugin'] = FALSE;
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['style_options']['row_class'] = 'row clearfix';
	$handler->display->display_options['style_options']['default_row_class'] = FALSE;
	$handler->display->display_options['style_options']['row_class_special'] = FALSE;
	$handler->display->display_options['defaults']['style_options'] = FALSE;
	$handler->display->display_options['defaults']['row_plugin'] = FALSE;
	$handler->display->display_options['row_plugin'] = 'fields';
	$handler->display->display_options['defaults']['row_options'] = FALSE;
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: Content: Path */
	$handler->display->display_options['fields']['path']['id'] = 'path';
	$handler->display->display_options['fields']['path']['table'] = 'node';
	$handler->display->display_options['fields']['path']['field'] = 'path';
	$handler->display->display_options['fields']['path']['label'] = '';
	$handler->display->display_options['fields']['path']['exclude'] = TRUE;
	$handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
	/* Field: Content: Thumbnail */
	$handler->display->display_options['fields']['field_thumbnail']['id'] = 'field_thumbnail';
	$handler->display->display_options['fields']['field_thumbnail']['table'] = 'field_data_field_thumbnail';
	$handler->display->display_options['fields']['field_thumbnail']['field'] = 'field_thumbnail';
	$handler->display->display_options['fields']['field_thumbnail']['label'] = '';
	$handler->display->display_options['fields']['field_thumbnail']['element_type'] = '0';
	$handler->display->display_options['fields']['field_thumbnail']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_thumbnail']['element_wrapper_class'] = 'column medium-2';
	$handler->display->display_options['fields']['field_thumbnail']['click_sort_column'] = 'fid';
	$handler->display->display_options['fields']['field_thumbnail']['settings'] = array(
	  'image_style' => '250x250',
	  'image_link' => 'content',
	);
	/* Field: Content: Title */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'node';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['label'] = '';
	$handler->display->display_options['fields']['title']['exclude'] = TRUE;
	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
	$handler->display->display_options['fields']['title']['element_type'] = 'h4';
	$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
	$handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
	/* Field: Content: Body */
	$handler->display->display_options['fields']['body']['id'] = 'body';
	$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
	$handler->display->display_options['fields']['body']['field'] = 'body';
	$handler->display->display_options['fields']['body']['label'] = '';
	$handler->display->display_options['fields']['body']['exclude'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['max_length'] = '500';
	$handler->display->display_options['fields']['body']['alter']['ellipsis'] = FALSE;
	$handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'Continue Reading';
	$handler->display->display_options['fields']['body']['alter']['more_link_path'] = '[path]';
	$handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
	$handler->display->display_options['fields']['body']['element_type'] = '0';
	$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
	$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
	$handler->display->display_options['fields']['body']['settings'] = array(
	  'trim_length' => '500',
	);
	/* Field: Title and Body */
	$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
	$handler->display->display_options['fields']['nothing']['table'] = 'views';
	$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
	$handler->display->display_options['fields']['nothing']['ui_name'] = 'Title and Body';
	$handler->display->display_options['fields']['nothing']['label'] = '';
	$handler->display->display_options['fields']['nothing']['alter']['text'] = '<h4 class="title">[title]</h4>
						<div class="content">[body]</div>';
	$handler->display->display_options['fields']['nothing']['element_type'] = '0';
	$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'column medium-10';
	$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
	$handler->display->display_options['defaults']['arguments'] = FALSE;
	/* Contextual filter: Content: Has taxonomy term ID */
	$handler->display->display_options['arguments']['tid']['id'] = 'tid';
	$handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
	$handler->display->display_options['arguments']['tid']['field'] = 'tid';
	$handler->display->display_options['arguments']['tid']['title_enable'] = TRUE;
	$handler->display->display_options['arguments']['tid']['title'] = 'Blog Posts Tagged: %1';
	$handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
	$handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
	$handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
	$handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
	$handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
	$handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
	$handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
	  'tags' => 'tags',
	);
	$handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
	$handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
	/* Contextual filter: Content: Created year + month */
	$handler->display->display_options['arguments']['created_year_month']['id'] = 'created_year_month';
	$handler->display->display_options['arguments']['created_year_month']['table'] = 'node';
	$handler->display->display_options['arguments']['created_year_month']['field'] = 'created_year_month';
	$handler->display->display_options['arguments']['created_year_month']['title_enable'] = TRUE;
	$handler->display->display_options['arguments']['created_year_month']['title'] = 'Blog Posts %2';
	$handler->display->display_options['arguments']['created_year_month']['default_argument_type'] = 'fixed';
	$handler->display->display_options['arguments']['created_year_month']['summary']['number_of_records'] = '0';
	$handler->display->display_options['arguments']['created_year_month']['summary']['format'] = 'default_summary';
	$handler->display->display_options['arguments']['created_year_month']['summary_options']['items_per_page'] = '25';
	$handler->display->display_options['path'] = 'blog';
	
	/* Display: Top Stories */
	$handler = $view->new_display('block', 'Top Stories', 'top_stories');
	$handler->display->display_options['defaults']['title'] = FALSE;
	$handler->display->display_options['title'] = 'Top Stories';
	$handler->display->display_options['defaults']['css_class'] = FALSE;
	$handler->display->display_options['css_class'] = 'carousel test';
	$handler->display->display_options['defaults']['pager'] = FALSE;
	$handler->display->display_options['pager']['type'] = 'some';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['defaults']['style_plugin'] = FALSE;
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['defaults']['style_options'] = FALSE;
	$handler->display->display_options['defaults']['row_plugin'] = FALSE;
	$handler->display->display_options['row_plugin'] = 'fields';
	$handler->display->display_options['defaults']['row_options'] = FALSE;
	$handler->display->display_options['defaults']['header'] = FALSE;
	/* Header: Global: Text area */
	$handler->display->display_options['header']['area']['id'] = 'area';
	$handler->display->display_options['header']['area']['table'] = 'views';
	$handler->display->display_options['header']['area']['field'] = 'area';
	$handler->display->display_options['header']['area']['content'] = '<a href="/blog" class="carousel-all">See All</a>';
	$handler->display->display_options['header']['area']['format'] = 'wysiwyg';
	$handler->display->display_options['header']['area']['tokenize'] = TRUE;
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
	  'article' => 'article',
	);
	/* Filter criterion: Content: Post date */
	$handler->display->display_options['filters']['created']['id'] = 'created';
	$handler->display->display_options['filters']['created']['table'] = 'node';
	$handler->display->display_options['filters']['created']['field'] = 'created';
	$handler->display->display_options['filters']['created']['operator'] = '<=';
	$handler->display->display_options['filters']['created']['value']['value'] = 'now';
	$handler->display->display_options['filters']['created']['value']['type'] = 'offset';
	
	/* Display: Archives */
	$handler = $view->new_display('block', 'Archives', 'archives');
	$handler->display->display_options['defaults']['title'] = FALSE;
	$handler->display->display_options['title'] = 'Archives';
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: Content: Post date */
	$handler->display->display_options['fields']['created']['id'] = 'created';
	$handler->display->display_options['fields']['created']['table'] = 'node';
	$handler->display->display_options['fields']['created']['field'] = 'created';
	$handler->display->display_options['fields']['created']['label'] = '';
	$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['created']['date_format'] = 'com_starter_short_month';
	$handler->display->display_options['fields']['created']['second_date_format'] = 'com_starter_day';
	$handler->display->display_options['defaults']['arguments'] = FALSE;
	/* Contextual filter: Content: Created year + month */
	$handler->display->display_options['arguments']['created_year_month']['id'] = 'created_year_month';
	$handler->display->display_options['arguments']['created_year_month']['table'] = 'node';
	$handler->display->display_options['arguments']['created_year_month']['field'] = 'created_year_month';
	$handler->display->display_options['arguments']['created_year_month']['default_action'] = 'summary';
	$handler->display->display_options['arguments']['created_year_month']['default_argument_type'] = 'fixed';
	$handler->display->display_options['arguments']['created_year_month']['summary']['sort_order'] = 'desc';
	$handler->display->display_options['arguments']['created_year_month']['summary']['number_of_records'] = '0';
	$handler->display->display_options['arguments']['created_year_month']['summary']['format'] = 'default_summary';
	$handler->display->display_options['arguments']['created_year_month']['summary_options']['base_path'] = 'blog/all';
	$handler->display->display_options['arguments']['created_year_month']['summary_options']['count'] = FALSE;
	$handler->display->display_options['arguments']['created_year_month']['summary_options']['items_per_page'] = '25';



    $views[$view->name] = $view;
	/* END BLOG CATEGORIES */








	return $views;

}
<?php

function com_starter_views_default_views() {

	$views = array();

	$view = new view();
	$view->name = 'featured';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'node';
	$view->human_name = 'Featured';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
	
	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Featured';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '10';
	$handler->display->display_options['style_plugin'] = 'default';
	$handler->display->display_options['style_options']['row_class'] = 'row';
	$handler->display->display_options['row_plugin'] = 'fields';
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
	$handler->display->display_options['fields']['field_thumbnail']['element_default_classes'] = FALSE;
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
	$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
	/* Field: Content: Body */
	$handler->display->display_options['fields']['body']['id'] = 'body';
	$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
	$handler->display->display_options['fields']['body']['field'] = 'body';
	$handler->display->display_options['fields']['body']['label'] = '';
	$handler->display->display_options['fields']['body']['exclude'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['max_length'] = '250';
	$handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'Continue Reading';
	$handler->display->display_options['fields']['body']['alter']['more_link_path'] = '[path]';
	$handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
	$handler->display->display_options['fields']['body']['element_type'] = '0';
	$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
	/* Field: Title and Body */
	$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
	$handler->display->display_options['fields']['nothing']['table'] = 'views';
	$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
	$handler->display->display_options['fields']['nothing']['ui_name'] = 'Title and Body';
	$handler->display->display_options['fields']['nothing']['label'] = '';
	$handler->display->display_options['fields']['nothing']['alter']['text'] = '<h4 class="title>[title]</h4>
		    <div class="content">[body]</div>';
	$handler->display->display_options['fields']['nothing']['element_type'] = '0';
	$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'column medium-10';
	$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
	/* Sort criterion: Weight: Weight */
	$handler->display->display_options['sorts']['weight']['id'] = 'weight';
	$handler->display->display_options['sorts']['weight']['table'] = 'weight_weights';
	$handler->display->display_options['sorts']['weight']['field'] = 'weight';
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
	  'page' => 'page',
	);
	/* Filter criterion: Content: Promoted to front page */
	$handler->display->display_options['filters']['promote']['id'] = 'promote';
	$handler->display->display_options['filters']['promote']['table'] = 'node';
	$handler->display->display_options['filters']['promote']['field'] = 'promote';
	$handler->display->display_options['filters']['promote']['value'] = '1';
	
	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['path'] = 'featured';
	
	/* Display: Block */
	$handler = $view->new_display('block', 'Block', 'feed');
	$handler->display->display_options['defaults']['pager'] = FALSE;
	$handler->display->display_options['pager']['type'] = 'some';
	$handler->display->display_options['pager']['options']['items_per_page'] = '4';
	$handler->display->display_options['defaults']['footer'] = FALSE;
	/* Footer: Global: Text area */
	$handler->display->display_options['footer']['area']['id'] = 'area';
	$handler->display->display_options['footer']['area']['table'] = 'views';
	$handler->display->display_options['footer']['area']['field'] = 'area';
	$handler->display->display_options['footer']['area']['content'] = '<a href="/featured" class="button">See More</a>';
	$handler->display->display_options['footer']['area']['format'] = 'wysiwyg';
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
	$handler->display->display_options['fields']['field_thumbnail']['element_wrapper_class'] = 'column medium-4';
	$handler->display->display_options['fields']['field_thumbnail']['element_default_classes'] = FALSE;
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
	$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
	/* Field: Content: Body */
	$handler->display->display_options['fields']['body']['id'] = 'body';
	$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
	$handler->display->display_options['fields']['body']['field'] = 'body';
	$handler->display->display_options['fields']['body']['label'] = '';
	$handler->display->display_options['fields']['body']['exclude'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['max_length'] = '250';
	$handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'Continue Reading';
	$handler->display->display_options['fields']['body']['alter']['more_link_path'] = '[path]';
	$handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
	$handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
	$handler->display->display_options['fields']['body']['element_type'] = '0';
	$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
	/* Field: Title and Body */
	$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
	$handler->display->display_options['fields']['nothing']['table'] = 'views';
	$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
	$handler->display->display_options['fields']['nothing']['ui_name'] = 'Title and Body';
	$handler->display->display_options['fields']['nothing']['label'] = '';
	$handler->display->display_options['fields']['nothing']['alter']['text'] = '<h4 class="title>[title]</h4>
		    <div class="content">[body]</div>';
	$handler->display->display_options['fields']['nothing']['element_type'] = '0';
	$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'column medium-8';
	$handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;

    $views[$view->name] = $view;
    
	return $views;
}

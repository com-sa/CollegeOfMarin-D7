<?php
function install_preprocess_maintenance_page(&$vars) {
	$vars['classes_array'] = array_values( preg_grep("/maintenance/i", $vars['classes_array'], PREG_GREP_INVERT) );	
}
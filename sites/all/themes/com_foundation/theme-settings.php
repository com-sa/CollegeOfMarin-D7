<?php
/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function com_foundation_form_system_theme_settings_alter(&$form, &$form_state) {
	$form['favicon']['default_favicon']['#default_value'] = 0;
	hide( $form['favicon'] );
}
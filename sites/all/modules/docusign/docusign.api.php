<?php

/**
 * Hooks for Docusign Module.
 */

 /**
 * Act on a DocuSign Event.  This hook is invoked after an event,
 * before saving to database.
 *
 * @param array $envelope
 *   The drupal DocuSign Envelope database entry, with status
 *   updated based on the event just processed.
 * @param string $event
 *   The event string.
 * @param string $old_status
 *   The Original Status String
 */
function hook_docusign_process_event(&$envelope, $event, $old_status) {

  if ($envelope['status'] == 'Incomplete' && $event == 'OnDecline') {
    // Do something.
  }
}


/**
 * Describe document info. Each document should contain:
 *  -name     The Human Readable Name of the Document
 *  -file     The local path of the file (default, can be overriden)
 *  -tabs     an array of tabs on the document
 *    -tab      an array with the following keys
 *      -name   The name of the tab
 *      -page   The page on the document
 *      -xpos   The X Coordinate of the upper left hand corner of the tab
 *      -ypos   The Y Coordinate of the upper left hand corner of the tab
 *      -type   DocuSign tab type
 *      -role   The role of the signer
 *  -roles    an array of key value, role name => role label
 *
 *  @see docusign_envelope_build().
 *
 */
function hook_docusign_document_info() {

  $documents = array();
  $documents['my_document_machine_name'] = array(
    'name' => 'My Document',
    'file' => drupal_get_path('module', 'mymodule') . '/pdf/MyDocument.pdf',
    'tabs' => array(
      array('name' => 'Applicant Signature', 'page' => 1, 'xpos' => 200, 'ypos' => 400, 'type' => 'SignHere', 'role' => 'signer1',),
      array('name' => 'Applicant 2 Signature', 'page' => 4, 'xpos' => 325, 'ypos' => 653, 'type' => 'SignHere', 'role' => 'signer2',),
      array('name' => 'Applicant 2 Signature', 'page' => 4, 'xpos' => 325, 'ypos' => 653, 'type' => 'SignHere', 'role' => 'docusign ',),
    ),
    'roles' => array(
      'signer1' => t('First User'),
      'signer2' => t('Second User'),
      'docusign' => t('Agent'),
    ),
  );

  return $documents;
}

/**
 * An example function to illustrate how to send a DocuSign Envelope
 * and embed a signing window.
 *
 * You must have previously created documents in
 * hook_docusign_document_info
 *
 *
 * @param StdClass $user
 *   A Drupal User
 * @param string $document
 *   A document identifier
 */
function mymodule_docusign_callback($user, $document) {
  $roles = array();
  $documents = array();
  $files = array();

  $roles['signer1'] = array('name' => "My Signer's Legal Name", 'user' => $user->uid);
  $roles['docusign'] = array();

  // Document key declared via hook_docusign_document_info().
  $documents[] = 'my_document_machine_name';

  // Override default file, or not, $files parameter is optional
  $files['my_document_machine_name'] = mymodule_create_pdf($document, $user);

  // Build the envelope, returns a DocuSignEnvelope Class
  $envelope = docusign_envelope_build("Title", "Instructions: Sign Here", $documents, $roles, $files);

  // Send the envelope.  The default method returns a token URL.
  $token_url = $envelope->sendEnvelope();

  // We want to embed this token using the docusign_iframe_item theme
  $iframe = array();
  $iframe['#src'] = $token_url;
  $iframe['#success_url'] = url("url/to/redirect/after/success", array('absolute' => TRUE));
  $iframe['#failure_url'] = url("url/to/redirect/after/failure", array('absolute' => TRUE));

  return array(
    '#theme' => 'docusign_iframe_item',
    '#element' => $iframe,
  );
}

<?php


/**
 * Docusign User List Page Callback
 * 
 * @param StdClass $user
 *   A Drupal User
 */
function docusign_view_list($user) {
  
  $rows = array();
  $header = array('Envelope ID', 'Status', 'Action Links');
  
  if ($envelopes = docusign_envelope_load_by_user($user->uid)) {
    foreach ($envelopes as $hash => $env) {
      $row = array();
      $row[] = $env['envelope_id'];
      $row[] = $env['status'];
      
      $links['view'] = array(
        'title' => 'View',
        'href' => url('docusign/' . $env['envelope_id'], array('absolute' => TRUE, 'query' => array('destination' => current_path()))),
        'html' => TRUE,
        'attributes' => array('class' => array('docusign-view'),),
      );
      $links['pdf'] = array(
        'title' => 'Print PDF',
        'href' => url('docusign/' . $env['envelope_id'] . '/download', array('absolute' => TRUE)),
        'html' => TRUE,
        'attributes' => array('class' => array('docusign-download'), 'target' => '_blank'),
      );      
      
      $row[] = theme('links', array('links' => $links, 'attributes' => array('class' => array('links', 'inline', 'operations'))));
      $rows[] = $row;      
    }

    $return = array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,   
    );    
  }
  else {
    $return = array(
      '#markup' => '<div>' . t('No Signed Documents') . '</div><div>' . l('Go back to user page', 'user') . '</div>',
    );
  }
   
  return $return;
}


/**
 * Return a single contiguous PDF file associated with the Envelope ID
 * 
 * @param string $envelope_id
 *   The envelope ID
 */
function docusign_pdf_download($envelope_id) {
  
  $bytes = docusign_request_envelope_pdf($envelope_id);
  $bytestream = $bytes->PDFBytes;
  
  header("Content-Type: application/pdf");
  header('Content-Disposition: inline; filename="' . $envelope_id . '.pdf"');
  header('Content-Length: ' . strlen($bytestream));  
  echo $bytestream;

  // Invoke Drupal Shutdown.
  module_invoke_all('exit');
  exit;
}

/**
 * DocuSign Page View Callback
 * 
 * @param string $envelope_id
 *   The envelope ID
 * @param string $action
 *   The action to be performed, currently "view"
 */
function docusign_view_page($envelope_id, $action = 'view') {
  
  $destination = drupal_get_destination();
  
  if ($destination['destination'] == current_path()) {
    $destination['destination'] = 'user';
  }

  // Known Envelope
  if ($token = docusign_envelope_get_token($envelope_id)) {
    $element['#src'] = $token;
    $element['#success_url'] = url($destination['destination'], array('absolute' => TRUE));
    $element['#failure_url'] = url($destination['destination'], array('absolute' => TRUE));
  }
  else {
    // Unknown Envelope
    // @TODO: make this get status and display, then save to db
    return array('#markup' => 'not finding this in db at the moment');
  }

  return theme('docusign_iframe_item', array('element' => $element));
}


/**
 * @param string $envelope_id
 *   An Envelope ID
 * @param string $event
 *   The Callback Event from DocuSign
 */
function docusign_event_page($envelope_id, $event) {

  if ($envelope = docusign_envelope_load($envelope_id)) {
    if (docusign_process_event($envelope, $event)) {
      $message = t('Thank you for Signing!');
      $status = 'success';
      drupal_add_js('jQuery(document).ready(function () { parent.Drupal.docusign.frame_dismiss("' . $status . '"); });', 'inline');
    }
    else {
      watchdog('docusign', 'Failed event for Docusign. Status: !event for User ID: !uid', array('!event' => $event, '!user' => $envelope['uid']));
      $status = 'failure';
      $message = t('You can follow the link in your email to complete the signing Process. Thank you!');
      drupal_add_js('jQuery(document).ready(function () { parent.Drupal.docusign.frame_dismiss("' . $status . '"); });', 'inline');
    }
  }
  else {
    return docusign_close_iframe();
  }

  return array('#markup' => 'Goodbye!');
}

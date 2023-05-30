<?php

/*
 * @file Docusign Admin File
 */

/**
 * Admin settings callback form.
 */
function docusign_admin_settings() {

  $form = array();
  
  $form['docusign_debug'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('docusign_debug', TRUE),
    '#description' => t('When ticked, all DocuSign requests go through the Demo Servers.'),
    '#title' => t('Use DocuSign Demo Servers'),
  );
  $form['docusign_integrator_key'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('docusign_integrator_key', ''),
    '#description' => t('Manage Integration keys on the !url', array('!url' => l('Docusign Demo Site', 'https://demo.docusign.net', array('absolute' => TRUE)))),
    '#title' => t('API Integrator\'s Key'),
    '#required' => TRUE,
  );
  
  $form['docusign_email'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('docusign_email', ''),
    '#title' => t('Email Address of the DocuSign User'),
    '#required' => TRUE,
  );  
  $form['docusign_user_legalname'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('docusign_user_legalname', ''),
    '#title' => t('The Legal Name of the User'),
    '#description' => t('This must match the Full Name of the user on Docusign'),        
    '#required' => TRUE,
  );
  
  
  $form['docusign_user_id'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('docusign_user_id', ''),
    '#title' => t('API UserName'),
    '#required' => TRUE,
  );
  $form['docusign_password'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('docusign_password', ''),
    '#title' => t('API Password'),
    '#required' => TRUE,
  );
  $form['docusign_account_id'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('docusign_account_id', ''),
    '#title' => t('API Account ID'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}


function docusign_folder_list() {

  $folders = docusign_folders_load();

  $header = array('Folder Name', 'Owner');
  $rows = array();

  foreach($folders as $folder) {

    $link = 'admin/config/services/docusign/folders/' . $folder['folder_type'] . ":" . $folder['folder_name'];

    $rows[] = array(
      l($folder['folder_name'], $link),
      '<p>' . $folder['username'] . '</p>',
    );
  }

  return array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );
}


function docusign_folder_list_items($folder) {

  drupal_set_title(t("Docusign Folder") . ': ' . $folder->FolderTypeInfo->FolderName);

  $header = array('Owner', 'Created', 'Sent', 'Subject', 'Completed', 'Recipients Status');
  $rows = array();

  $items = array();
  if ($folder->ResultSetSize == 0) {

  }
  elseif ($folder->ResultSetSize == 1) {
    $items = array($folder->FolderItems->FolderItem);
  }
  elseif ($folder->ResultSetSize > 1) {
    $items = $folder->FolderItems->FolderItem;
  }


  foreach($items as $fi) {

    $status_rows = array();
    $status_header = array('Type', 'Person', 'Status');
    foreach($fi->RecipientStatuses as $rs) {
      if (!is_array($rs)) {
        $rs = array($rs);
      }
      foreach($rs as $r) {
        $status_rows[] = array(
          $r->Type,
          $r->UserName,
          $r->Status,
        );
      }
    }
    $status = theme('table', array('header' => $status_header, 'rows' => $status_rows));

    $rows[] = array(
      array('data' => $fi->Owner),
      array('data' => date('m/d/Y', strtotime($fi->Created))),
      date('m/d/Y', strtotime($fi->Sent)),
      $fi->Subject,
      (isset($fi->Completed) ? date('m/d/Y', strtotime($fi->Completed)) : "Not Completed"),
      $status,
    );
  }

  return array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );
}


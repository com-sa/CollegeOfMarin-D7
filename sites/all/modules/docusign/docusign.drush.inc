<?php

/**
 * @file
 *   drush file for Downloading SOAP security libraries.
 */

/**
 * The docusign required files.
 *
 */
define('DOCUSIGN_XMLSECLIBS', 'https://wse-php.googlecode.com/hg-history/ba4a146e1bbe5bf1ca5e51218938f4aaaf9d0eb3/xmlseclibs.php');
define('DOCUSIGN_SOAP_WSSE', 'https://wse-php.googlecode.com/hg-history/ba4a146e1bbe5bf1ca5e51218938f4aaaf9d0eb3/soap-wsse.php');
define('DOCUSIGN_SOAP_WSA', 'https://wse-php.googlecode.com/hg-history/ba4a146e1bbe5bf1ca5e51218938f4aaaf9d0eb3/soap-wsa.php');
define('DOCUSIGN_SOAP_WSSE_NOCRYPT', 'https://raw.github.com/docusign/DocuSign-eSignature-SDK/master/PHP/DocuSignSample/api/WSSESoap.php');

/**
 * Implements hook_drush_command().
 */
function docusign_drush_command() {
  $items = array();

  $items['docusign-dl'] = array(
    'callback' => 'drush_docusign_downloader',
    'description' => dt("Download Docusign required libraries"),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function docusign_drush_help($section) {
  switch ($section) {
    case 'drush:docusign-dl':
      return dt("Downloads Required PHP Libraries for using the DocuSign service.");
  }
}


/**
 * Command to download the docusign plugin.
 */
function drush_docusign_downloader() {
  
  $path = 'sites/all/libraries';  

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  $olddir = getcwd();

  // Docusign path
  $path .= '/docusign';

  // Create the path if it does not exist.
  if (!is_dir(realpath($path))) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  chdir($path);

  $files = array(
    DOCUSIGN_XMLSECLIBS,
    DOCUSIGN_SOAP_WSSE,
    DOCUSIGN_SOAP_WSA,
    DOCUSIGN_SOAP_WSSE_NOCRYPT,
  );

  foreach($files as $file) {

    // Delete old version if it exists.
    if (is_file(basename($file))) {
      drush_op('unlink', basename($file));
    }

    drush_log(dt('Downloading File: @file', array('@file' => $file)), 'ok');
    if (!drush_shell_exec("wget " . $file)) {
      drush_shell_exec('curl ' . $file);
    }
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}

<?php

class DocuSignCredentialSOAPEndpoint extends WSClientSOAPEndpoint {

  /**
   * Client Initializer
   *
   * Overriden
   *
   * @see WSClientSOAPEndpoint::client()
   */
  public function client() {
    $options['exceptions'] = TRUE;
    if (!isset($this->client)) {
      if (!empty($this->service->settings['options'])) {
        $options += $this->service->settings['options'];
      }
      $this->client = new SoapClient($this->url, $options);
    }
    return $this->client;
  }

  /**
   * Calls the SOAP service.
   *
   * @param string $operation
   *   The name of the operation to execute.
   * @param array $arguments
   *   Arguments to pass to the service with this operation.
   */
  public function call($operation, $arguments) {

    $client = $this->client();

    try {
      return $client->__soapCall($operation, $arguments['parameters']);
    }
    catch (SoapFault $e) {
      watchdog('docusign', "There was an error invoking this DocuSign Credential Service.  Message: !message", array('!message' => $e->getMessage()));
      if (module_exists('rules')) {
        rules_invoke_event_by_args('docusign_invocation_error', array('user' => $GLOBALS['user'], 'time' => REQUEST_TIME));
      }
      drupal_set_message("There was an error invoking this DocuSign Credential Service.");
      return FALSE;
    }
  }
}

/**
 * A remote endpoint type for invoking DocuSign SOAP services.
 */
class DocuSignSOAPEndpoint extends WSClientSOAPEndpoint {

  public function client() {
    $options['exceptions'] = TRUE;
    if (!isset($this->client)) {
      if (!empty($this->service->settings['options'])) {
        $options += $this->service->settings['options'];
      }
      $this->client = new DocuSoapClient($this->url, $options);
    }
    return $this->client;
  }

  /**
   * Calls the SOAP service.
   *
   * @param string $operation
   *   The name of the operation to execute.
   * @param array $arguments
   *   Arguments to pass to the service with this operation.
   */
  public function call($operation, $arguments) {

    $client = $this->client();

    try {
      if(!function_exists('mcrypt_module_get_algo_key_size')){
        docusign_load_library('WSSESoap.php');
      }
      else {
        docusign_load_library('soap-wsse.php');        
      }      
      
      docusign_load_library('soap-wsa.php');
      return $client->__soapCall($operation, $arguments);
    }
    catch (SoapFault $e) {
      watchdog('docusign', "There was an error invoking this DocuSign Service.  Message: !message", array('!message' => $e->getMessage()));
      if (module_exists('rules')) {
        rules_invoke_event_by_args('docusign_invocation_error', array('user' => $GLOBALS['user'], 'time' => REQUEST_TIME));
      }
      drupal_set_message("There was an error using a web service.  Site Administrators are working to fix this. Please try again later.");
      return FALSE;
    }
  }
}


class DocuSoapClient extends SoapClient {

  private $_username;
  private $_password;

  function __doRequest($request, $location, $saction, $version, $one_way = null) {

    $this->_username = "[" . variable_get('docusign_integrator_key', '') . "]" . variable_get('docusign_user_id', '');
    $this->_password = variable_get('docusign_password', '');


    $dom = new DOMDocument('1.0');
    $dom->loadXML($request);
    $objWSA = new WSASoap($dom);
    $objWSA->addAction($saction);
    $objWSA->addTo($location);
    $objWSA->addMessageID();
    $objWSA->addReplyTo();

    $dom = $objWSA->getDoc();

    $objWSSE = new WSSESoap($dom);

    if (isset($this->_username) && isset($this->_password)) {
      if(!function_exists('mcrypt_module_get_algo_key_size')){
        $objWSSE->addUserTokenNoMCrypt($this->_username,$this->_password);
      } else {
        $objWSSE->addUserToken($this->_username, $this->_password);
      }
    }

    /* Sign all headers to include signing the WS-Addressing headers */
    $objWSSE->signAllHeaders = TRUE;

    $objWSSE->addTimestamp(300);
    // if you need to do binary certificate signing you can uncomment this (and provide the path to the cert)
    /* create new XMLSec Key using RSA SHA-1 and type is private key */
    // $objKey = new XMLSecurityKey(XMLSecurityKey::RSA_SHA1, array('type'=>'private'));

    /* load the private key from file - last arg is bool if key in file (TRUE) or is string (FALSE) */

    /* Sign the message - also signs appropraite WS-Security items */
    // $objWSSE->signSoapDoc($objKey);

    /* Add certificate (BinarySecurityToken) to the message and attach pointer to Signature */
    // $token = $objWSSE->addBinaryToken(file_get_contents(CERT_FILE));
    // $objWSSE->attachTokentoSig($token);

    $request = $objWSSE->saveXML();
    $this->_lastRequest = $request;

    return parent::__doRequest($request, $location, $saction, $version);
  }
}

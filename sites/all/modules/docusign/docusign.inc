<?php

/*
 * @file DocuSign Class For Building Envelopes
 */

/*
 * A Class to Manage DocuSign Envelopes
 *
 */
class DocuSignEnvelope {

  /*
   * The Envelope ID
   */
  public $EnvelopeID;

  /*
   * Account ID, issued by DocuSign.
   */
  private $AccountId;

  /*
   * The subject of this envenlope.
   */
  public $Subject;

  /*
   * A message to include with the envelope.
   */
  public $EmailBlurb;

  /*
   * Where the Document is Signed
   * 'Online' or, 'InPerson'
   */
  public $SigningLocation = 'Online';

  //     'TransactionID', // For us when we start tracking envelopes
  //     'Asynchronous', // Add to a queue rather than process immediately
  //     'CustomFields', // ArrayOfCustomField
  //     'VaultingOptions', // VaultingOptions
  //     'AutoNavigation', // boolean
  //     'EnvelopeIdStamping', // boolean
  //     'AuthoritativeCopy', // boolean
  //     'Notification', // Notification
  //     'EnvelopeAttachment', // ArrayOfAttachment
  //     'EnforceSignerVisibility', // boolean
  //     'EnableWetSign', // boolean
  //     'AllowMarkup', // boolean
  //     'EventNotification', // EventNotification


  /*
   * An array of Documents to be included in the Envelope.
   */
  public $Documents = array();

  /*
   * An array of Receipients to be included on the Envelope.
   */
  public $Recipients= array();

  /**
   * Contructor
   *
   * @param string $subject
   *   The Subject of the Envelope.
   * @param string $email_blurb
   *   The message blurb to be included on the envelope.
   */
  public function __construct($subject = '', $email_blurb = '') {
    $this->AccountId = variable_get('docusign_account_id');
    $this->EmailBlurb = $email_blurb;
    $this->Subject = $subject;
  }


  /**
   * Add a Dcoument to the Envelope
   *
   * @param string $name
   *   The Name of the Document to be added
   * @param string $file
   *   The file name.  Care to pass a realpath.
   */
  public function addDocument($name, $file) {
    $document_id = count($this->Documents) + 1;
    $doc = new DocuSignDocument($document_id, $name);
    $doc->addFile($file);
    $this->Documents[$document_id] = $doc;
    return $this->getDocument($document_id);
  }

  /**
   * @param $document_id
   * @return DocuSignDocument
   */
  public function &getDocument($document_id) {
    return $this->Documents[$document_id];
  }

  /**
   * Add a Recipient to a Document.
   *
   * @param string $email
   *   The email address of the recipient
   * @param string $full_name
   *   The Full Name of the Recipient
   */
  public function addRecipient($email, $full_name, $signer_identifier) {
    $recipient_id = count($this->Recipients) + 1;
    $this->Recipients[$recipient_id] = new DocuSignRecipient($recipient_id, $full_name, $email, $signer_identifier);
    $this->Recipients[$recipient_id]->RoutingOrder = $recipient_id;
    return $this->getRecipient($recipient_id);
  }

  /**
   * Add a Recipient to a Document.
   *
   * @param string $email
   *   The email address of the recipient
   * @param string $full_name
   *   The Full Name of the Recipient
   */
  public function addDocusignAccountHolder() {
    $recipient_id = count($this->Recipients) + 1;
    $this->Recipients[$recipient_id] = new DocuSignRecipient($recipient_id, variable_get('docusign_account_holder_name', ''), variable_get('docusign_account_holder_email', ''), NULL);
    return $this->getRecipient($recipient_id);
  }


  public function addDrupalRecipient($user, $full_name) {
    $recipient_id = count($this->Recipients) + 1;
    $this->Recipients[$recipient_id] = new DocuSignRecipient($recipient_id, $full_name, $user->mail, $user->uid);
    return $this->getRecipient($recipient_id);
  }

  public function &getRecipient($recipient_id) {
    return $this->Recipients[$recipient_id];
  }

  public function getByUserID($user_id) {
    foreach ($this->Recipients as $recipient) {
      if (isset($recipient->CaptiveInfo)) {
        if ($recipient->CaptiveInfo['ClientUserId'] == $user_id) {
          return $recipient->ID;
        }
      }
    }
  }

  public function getTokenURL($envelope) {

    $serv = wsclient_service_load('docusign_api');

    $recipientoken = array(
      'EnvelopeID' => $envelope['envelope_id'],
      'ClientUserID' => $envelope['uid'],
      'ClientURLs' => $this->receiptTokenURLs($envelope['envelope_id']),
      'AuthenticationAssertion' => $this->tokenAuthenticationAssertion(),
      'Username' => $envelope['username'],
      'Email' => $envelope['email'],
    );

    $token = $serv->RequestRecipientToken($recipientoken);

    return $token->RequestRecipientTokenResult;
  }

  public function sendEnvelope($get_token = TRUE) {

    $envelope = array_filter(get_object_vars($this), 'is_scalar');
    $uid = FALSE;

    // Get Recipients
    foreach($this->Recipients as $recipient) {
      $envelope['Recipients'][] = $recipient->toArray();

      if (!$uid) {
        $uid = $recipient->getDrupalID();
      }
    }

    // Get Documents and Tabs
    $envelope['Tabs'] = array();
    foreach($this->Documents as $document) {
      $envelope['Documents'][] = $document->toArray();
      $envelope['Tabs'] = array_merge($envelope['Tabs'], $document->tabsToArray());
    }

    if ($service = wsclient_service_load('docusign_api')) {
      try {
        $result = $service->CreateAndSendEnvelope(array('Envelope' => $envelope));

      } catch (Exception $e) {
       watchdog('docusign', $e->getMessage());
       return FALSE;
      }

      // Set the Envelope ID
      $this->EnvelopeID = $result->CreateAndSendEnvelopeResult->EnvelopeID;

      foreach ($result->CreateAndSendEnvelopeResult->RecipientStatuses as $rs) {
        if (!is_array($rs)) {
          $rs = array($rs);
        }

        // If there is more than one recipient, prefer the ClientUserID of our
        // signed in user
        foreach ($rs as $r) {
          global $user;
          if (isset($r->ClientUserId) && (is_numeric($r->ClientUserId)) && ($user->uid == $r->ClientUserId || user_access('administer docusign') || $user->uid == 1)) {
            $recipient = $r;
          }
        }
      }

      if (isset($recipient) && $this->EnvelopeID && !empty($recipient->ClientUserId)) {
        $envelope_record = array(
          'envelope_id' => $result->CreateAndSendEnvelopeResult->EnvelopeID,
          'uid' => $uid,
          'status' => $recipient->Status,
          'decline_reason' => NULL,
          'username' => $recipient->UserName,
          'email' => $recipient->Email,
        );

        docusign_envelope_insert($envelope_record);

        if ($get_token) {
          return $this->getTokenURL($envelope_record);
        }

        return $this;
      }
      else {
        return FALSE;
      }
    }
  }

  private function receiptTokenURLs($identifier) {

    $receipt_urls = array();

    foreach($this::eventTypes() as $event) {
      $receipt_urls[$event] = url('docusign/event/' . $identifier . '/' . $event, array('absolute' => TRUE,));
    }

    // $urls['GenerateSignedDocumentAsynch'] = TRUE; // boolean
    return $receipt_urls;
  }

  private function tokenAuthenticationAssertion() {
    return array(
      'AssertionID' => _docusign_guid(),
      'AuthenticationInstant' => _docusign_xsd_date(),
      'AuthenticationMethod' => 'Password',
      'SecurityDomain' => 'DrupalDocuSign',
    );
  }

  public static function eventTypes() {
    return array(
      'OnSigningComplete',
      'OnViewingComplete',
      'OnCancel',
      'OnDecline',
      'OnSessionTimeout',
      'OnTTLExpired',
      'OnException',
      'OnAccessCodeFailed',
      'OnIdCheckFailed',
      'OnFaxPending',
    );
  }

  public static function envelopeStatuses() {
    return array(
      'Voided',
      'Created',
      'Deleted',
      'Sent',
      'Delivered',
      'Signed',
      'Completed',
      'Declined',
      'TimedOut',
    );
  }

  public static function authenticationMethods() {
    return array(
      'Password', // 'Password';
      'Email', // 'Email';
      'PaperDocuments', // 'PaperDocuments';
      'HTTPBasicAuth', // 'HTTPBasicAuth';
      'SSLMutualAuth', // 'SSLMutualAuth';
      'X509Certificate', // 'X509Certificate';
      'Kerberos', // 'Kerberos';
      'SingleSignOn_CASiteminder', // 'SingleSignOn_CASiteminder';
      'SingleSignOn_InfoCard', // 'SingleSignOn_InfoCard';
      'SingleSignOn_MicrosoftActiveDirectory', // 'SingleSignOn_MicrosoftActiveDirectory';
      'SingleSignOn_Passport', // 'SingleSignOn_Passport';
      'SingleSignOn_SAML', // 'SingleSignOn_SAML';
      'SingleSignOn_Other', // 'SingleSignOn_Other';
      'Smartcard', // 'Smartcard';
      'RSASecureID', // 'RSASecureID';
      'Biometric', // 'Biometric';
      'None', // 'None';
      'KnowledgeBasedAuth', // 'KnowledgeBasedAuth';
    );
  }

}

class DocuSignRecipient {


  public $ID;

  /**
   * Full Legal Name of the Recipient
   *
   * @var string
   */
  public $UserName;

  /**
   * Email Address
   *
   * @var string
   */
  public $Email;

  /**
   * Type of Recipient
   *
   * @var string Type
   */
  public $Type = 'Signer';

  public $CaptiveInfo = array();

  public $RoutingOrder = 1;

  private $uid;

  //    'SignerName',  // string
  //    'AccessCode',  // string
  //    'AddAccessCodeToEmail',  // boolean
  //    'RequireIDLookup',  // boolean
  //    'IDCheckConfigurationName',  // string
  //    'PhoneAuthentication',  // RecipientPhoneAuthentication
  //    'SignatureInfo',  // RecipientSignatureInfo
  //    'CustomFields',  // ArrayOfString1

  //    'IDCheckInformationInput',  // IDCheckInformationInput
  //    'AutoNavigation',  // boolean
  //    'RecipientAttachment',  // ArrayOfAttachment
  //    'Note',  // string
  //    'RoleName',  // string
  //    'TemplateLocked',  // boolean
  //    'TemplateRequired',  // boolean
  //    'TemplateAccessCodeRequired',  // boolean
  //    'DefaultRecipient',  // boolean

  public $machine_name = '';

  public static function recipientTypes() {
    return array(
      'Signer',
      'Agent',
      'Editor',
      'CarbonCopy',
      'CertifiedDelivery',
      'InPersonSigner',
    );
  }

  public function __construct($recipient_id, $name, $email, $signer_identifier) {
    $this->ID = $recipient_id;
    if (is_null($signer_identifier)) {
      $this->CaptiveInfo = NULL;
      $this->UserName = variable_get('docusign_user_legalname');
      $this->Email = variable_get('docusign_email');
      $this->uid = $GLOBALS['user']->uid;
    }
    else {
      $this->UserName = $name;
      $this->Email = $email;
      $this->CaptiveInfo['ClientUserId'] = $signer_identifier;
      $this->uid = $signer_identifier;
    }
  }

  public function getID() {
    return $this->ID;
  }

  public function getDrupalID() {
    return $this->uid;
  }

  public function toArray() {
    $vars = get_object_vars($this);
    unset($vars['machine_name']);
    unset($vars['uid']);
    return array_filter($vars);
  }
}

class DocuSignDocument {

  /**
   * ID of the Document
   *
   * @var int
   */
  public $ID;

  /**
   * Document Byte Stream
   *
   * @var binary
   */
  private $PDFBytes;

  /**
   * File Extension
   *
   * @var string
   */
  private $FileExtension;

  /**
   * Name for the Document
   *
   * @var string
   */
  public $Name;

  /**
   * Array of Tabs
   *
   * @var array DocuSignTab
   */
  private $tabs = array();

  //  'Password', // string
  //  'TransformPdfFields', // boolean
  //  'MatchBoxes', // ArrayOfMatchBox
  //  'AttachmentDescription', // string


  public $machine_name = '';

  /**
   * Constructor
   *
   * @param int $document_id
   */
  public function __construct($document_id, $name = '') {
    $this->ID = $document_id;
    $this->Name = $name;
  }

  /**
   * Load the PDF file for upload.
   *
   * @param string $file
   */
  public function addFile($file) {
    if (!file_exists($file)) {
      return FALSE;
    }

    $this->PDFBytes = file_get_contents($file);
    $pathinfo = pathinfo($file);
    $this->FileExtension = $pathinfo['extension'];

    return $this;
  }

  /**
   * Add a Tab to a Document
   *
   * @param DocuSignRecipient $recipient
   *   The Recipient ID of the previously added Recipient.  If the integer
   *   passed does not correspond to a Document ID, FALSE is returned
   * @param int $page
   *   The integer of the Page Number.  First page is 1.
   * @param int $xpos
   *   The X Coordinate of the bottom left corner of Sign Line.  Remeber that
   *   PDF coordinates originate from lower left corner of the Document.
   * @param int $ypos
   *   The Y Coordinate of the bottom left corner of Sign Line.  Remeber that
   *   PDF coordinates originate from lower left corner of the Document.
   */
  public function addTab($recipient, $page, $xpos, $ypos) {

    $tab_id = count($this->tabs) + 1;
    $this->tabs[$tab_id] = new DocuSignTab($this->ID, $recipient);
    $this->tabs[$tab_id]->PageNumber = $page;
    $this->tabs[$tab_id]->XPosition = $xpos;
    $this->tabs[$tab_id]->YPosition = $ypos;
    return $this->getTab($tab_id);
  }

  public function &getTab($tab_id) {
    return $this->tabs[$tab_id];
  }

  public function toArray() {
    $vars = get_object_vars($this);
    unset($vars['tabs']);
    unset($vars['machine_name']);
    return $vars;
  }

  public function tabsToArray() {
    $tabs = array();

    foreach($this->tabs as $tab) {
      $tabs[] = $tab->toArray();
    }
    return $tabs;
  }

}

/**
 * Class Definition for a DocuSign Document Tab
 */
class DocuSignTab {

  /**
   * Document ID
   * Must be greater than 0
   *
   * @var int
   */
  private $DocumentID;

  /**
   * Recipeint ID
   * Must be greater than 0
   *
   * @var int
   */
  private $RecipientID;

  /**
   * The page of the tab
   *
   * @var int
   */
  public $PageNumber;

  /**
   * X Coordinate of the Tab
   *
   * @var int
   */
  public $XPosition;

  /**
   * Y Coordinate of the Tab
   *
   * @var unknown_type
   */
  public $YPosition;

  /**
   * Tab Type
   *
   * @var unknown_type
   */
  public $Type = 'SignHere';

  //    'ScaleValue',  // decimal
  //    'AnchorTabItem',  // AnchorTab
  //    'Name',  // string
  //    'TabLabel',  // string
  //    'Value',  // string
  //    'CustomTabType',  // CustomTabType
  //    'CustomTabWidth',  // int
  //    'CustomTabHeight',  // int
  //    'CustomTabRequired',  // boolean
  //    'CustomTabLocked',  // boolean
  //    'CustomTabDisableAutoSize',  // boolean
  //    'CustomTabListItems',  // string
  //    'CustomTabListValues',  // string
  //    'CustomTabListSelectedValue',  // string
  //    'CustomTabRadioGroupName',  // string
  //    'CustomTabValidationPattern',  // string
  //    'CustomTabValidationMessage',  // string
  //    'TemplateLocked',  // boolean
  //    'TemplateRequired',  // boolean
  //    'ConditionalParentLabel',  // string
  //    'ConditionalParentValue',  // string
  //    'SharedTab',  // boolean
  //    'RequireInitialOnSharedTabChange',  // boolean
  //    'ConcealValueOnDocument',  // boolean

  /**
   * Constructor
   *
   * @param int $document_id
   * @param DocuSignRecipient $recipient
   */
  public function __construct($document_id, $recipient) {
    $this->DocumentID = $document_id;
    $this->RecipientID = is_object($recipient) ? $recipient->getID() : $recipient;
  }

  /**
   * Available tab types
   */
  public static function tabTypes() {
    return array(
      'InitialHere',
      'SignHere',
      'FullName',
      'Company',
      'Title',
      'DateSigned',
      'InitialHereOptional',
      'EnvelopeID',
      'Custom',
      'SignerAttachment',
      'SignHereOptional',
    );
  }

  /**
   * Return this tab as an array
   */
  public function toArray() {
    return array_filter(get_object_vars($this));
  }
}


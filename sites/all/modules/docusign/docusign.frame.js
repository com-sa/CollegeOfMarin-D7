(function($) {
  Drupal.docusign = {};
  Drupal.docusign.frame_dismiss = function(status, url) {
    switch (status) {
      case 'close':
        $('iframe[name="' + Drupal.settings.docusign.elementName + '"]')
          .remove();
        break;
      case 'success':
        $('iframe[name="' + Drupal.settings.docusign.elementName + '"]')
          .remove();
        window.location = Drupal.settings.docusign.onSuccess;
        break;
      default:
        $('iframe[name="' + Drupal.settings.docusign.elementName + '"]')
          .remove();
        window.location = Drupal.settings.docusign.onFailure;
        break;
    }    
  };
})(jQuery);

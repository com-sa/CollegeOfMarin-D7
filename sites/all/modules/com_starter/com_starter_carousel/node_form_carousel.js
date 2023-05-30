(function($) {
	var $fieldset = $(".node-form #edit-field-carousel-image-und");
	$fieldset.children("legend").on("click", function() {
		$fieldset.toggleClass("active");
	});
})(jQuery);
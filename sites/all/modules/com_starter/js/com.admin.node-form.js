(function($) {

	var link = document.createElement("a"), getVideoId = function(link) { return link.search ? link.search.substring(1).split("&").reduce(function(el) { return el.substring(0,1) === "v" ? el.split("=")[1] : false; }) : link.pathname.substring(1); };	

	$(document).on("keyup", function(evt) {
		var currentModal = CKEDITOR.dialog.getCurrent();
		if ( currentModal ) {
			var title = currentModal.parts.dialog.$.querySelector(".cke_dialog_title"), iframe = currentModal.hasOwnProperty("iframeNode");
			if ( evt.target.matches(".cke_dialog_ui_input_text") && title.innerHTML === "IFrame Properties") {
				link.href = evt.target.value;
				if ( ["youtu.be", "www.youtube.com"].indexOf( link.host ) > -1 && link.pathname.indexOf("embed") === -1 ) { evt.target.value = "https://www.youtube.com/embed/" + getVideoId(link); }
			}
		}
	});
})(jQuery);
/*
	https://www.youtube.com/watch?v=5ZlOn9V_MmE&feature=youtu.be
	https://youtu.be/5ZlOn9V_MmE
	https://www.youtube.com/embed/5ZlOn9V_MmE
*/
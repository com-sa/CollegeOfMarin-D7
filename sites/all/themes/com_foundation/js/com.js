//* smooth scroll *//
!function(t,n){var o=null,l={},e=function(t,n){for(var o in n)t[o]="object"==typeof n[o]?e(t[o],n[o]):n[o];return t},i={duration:500,callback:null},s=function(o){var l=null;return"number"==typeof o?l=o:"string"==typeof o?(o=n.querySelector(o),o&&(l=o.getBoundingClientRect().top+t.pageYOffset)):"string"==typeof o.className&&(l=o.getBoundingClientRect().top+t.pageYOffset),l};scroll=function(){var n=Date.now(),e=Math.ceil((n-o)/l.settings.duration*l.destination);e<l.destination?(t.scrollTo(t.scrollX,e),t.requestAnimationFrame(function(){scroll(l)})):(t.scrollTo(t.scrollX,l.destination),l.settings.callback&&l.settings.callback.call(l.elem),l={})},t.smoothScroll=function(t,n){l.destination=s(t),l.settings=i,l.destination&&(o=Date.now(),e(l.settings,n),l.elem=t,scroll())}}(window,this.document);
//* smooth scroll *//




/****
	header js
	hover and clicks
****/
(function(window, document, $) {

	var $nav = $("header nav"),
		$topNav = $("#top-nav"),
		$subNav = $("#sub-nav"),
		$body = $("body"),
		$navWrapper = $( "#nav-wrapper" );

	$topNav.on("mouseover", "a", function() {
		var $li = $(this).parent(),
			i = $li.parent().children().index( $li );

		$subNav.find("ul").eq(i).addClass("over");
	}).on("mouseout", "a", function() {
		$subNav.find(".over").removeClass("over");
	}).on("click", "a", function(evt) {
		if ( document.documentElement.clientWidth <= 1024 ) {
			evt.preventDefault();

			var $li = $(this).parent(),
				i = $li.parent().children().index( $li );

			$subNav.find("ul").eq(i).addClass("active");
			
			// stop window from opening link
			//return false;
		}
	}).on("mouseover", "ul", function() {
		$nav.addClass("over");
	});

	$nav.on("mouseout", function() {
		$nav.removeClass("over");
	});

	$subNav.on("mouseover", "ul", function() {
		var i = $(this).parent().children().index( this );
		$topNav.find("li").eq(i).addClass("over");
	}).on("mouseout", "ul", function() {
		$topNav.find("li.over").removeClass("over");
	});

	

	$(".hamburger-menu").on("click", function() {
		//var $this = $(this);

		$body.toggleClass("menu-slide-in");
		/*if ( $body.is(".menu-slide-in") ) {
			$(".hamburger-menu").filter(".in").removeClass("in").addClass("out");
			$body.removeClass("menu-slide-in");
			$navWrapper.filter(".active").removeClass("active");
		} else {
			if ( $this.hasClass("out") ) {
				$this.removeClass("out").addClass("in");
			} else {
				$this.addClass("in");
			}

			$navWrapper.addClass("active");
			$body.addClass("menu-slide-in");
		}*/
	});


	$("#touch-nav-back").on("click", function(evt) {
		evt.preventDefault();
		$(this).siblings(".active").removeClass("active");
	});


	$("#skip-to-content").add( "#maps-link" ).on("click", function(evt) {
		evt.preventDefault();
		smoothScroll( this.getAttribute("href"), { duration: 150 });
	});


	// close alert boxes
	$(".alert-box").on("click", ".close", function() { $(this).parent().fadeOut(); });
	
	
	
	
	var $header = $("header"),
		breakpoint = 1025,
		touchDevice = !!('ontouchstart' in window),
		scrollWatch = (function() {  
			if ( window.pageYOffset > (document.body.clientHeight / 6) ) {
				if ( !$header.hasClass("minimal") ) {
					$header.addClass("minimal")
				}
			} else {
				if ( $header.hasClass("minimal") ) {
					$header.removeClass("minimal")
				}
			}
		});
		
		
		
	if ( !touchDevice ) {
		
		$header.addClass("fixed").next().css("margin-top", $header.outerHeight() );
		
		if ( window.matchMedia) {
			var headerThreshold = window.matchMedia("(min-width: " + breakpoint + "px)");
			
			scrollWatchWindow = (function (mql) {
				if (mql.matches) {
					window.addEventListener("scroll", scrollWatch);
					$header.addClass("fixed").next().css("margin-top", $header.outerHeight() );
					scrollWatch();
				} else {
					$header.removeClass("minimal fixed").next().css("margin-top", "" );
					window.removeEventListener("scroll", scrollWatch);
				}
			});
			
			headerThreshold.addListener(scrollWatchWindow);
			scrollWatchWindow(headerThreshold);
			
		} else {
			window.addEventListener("scroll", scrollWatch);			
		}
	}

})(window, document, jQuery);


// default js
(function(window, document, $) {

	//init some vars
	var $window = $( window ),
		$document = $( document ),
		$body = $( document.getElementsByTagName("body") ),
		//$topbar = $('nav').filter('[data-topbar]'),
		$topbarButton = $(".toggle-topbar").children("a"),
		$subTray = $("#sub-tray"),
		navFixed = false;

	//init foundation
	$document.foundation();

	// init fastclick
	FastClick.attach(document.body);

	// ability to popup modal on page load
	$('.modal-on-load').foundation('reveal', 'open');


	$("#navigation .sub-nav").each(function() {
		var $this = $(this),
			$related = $this.find(".nav-related-links");

		$this.find(".links").on("mouseover", "a[data-related]", function() {

			$related.find('[data-related-link="' + $(this).attr("data-related") + '"]')
				    .addClass('active')
				    .siblings()
				    .removeClass('active');
		});
	});



	var $loader = $('<span>').addClass("loader").text("Loading...");

	/* events filtering */
	var onComplete = function(evt) {

		$(".view-events").find(".tab-controller").children("li").filter(function() {
			return this.getAttribute("data-trigger") == evt.data.choice;
		}).addClass("active").siblings().removeClass("active").find(".loader").remove();

		$( document ).off("ajaxComplete", onComplete);
	};
	$(document).on("click", ".view-events .tab-controller li:not(.active)", function() {
		var $this = $(this),
			choice = $this.data("trigger"),
			select = document.getElementById("edit-promote"),
			button = document.getElementById("edit-submit-events");

		$(this).append( $loader );
		
		$( document ).on("ajaxComplete", { choice: choice }, onComplete);

		select.value = choice;
		button.click();

		//$this.addClass("active").siblings().removeClass("active");
	});


	// ensure parent of .pull-up is at least that tall
	var fitPullUp = function() { $(".pull-up").each(function() { this.parentNode.style["min-height"] = $(this).outerHeight(true) + "px"; }); };

	if ( window.matchMedia ) {
		var mql = window.matchMedia("(min-width: 1025px)"),
			threshold = function handleOrientationChange(mql) {
				if (mql.matches) {
					fitPullUp();
				} else {
					$(".pull-up").each(function() { this.parentNode.style["min-height"] = ''; });
				}
			};
			
		mql.addListener(threshold);

		setTimeout( fitPullUp, 0);
	} else {
		setTimeout( fitPullUp, 0);
	}

	$("iframe.responsive").each(function() {

		var $this = $(this);

		setTimeout( function() {
			var $wrapper = $('<div />').addClass("responsive-video"),
				height = $this.outerHeight(),
				width = $this.outerWidth();

			$wrapper.css("padding-bottom", (( height/width ) * 100 ) + "%")
			$this.wrap( $wrapper );
		}, 3);
	});
	
	
	
	
	// illuminate obfuscated email addresses
	[].slice.apply( document.querySelectorAll("a[data-email]") ).forEach(function(emailLink) {
		var emailAddress = emailLink.getAttribute("href").replace("/", "@");
		emailLink.href = "mailto:" + emailAddress;
		emailLink.innerHTML = emailAddress;		
	});
	
	
})(window, document, jQuery);




// init carousel
(function(window, document, $) {
	$(function() {
		//Top of page carousel
		$("#featured .carousel").on("init", function(evt, slick) {
			slick.$slider.addClass("loaded")
		}).slick({
			autoplay: true,
			autoplaySpeed: 6000,
			speed: 600,
		});

		// Content sliders
		//$(".view.carousel").find(".view-content").slick({ slidesToShow : 3, infinite: false });
		var carouselSettings = Drupal.settings.COMCarousel;

		if ( carouselSettings ) {
			for (var key in carouselSettings) { 
				
				if (carouselSettings.hasOwnProperty(key)) {
					var $carousel = $("." + key).find(".view-content");
										
					if ( $carousel.children().length <= parseFloat(carouselSettings[key])) {
						$carousel.closest(".carousel").addClass("no-scroll");
					}

					var opts = {
						slidesToShow : carouselSettings[key],
						responsive: [{
					    	breakpoint: 475,
							settings: {
						        slidesToShow: 1,
						        //slidesToScroll: 1,
						        //infinite: true,
						        rows: carouselSettings[key] > 4 ? 2 : 1
							}
					    }]
					};
					if ( carouselSettings[key] > 4 ) {
						opts.rows = 2;
						opts.slidesToShow = 4;
						opts.responsive.push({
							"breakpoint" : 1024,
							"settings" : {
						        "slidesToShow" : 2,
						        //"slidesToScroll" : 1,
						        //"infinite" : true,
						        "rows" : 2
					       	}
						});
					}

					$carousel.slick(opts);
				}
			}
		}
	}); // on document ready
})(window, document, jQuery);



/* open remote links in new window */
(function(win, doc) {
	
	var anchor = doc.createElement("a"),
		getURIBase = function(URI) { return (URI.match(/\./g) || []).length > 1 ? URI.substring( URI.indexOf( "." ) + 1 ) : URI; },
		exclude = [].slice.apply( doc.querySelectorAll("header a, footer a") );
	
	doc.addEventListener("click", function(evt) {
		if ( evt.target.matches("a") ) {
			anchor.href = evt.target.href;

			if ( getURIBase(doc.location.hostname) !== getURIBase(anchor.hostname) && exclude.indexOf( evt.target ) < 0 ) {
				evt.preventDefault();
				win.open( evt.target.href );
			}
		}
	});
})(this, this.document);






// Google Custom Site Search
(function(window, document, $) {
	$(function() {
		
	    /*var cx = Drupal.settings.COM.googleSearchCx;
	    if ( cx ) {
	    	    
	    var gcse = document.createElement('script');
	    gcse.type = 'text/javascript';
	    gcse.async = true;
	    gcse.src = (document.location.protocol == 'https:' ? 'https:' : 'http:') +
	        '//www.google.com/cse/cse.js?cx=' + cx;
	    var s = document.getElementsByTagName('script')[0];
	    s.parentNode.insertBefore(gcse, s);*/
	    
		var cx = '017521502328193371144:y_-cdddnodg',
			gcse = document.createElement('script'),
			s = document.getElementsByTagName('script')[0];
				
		gcse.type = 'text/javascript';
		gcse.async = true;
		gcse.src = (document.location.protocol == 'https:' ? 'https:' : 'http:') + '//cse.google.com/cse.js?cx=' + cx;
		s.parentNode.insertBefore(gcse, s);

	    gcse.addEventListener("load", function() {
			__gcse.callback = function () {

				/* Fix for Google logo not having alt tags for accessibility - MB 04.28.2015 */

				var x = document.getElementsByClassName("gsc-branding-img");

				for (i = 0; i < x.length; i++) {
					if(x[i].tagName == "IMG") {
	        	x[i].alt = "Google logo";
	    		}
				}

				/* Fix for Google image button not having alt tags for accessibility - MB 04.28.2015 */

				var y = document.getElementsByClassName("gsc-search-button-v2");

				for (i = 0; i < y.length; i++) {
					y[i].alt = "Search";
	    	}

				var searchBoxes = document.querySelectorAll('input.gsc-input[type="text"]'),
					searchBoxesLength = searchBoxes.length;

				//for (var i = 0; i < searchBoxesLength; i++) { searchBoxes[i].setAttribute('placeholder', 'Search...'); }

				/* Fix for Google multiple search boxes having the same id for accessibility. Changes the mobile one to a -mobile id - MB 05.13.2015 */
				var bgresponses = [].slice.apply( document.querySelectorAll("#bgresponse") );
				if ( bgresponses.length > 1 ) {
					bgresponses[1].id = "bgresponse-mobile";
				}

				/* Fix for removing cellspacing and cell padding from Google image search area for accessibility - MB 05.13.2015 */

				var z = document.querySelectorAll(".gsc-search-box > table, .gsc-input-box > table, table.gsc-search-box, table.gsc-branding, table.gsc-above-wrapper-area-container, table.gsc-resultsHeader, table.gssb_c");

				for (i = 0; i < z.length; i++) {
					z[i].removeAttribute("cellpadding");
					z[i].removeAttribute("cellspacing");
				}

			};
	    }, false);
	}); // on document ready
    // Google Custom Site Search
})(window, document, jQuery);

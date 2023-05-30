<!DOCTYPE html>
<!-- Sorry no IE7 support! -->
<!-- @see http://foundation.zurb.com/docs/index.html#basicHTMLMarkup -->
<!--[if IE 8]><html class="no-js lt-ie9" lang="en"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js" lang="en"> <!--<![endif]-->
<head>
	<?php print $head; ?>
	<title><?php print $head_title; ?></title>
	<?php print $styles; ?>
	<!--[if lt IE 9]><script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->
	<style>
	.progress {
		background-color:transparent;
		background-image: -moz-linear-gradient(left, #0f335e, #00244f);
		background-image: -webkit-gradient(linear, left top, right top, color-stop(0%, #0f335e), color-stop(100%, #00244f));
		background-image: -webkit-linear-gradient(left, #0f335e, #00244f);
		background-image: -o-linear-gradient(left, #0f335e, #00244f);
		background-image: -ms-linear-gradient(left, #0f335e, #00244f);
		background-image: linear-gradient(to right, #0f335e, #00244f);	
		border-radius: 999px;
		height: .75rem; }
	.progress .bar {
		background: transparent;
		border: 0;
		border-radius: 999px;
		height: 100%;
	}
	.progress .filled {
		background: #820000;
		border-radius: 999px;
		height: 80%;
	}
	</style>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
	<?php print $page_top; ?>
	<!--.page -->
	<div role="document" class="page">
  		<main role="main" class="row l-main">
  			<?php if ($sidebar_first): ?>
  				<aside role="complementary" class="<?php print $sidebar_first_grid_class; ?> sidebar-first column sidebar">
	  				<?php print $sidebar_first ?>
  			 	</aside>
	  		<?php endif; ?>						
			<div class="<?php print $main_grid_class; ?> main column">
				<?php if ($title): ?><h1 id="page-title" class="title"><?php print $title; ?></h1><?php endif; ?>
			
				<?php if ($messages): ?><div id="console"><?php print $messages; ?></div><?php endif; ?>
				<?php if ($help): ?><div id="help"><?php print $help; ?></div><?php endif; ?>
			
				<?php print $content; ?>
			</div>
			<!--/.main region -->
		</main>
		<?php print $page_bottom; ?>
	</div>
	<!--/.page -->
	<?php print $scripts; ?>
</body>
</html>
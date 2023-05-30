<!doctype html>
<html class="no-js" lang="">
	<head>
		<?php print $head; ?>
		
		<?php print com_foundation_build_favicon(); ?>
		
		<title><?php print $head_title; ?></title>
		<?php print $styles; ?>
	</head>
	<body class="<?php print $classes; ?>" <?php print $attributes;?>>
		<?php print $page_top; ?>
		<div role="document" class="page">
			<?php print $page; ?>
		</div><!--// .page -->
		<?php print $page_bottom; ?>
		<?php //print _com_foundation_add_reveals(); ?>
		<?php print $scripts; ?>
	</body>
</html>
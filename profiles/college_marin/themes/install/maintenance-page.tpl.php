<!doctype html>
<html lang="">
<head>
	<?php print $head; ?>
	<title><?php print $head_title; ?></title>
	<?php print $styles; ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
	<?php //print $page_top; ?>
	<div role="document" class="page">
		<main role="main" class="row l-main">						
			<?php if ($title): ?><h1 id="page-title" class="title"><?php print $title; ?></h1><?php endif; ?>
			<?php if ($messages): ?><div id="console"><?php print $messages; ?></div><?php endif; ?>
			<?php if ($help): ?><div id="help"><?php print $help; ?></div><?php endif; ?>
			<?php print $content; ?>		
		</main>
	</div>
	<?php //print $page_bottom; ?>
	<?php print $scripts; ?>
</body>
</html>
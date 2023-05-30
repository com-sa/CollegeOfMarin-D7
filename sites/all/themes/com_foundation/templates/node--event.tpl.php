<?php
 
// We hide the comments and links now so that we can render them later.
hide($content['comments']);
hide($content['links']);
hide($content['field_tags']); 

//$content_rendered = render($content); 

//if ($content_rendered):
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
	
	<?php print render($title_prefix); ?>
	<?php if (!$page): ?>
    	<?php if (!$page): ?>
			<h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
		<?php endif; ?>
	<?php endif; ?>
	<?php print render($title_suffix); ?>

	<?php if ($display_submitted): ?>
    	<div class="posted">
			<?php if ($user_picture): ?>
				<?php print $user_picture; ?>
			<?php endif; ?>
		<?php print $submitted; ?>
		</div>
	<?php endif; ?>
	
	<?php print render($content['body']); ?>
	
	<?php print render($content['links']); ?>
	<?php print render($content['comments']); ?>

</article>
<?php //endif; ?>
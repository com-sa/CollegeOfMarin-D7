<?php
 
// We hide the comments and links now so that we can render them later.
hide($content['comments']);
hide($content['links']);
hide($content['field_tags']); 

$date = isset($node->created) ? format_date($node->created, 'com_starter_full') : NULL;
$author = ( isset($node->uid) && ($node->uid > 0) ) ? user_load($node->uid)->name : NULL;

//$content_rendered = render($content); 

//if ($content_rendered):


$tags = isset($node->field_blog_tags[LANGUAGE_NONE]) ? $node->field_blog_tags[LANGUAGE_NONE] : '';
$tags_content = array();

if ( $tags ) {
	foreach( $tags as &$tag ) {
		$name = $tag['taxonomy_term']->name;
		$tags_content[] = '<a href="/blog/' . $name. '">' . $name . '</a>';
	}
	
	$tags = implode(", ", $tags_content);

}

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

	<div class="row">
		<?php if ($author): ?><div class="column medium-6 author">By <?php print $author; ?></div><?php endif; ?>
		<?php if ( $date ): ?><div class="column medium-6 date"><?php print $date; ?></div><?php endif; ?>
		<?php if ($tags): ?><div class="column tags"><?php print $tags; ?></div><?php endif; ?>
	</div>
	
	<?php print render($content['body']); ?>
	
	<?php print render($content['links']); ?>
	<?php print render($content['comments']); ?>

</article>
<?php //endif; ?>
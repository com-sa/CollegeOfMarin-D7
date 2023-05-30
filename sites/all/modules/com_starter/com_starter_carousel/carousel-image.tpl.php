<?php $image_path = $variables['image_path']; ?>
<?php $fullbleed = variable_get('com_starter_carousel_fullbleed', false); ?>
<?php if ( !$fullbleed ): ?>
<div class="row">
	<div class="column">
<?php endif; ?>
		<div class="carousel<?php print ($fullbleed ? ' fullbleed' : ''); ?>">
			<div class="page-banner" style="background-image: url('<?php print $image_path; ?>');">
				<img typeof="foaf:Image" src="<?php print $image_path; ?>" alt="<?php print drupal_get_title(); ?>" />
			</div>
		</div><!-- // .carousel -->
<?php if ( !$fullbleed ): ?>
	</div><!-- // .column -->
</div><!-- // .row -->
<?php endif; ?>
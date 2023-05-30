<?php
	
$slides = $variables['slides'];
$fullbleed = variable_get('com_starter_carousel_fullbleed', false);	
$items = array();
?>

<?php if ( !$fullbleed ): ?>
<div class="row">
	<!--div class="column"-->
<?php endif; ?>

		<div class="carousel<?php print ($fullbleed ? ' fullbleed' : ''); ?>">

<?php foreach( $slides as &$slide ) : ?>

<?php 
	$title = $slide['title'] ? $slide['title'] : '';
	$body = isset( $slide['image_field_caption'] ) ? $slide['image_field_caption']['value'] : '';
	$img_url = image_style_url('2000x640', $slide['uri'] );
	$img = '<img typeof="foaf:Image" src="' . $img_url . '" alt="' . $title. '" />';	
?>
			<div class="page-banner" style="background-image: url('<?php print $img_url; ?>');">
				
				<?php if ( $title || $body ): ?>
				<div class="carousel-layover">
					<?php if ($fullbleed): ?><div class="row"><div class="column"><?php endif; ?>
						<?php if ( $title ): ?><h3 class="title"><?php print $title; ?></h3><?php endif; ?>
						<?php if ( $body && !$fullbleed ): ?><div class="body"><?php print $body; ?></div><?php endif; ?>
					<?php if ($fullbleed): ?></div></div><?php endif; ?>
				</div>
				<?php endif; ?>
				
				<?php print $img; ?>
			</div>

<?php endforeach; ?>

		</div><!-- // .carousel -->

<?php if ( !$fullbleed ): ?>
	<!--/div--><!-- // .column -->
</div><!-- // .row -->
<?php endif; ?>
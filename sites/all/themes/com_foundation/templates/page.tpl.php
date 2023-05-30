<!-- header -->
<?php include(drupal_get_path('theme', 'com_foundation') . '/inc/header.inc'); ?>

<?php if (!empty($page['featured'])): ?>
<section id="featured" class="<?php print isset($page['featured']['#attributes']['class']) ? $page['featured']['#attributes']['class'] : ''; ?>">
	<?php print render($page['featured']); ?>
</section><!--// #featured -->
<?php endif; ?>

<main id="main" class="row">

	<?php $is_main_content = $is_front && isset($node) && isset($node->body['und']) && !empty($node->body['und'][0]['safe_value']); ?>

	<div id="content" class="<?php print $main_grid_class; ?><?php print $is_front && !$is_main_content ? '' : ' main'; ?> column">
		<a id="main-content"></a>

		<?php // Let's show the page title on: all interior pages and the home page if there is body content ?>
		<?php if ($title && (!$is_front || $is_main_content ) ): ?>
			<?php print render($title_prefix); ?>
			<h1 id="page-title" class="title"><?php print $title; ?></h1>
			<?php print render($title_suffix); ?>
		<?php endif; ?>

		<?php if (!empty($tabs)): ?>
			<?php print render($tabs); ?>
			<?php if (!empty($tabs2)): print render($tabs2); endif; ?>
		<?php endif; ?>

		<?php if ($action_links): ?>
			<ul class="action-links">
				<?php print render($action_links); ?>
			</ul>
		<?php endif; ?>
		
		<?php print render($page['content']); ?>
	
		<?php if (!empty($page['content_addt'])): ?>
		<div id="content-additional" class="row">
			<?php print render($page['content_addt']); ?>
		</div>
		<?php endif; ?>	
		
	</div><!--// .main region -->

	<?php if (!empty($page['sidebar_first'])): ?>
	<aside role="complementary" class="<?php print $sidebar_first_grid_class; ?> sidebar-first column sidebar">
		<?php print render($page['sidebar_first']); ?>
	</aside>
	<?php endif; ?>	

	<?php if (!empty($page['sidebar_second'])): ?>
	<aside role="complementary" class="<?php print $sidebar_sec_grid_class; ?> sidebar-second column sidebar">
		<?php print render($page['sidebar_second']); ?>
	</aside>
	<?php endif; ?>
</main>
<!--// .main-->

<?php if ($messages): ?>
	<section id="messages"><div class="column"><?php print $messages; ?></div></section>
<?php endif; ?><!--// #messages -->

<!-- footer -->
<?php include(drupal_get_path('theme', 'com_foundation') . '/inc/footer.inc'); ?>
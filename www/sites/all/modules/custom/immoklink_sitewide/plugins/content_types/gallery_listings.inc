<?php
/**
 * @file
 * Plugin to output logo.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Gallery listings'),
  'category' => t('Immo Klink'),
  'defaults' => array(),
  'render callback' => 'immoklink_sitewide_gallery_listings_content_type_render',
  'required context' => array(
    new ctools_context_required(t('Node'), 'node'),
  ),
);

/**
 * Output function for the 'node' content type.
 *
 * Outputs a node based on the module and delta supplied in the configuration.
 */
function immoklink_sitewide_gallery_listings_content_type_render($subtype, $conf, $panel_args, $context) {
  $output = '';

  if (!isset($context[0]->data)) {
    return;
  }

  $node = $context[0]->data;

  if (isset($node->field_gallery_list_gallery_type[LANGUAGE_NONE])) {
    $gallery_id = $node->field_gallery_list_gallery_type[LANGUAGE_NONE][0]['target_id'];

    $query = new EntityFieldQuery();
    $results = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'gallery')
      ->propertyCondition('status', 1, '=')
      ->fieldCondition('field_gallery_gallery_type', 'target_id', $gallery_id, '=')
      ->fieldOrderBy('field_gallery_lading_ordering', 'value', 'ASC')
      ->execute();

    $nodes = node_load_multiple(array_keys($results['node']));
    $output .= theme('immoklink_gallery', array('node' => $nodes));
  }


  $block = new stdClass();
  $block->title = '';
  $block->content = $output;

  return $block;
}


/**
 * Returns the administrative title for a node.
 */
function immoklink_sitewide_gallery_listings_content_type_admin_title($subtype, $conf) {
  return t('Gallery listings');
}

/**
 * Returns an edit form for custom type settings.
 */
function immoklink_sitewide_gallery_listings_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Submit handler for the custom type settings form.
 */
function immoklink_sitewide_gallery_listings_content_type_edit_form_submit($form, &$form_state) {
  foreach ($form_state['values'] as $k => $v) {
    if (!empty($form_state['values'][$k])) {
      $form_state['conf'][$k] = $form_state['values'][$k];
    }
  }
}

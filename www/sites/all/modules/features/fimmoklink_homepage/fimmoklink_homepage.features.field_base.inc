<?php
/**
 * @file
 * fimmoklink_homepage.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function fimmoklink_homepage_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_homepage_images'.
  $field_bases['field_homepage_images'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_homepage_images',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  return $field_bases;
}

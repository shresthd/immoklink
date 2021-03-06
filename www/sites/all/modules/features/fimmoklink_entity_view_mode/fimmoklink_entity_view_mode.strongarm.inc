<?php
/**
 * @file
 * fimmoklink_entity_view_mode.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function fimmoklink_entity_view_mode_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_view_modes';
  $strongarm->value = array(
    'file' => array(
      'image_landscale' => array(
        'label' => 'Image landscape',
        'custom settings' => 1,
      ),
      'image_portrait' => array(
        'label' => 'Image portrait',
        'custom settings' => 1,
      ),
    ),
  );
  $export['entity_view_modes'] = $strongarm;

  return $export;
}

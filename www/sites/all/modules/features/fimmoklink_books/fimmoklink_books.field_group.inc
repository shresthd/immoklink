<?php
/**
 * @file
 * fimmoklink_books.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function fimmoklink_books_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_information|node|books|form';
  $field_group->group_name = 'group_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'books';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_books_description',
      1 => 'field_books_books',
      2 => 'metatags',
      3 => 'title',
      4 => 'path',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-information field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_information|node|books|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Information');

  return $field_groups;
}

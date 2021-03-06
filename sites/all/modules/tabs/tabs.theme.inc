<?php
// $Id: tabs.theme.inc,v 1.4 2009/08/19 15:16:50 nedjo Exp $

/**
 * @file
 * Theme functions for tabs.
 */

/**
 * Return rendered tabset.
 *
 * @themable
 */
function theme_tabset($element) {
  $output = '<div id="tabs-'. $element['#tabset_name'] .'"'. drupal_attributes($element['#attributes']) .'>';
  $output .= '<ul class="tabs clear-block">';
  foreach (element_children($element) as $key) {
    if (isset($element[$key]['#type']) && $element[$key]['#type'] == 'tabpage') {
      // Ensure the tab has content before rendering it.
      if (isset($element[$key]['#content']) && !empty($element[$key]['#content']) || (isset($element[$key]['#children']) && !empty($element[$key]['#children']))) {
        $output .= '<li'. drupal_attributes($element[$key]['#attributes']) .'><a href="' . $element[$key]['#url'] . '"><span class="tab">'. $element[$key]['#title'] .'</span></a></li>';
      }
    }
  }
  $output .= '</ul>';
  if (isset($element['#children'])) {
    $output .= $element['#children'];
  }
  $output .= '</div>';
  return $output;
}

/**
 * Return rendered content of a tab.
 *
 * @themable
 */
function theme_tabpage($element) {
  $output = '';
  // Ensure the tab has content before rendering it.
  if (isset($element['#content']) && !empty($element['#content']) || (isset($element['#children']) && !empty($element['#children']))) {
    $output .= '<div id="' . $element['#tab_name'] . '" class="tabs-' . $element['#tabset_name'] . '">';
    $output .= '<h2 class="drupal-tabs-title js-hide">'. $element['#title'] .'</h2>';
    $output .= $element['#content'] . $element['#children'];
    $output .='</div>';
  }
  return $output;
}

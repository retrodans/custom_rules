<?php

/**
* Implement hook_rules_action_info().
*/
function custom_rules_rules_action_info() {
  return array(
    'custom_rules_rules_action_return_message' => array(
      'label' => t('Return a test message to the admin'),
      'group' => t('Custom'),

      # List the parameters used by this rule
      'parameter' => array(
        'message_end' => array(
          'type' => 'text',
          'label' => t('A little message to go at the end of your message.'),
          'description' => t('A little message to go at the end of your message.'),
        ),
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
      ),

      # What is returned (not useful here, but could be handy if you are using more actions in your rule)
      'provides' => array(
        'return_message' => array(
          'type' => 'text',
          'label' => t('A return message'),
        ),
      ),
    ),
  );
}


/**
 * Callback to use the parameters passed in from the info hook
 */
function custom_rules_rules_action_return_message($message_end, $node) {
  // Create the string to output
  $string = t('you have just updated a %title created on %created_date modified on %modified_date - so %message_end', array('%message_end' => $message_end, '%title' => $node->title, '%created_date' => $node->created, '%modified_date' => date($node->changed)));

  // Return the variable(s) for future usage
  return array(
    'return_message' => $string,
  );
}

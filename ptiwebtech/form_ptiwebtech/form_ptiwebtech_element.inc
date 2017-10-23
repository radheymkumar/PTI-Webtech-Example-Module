<?php

function pti_form_element_form($form, &$form_state) {
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('eg. Radhey Kumar'),
  );
  $form['mobile'] = array(
    '#type' => 'textfield',
    '#title' => t('Mobile'),
    '#description' => t('eg. First Two no {9-7} after {0-9}'),
  );
  $form['email'] = array(
  	'#type' => 'textfield',
  	'#title' => t('Email'),
  	'#description' => t('eg. radhey@gmail.com'),
  );
  $form['number'] = array(
  	'#type' => 'textfield',
  	'#title' => t('Number'),
  	'#description' => t('eg. Less then < 1000 and Grater then > 100'),
  );
  $date = format_date(REQUEST_TIME, 'custom', 'Y-m-d H:i:s');
  $form['date'] = array(
    '#type' => 'date_popup',
    '#date_format' => 'd-m-Y',
    '#date_year_range' => '-10:+0',
    '#default_value' => $date,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
	return $form;
}

function pti_form_element_form_validate($element, &$form_state) {
	
	/*$name = $element['name']['#value'];
	if ( !preg_match( '/^[a-zA-Z\s]+$/', $name) ) {
      form_set_error('', t('The Name you entered is not validated.'));
    }
    $mobile = $element['mobile']['#value'];
    if( !preg_match('/^[7-9]{2}[0-9]{8}+$/', $mobile) ) {
    	form_set_error('', t('The Mobile entered is not validated.'));
    }
    $email = $element['email']['#value'];
    if( !filter_var($email, FILTER_VALIDATE_EMAIL)) {
    	form_set_error('', t('The Email entered is not validated.'));
    }*/
    /*$number = $element['number']['#value'];
    if(!($number > 100 && $number < 1000)) {
     	form_set_error('', t('Less then < 1000 and Grater then > 100'));
    } */
    $date = $element['date']['#value'];
   
}

function pti_form_element_form_submit($form, &$form_state) {

	unset($form_state['values']['submit'],$form_state['values']['form_build_id'],$form_state['values']['form_token'],      	 $form_state['values']['form_id'],$form_state['values']['op']);
		foreach ($form_state['values'] as $key=>$value) {
			variable_set($key, $value);
			drupal_set_message(
				t('%name has value %value', 
					array(
						'%name' => $key, 
						'%value' => print_r($value, TRUE),
						)
					)
			);	
		}
	//drupal_add_js('JQuery(document).ready(function(){ alert("Hello"); });','inline');	
}
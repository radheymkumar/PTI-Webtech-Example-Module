<?php

function pti_form_login_form($form, &$form_state) {
	$form['fname'] = array(
			'#type' => 'textfield',
			'#title' => t('Full Name'),
			'#required' => True,
		);
	$form['user'] = array(
			'#type' => 'textfield',
			'#title' => t('Username'),
			'#required' => True,
		);
	$form['mail'] = array(
			'#type' => 'textfield',
			'#title' => t('Email'),
			'#required' => True,
		);
	$form['password'] = array(
			'#type' => 'password_confirm',
			'#required' => True,
		);

	/*$sql = 'SELECT * FROM {role}';
  	$q = db_query($sql);
  	foreach ($dropdown_source as $item) {
			$key   = $item->rid;
			$value = $item->name;
			$dropdown_array[$key] = $value;
		}*/
  	/*$roles = array();
  	while ($row = mysql_fetch_array($q)) {
   	 $key = $row['rid'];
   	 $value = $row['name'];
   	 $dropdown_roles['key'] = $values;
  	}*/

	$form['roles'] = array(
			'#type' => 'select',
			'#title' => t('Select Role'),
			'#multiple' => 'multiple',
			'#options' => user_roles() //array('2' => 'Authenticated User', '3' => 'Administrator', '4' => 'Member'),
		);
	$form['send_message'] = array(
		'#type' => 'checkbox',
		'#title' => t('Notify user of new account via email.'),
		'#description' => 'If left unchecked, a message will not be sent.',
		'#default_value' => 1,
	);

	$form['submit'] = array(
			'#type' => 'submit',
			'#value' => t('Login'),
		);
	return $form;
}

function pti_form_login_form_submit($form, &$form_state) {
	//drupal_set_message("Success");
		//echo "<pre>";

	$roles_list = $form['roles']['#options'];
	$roles_get_key = $form_state['values']['roles'];

	$role = array();  foreach ($roles_get_key as $value) 	$role[$value] = $roles_list[$value];

	
	$password = $form_state['values']['password'];
	$edit = array(
		'name' => $form_state['values']['user'],
		'pass' => $password,
		'mail' => $form_state['values']['mail'],
		'init' => $form_state['values']['mail'],
		'status' => 1,
		'access' => REQUEST_TIME,
		'roles' => $role,  //array(4 => 'member'),
		'field_full_name' => array(LANGUAGE_NONE => array(array('value' => $form_state['values']['fname']))),
	);
/*	print_r($edit);
	die();*/
	user_save(drupal_anonymous_user(), $edit);
	/*--Send mail--*/
		$to = $form_state['values']['mail'];
		$subject = 'New account created';
		$headers = "From: example@drupal.org\nContent-type: text/html";
		$body = 'Your login details are as follows: 
				 Username : '. $form_state['values']['user'].' 
				 Password : '. $form_state['values']['password'].'  
				 Please login to Something.org and change your password.';
		if($form_state['values']['send_message'] == 1)	{
			mail($to,$subject,$body,$headers);
			drupal_set_message('Thank you...Registration is Successfully. Plz login email account.');
		} else {		 
			drupal_set_message('Registration Successfully.');
		}	
}



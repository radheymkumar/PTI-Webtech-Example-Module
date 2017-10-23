<?php



function pti_form_state_form($form, &$form_state) {
	$form['contact_info'] = array(
		'#markup' =>t('<h2>This is my custom form.</h2>'),
	);
	$form['#action'] = url('my-custom-page');
	$form['#method'] = 'get';

	$form['name'] = array(
		'#type' => 'textfield',
		'#title'=> t('Name'),
		'#size' => 60,
		'#maxlength' => 20,
		'#required' => True,
		'#field_suffix' => t('/-'),
		'#field_prefix' => t('Mr/Miss'),
		'#attributes' => array('class'=>array('custom-name')),
		'#prefix' => '<div class="poll-form">',
		'#suffix' => '</div>', 
	);
	$form['gender'] = array(
		'#type' => 'radios',
		'#title' => t('Gender'),
		'#options' => array(
						'male'=>t('Male'),
						'female'=>t('Female'),
					),
		'#required' => True,
	);
	$form['hobby'] = array(
		'#type' => 'checkboxes',
		'#title' => t('Hobbies'),
		'#options' => array(
						'music'=>t('Music'),
						'reading'=>t('Reading'),
						'dance'=>t('Dance'),
					),
	);
	$form['category'] = array(
		'#type' => 'select',
		'#title' => t('Category'),
		'#options' => array(
						''=>t('--Select--'),
						'Gen'=>t('Gen'),
						'Obc'=>t('Obc'),
						'Sc'=>t('Sc'),
						'St'=>t('St'),
						'Other'=>t('Other'),
					),
	);
	$form['technology'] = array(
		'#type' => 'select',
		'#title' => t('Technology'),
		'#multiple' => 'multiple',
		'#size' => 5,
		'#options' => array(
						''=>t('--Select--'),
						'Drupal'=>t('Drupal'),
						'Wordpress'=>t('Wordpress'),
						'Magento'=>t('Magento'),
						'Shopify'=>t('Shopify'),
						'Ruby on Rails'=>t('Ruby on Rails'),
						'Codeigniter'=>t('Codeigniter'),
						'Cake Php'=>t('Cake Php'),
						'Android'=>t('Android'),
						'Photoshop'=>t('Photoshop'),
						'Jquery'=>t('Jquery'),
						'Java Script'=>t('Java Script'),
						'MySql'=>t('MySql'),
						'Html5'=>t('Html5'),
						'CSS3'=>t('CSS3'),
						'Bootstrap'=>t('Bootstrap'),
					),
	);
	$form['password'] = array(
		'#type' => 'password',
		'#title' => t('Password'),
		'#size' => 60,
		'#required' => True,
	);
	$form['password_confirm'] = array(
		'#type' => 'password_confirm',
		'#title' => t('Password Confirm'),
		'#required' => True,
	);
	$form['date'] = array(
		'#type'=> 'date',
		'#title'=> t('Date'),
	);
	$form['file'] = array(
		'#type' => 'file',
		'#title' => t('Choose a file'),
		//'#title_display' => 'invisible',
		//'#upload_validators' => array('file_validate_extensions' => array('png, jpg, gif')),
	);
	$form['description'] = array(
		'#type' => 'text_format',
		'#title' => t('Description'),
	);
	$form['textarea'] = array(
		'#type' => 'textarea',
		'#title' => t('Description Textarea'),
		'#description' => t('this is using form comments text here...'),
	);
	$form['weight'] = array(
		'#type' => 'weight',
		'#title' => t('Weight'),
	);
	$form['autocomplete'] = array(
		'#type' => 'textfield',
		'#title' => t('Authored by'),
		'#maxlength' => 60,
		'#autocomplete_page' => 'user/autocomplete',
	);
	$form['vertical_tabs'] = array(
		'#type' => 'vertical_tabs',
		'#default_tab' => 'edit-tab1',
	);
		$form['tab1'] = array(
			'#type' =>'fieldset',
			'#title' => t('Tab 1'),
			'#collapsible' => True,
			'#group' => 'vertical_tabs',
		);
			$form['tab1']['field1'] = array(
				'#type' => 'textfield',
				'#title' => t('Field 1'),
				'#default_value' => 'Tab-1',
			);
			$form['tab1']['field2'] = array(
				'#type' => 'textfield',
				'#title' => t('Field 2'),
				'#default_value' => 'Tab-2',
			);

		$form['tab2'] = array(
			'#type' =>'fieldset',
			'#title' => t('Tab 2'),
			'#collapsible' => True,
			'#group' => 'vertical_tabs',
		);
			$form['tab2']['field3'] = array(
				'#type' => 'textfield',
				'#title' => t('Field 3'),
				'#default_value' => 'Tab-3',
			);
			$form['tab2']['field4'] = array(
				'#type' => 'textfield',
				'#title' => t('Field 4'),
				'#default_value' => 'Tab-4',
			);

	$dropdown_source = taxonomy_get_tree(2);
		foreach ($dropdown_source as $item) {
			$key   = $item->tid;
			$value = $item->name;
			$dropdown_array[$key] = $value;
		}
		//	print_r($dropdown_array);
		$form['taxonomy_get_tree'] = array(
			'#type' => 'select',
			'#title' => t('Taxonomy get tree'),
			'#options' => $dropdown_array,
		);
				
	$form['submit'] = array(
		'#type'=> 'submit',
		'#value'=>t('Submit'),
	);
	$form['clear'] = array(
		'#type'=>'submit',
		'#value'=>t('Clear'),
	);
	$form['preview'] = array(
		'#type' => 'button',
		'#value' => t('Preview'),
	);
		/*$dropdown_source = taxonomy_get_tree(2);
		$dropdown_array = array('0' => '--none--');
		foreach ($dropdown_source as $item) {
		$key = $item->tid;
		$value = $item->name;
		$dropdown_array[$key] = $value;
		}*/
		
		//$tids = array(1, 2);

		
	return $form;
}
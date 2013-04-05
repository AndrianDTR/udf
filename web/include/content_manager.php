<?php
/*****************************************************************************
 *                                                                           *
 * Andrian Yablonskyy                                                        *
 * Copyright (c) 2011 Andrian Yablonskyy. All rights reserved.               *
 * andrian.yablonsky@gmail.com                                               *
 *                                                                           *
 ****************************************************************************/

defined('__INDEX') or die('Restricted access');

function getContent()
{
	$modules = array();
	// create a handler for the directory
	$module_files = glob("./modules/*.php");
	
	$data = array();
	$error = 0; // 0 - OK, else = error.
	
	$mod = GetSentNdx('m');
	$modules = array();
	
	foreach($module_files as $m)
	{
		$mod_name = "";
		include($m);
		$modules[$mod_name] = new $mod_name();
	}
	
	if($mod && $modules[$mod]) 
		list($error, $data) = $modules[$mod]->display($error, $data);
	
	//Return data to user
	echo (Reply($error, $data));
}
?>

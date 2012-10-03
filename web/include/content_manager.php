<?php
/*****************************************************************************
 *                                                                           *
 * Andrian Yablonskyy                                                        *
 * Copyright (c) 2011 Andrian Yablonskyy. All rights reserved.               *
 * andrian.yablonsky@gmail.com                                               *
 *                                                                           *
 ****************************************************************************/

defined('__INDEX') or die('Restricted access');

$modules = array();
// create a handler for the directory
$module_files = glob("./modules/*.php");
	
function getContent()
{
	$data = array();
	$error = 0; // 0 - OK, else = error.
	
	$mod = GetSentNdx('m');
	$modules = array();
	foreach($m in $module_files)
	{
		$mod_name = "";
		include($m);
		$modules[$mod_name] = new $mod_name();
	}

	if($mod && $modules[$mod_name]) 
		list($error, $data) = $modules[$mod]->display();
	
	//Return data to user
	echo (Reply($error, $data));
}
?>

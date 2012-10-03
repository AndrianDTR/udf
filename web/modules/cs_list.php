<?php
/*****************************************************************************
 *                                                                           *
 * Andrian Yablonskyy                                                        *
 * Copyright (c) 2011 Andrian Yablonskyy. All rights reserved.               *
 * andrian.yablonsky@gmail.com                                               *
 *                                                                           *
 ****************************************************************************/

defined('__INDEX') or die('Restricted access');

$mod_name = "cs_list";

class $mod_name{
	function display($error, $data)
	{
		$data = $mod_name.".Display()";
		return ($error, $data);
	}
}

?>

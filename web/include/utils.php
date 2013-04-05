<?php
/*****************************************************************************
 *                                                                           *
 * Andrian Yablonskyy                                                         *
 * Copyright (c) 2011 Andrian Yablonskyy. All rights reserved.                *
 * andrian.yablonsky@gmail.com                                               *
 *                                                                           *
 ****************************************************************************/

defined('__INDEX') or die('Restricted access');

function GetSentNdx($ndx)
{
	return isset($_POST[$ndx]) ? $_POST[$ndx] : (isset($_GET[$ndx]) ? $_GET[$ndx] : "");
}

/**
* Starts the $haystack string with the prefix $needle?
* @param  string
* @param  string
* @return bool
*/
function startsWith($haystack, $needle)
{
	return strncmp($haystack, $needle, strlen($needle)) === 0;
}


/**
* Ends the $haystack string with the suffix $needle?
* @param  string
* @param  string
* @return bool
*/
function endsWith($haystack, $needle)
{
	return strlen($needle) === 0 || substr($haystack, -strlen($needle)) === $needle;
}


function assign($key, $val)
{
	global $smarty;
	$smarty->assign($key, $val);
}

function fetch($tpl)
{
	global $smarty;
	return $smarty->fetch($tpl);
}

function A2Json($arr)
{
	$cb = GetSentNdx('callback');

	$res = json_encode($arr);

	if (!empty($cb))
	{
		$res = $cb.'(' . json_encode($arr) . ')';
	}

	return $res;
}

function Reply($err, $data)
{
	echo A2Json(array("err"=>$err, "data"=>$data));
}

function sd($a, $l = 0)
{
	$debug = $a;
	if(defined('debug'))
	{

		$backtrace = debug_backtrace();
		foreach($backtrace as $bt)
		{
			$debug .= ' <- [File:'.$bt['file'].', Line:'.$bt['line'].']';
		}
		$debug .= PHP_EOL.PHP_EOL;
		//$debug .= ' [File:'.$backtrace[$l]['file'].', Line:'.$backtrace[$l]['line'].']'.PHP_EOL;
	}
	return $debug;
}

function esd($a)
{
	$f = fopen("./log.txt", "a+");
	fwrite($f, sd($a, 1));
	fclose($f);
	//echo sd($a, 1);
}
?>

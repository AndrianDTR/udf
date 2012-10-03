<?php
/*****************************************************************************
 *                                                                           *
 * Andrian Yablonskyy                                                        *
 * Copyright (c) 2011 Andrian Yablonskyy. All rights reserved.               *
 *                                                                           *
 ****************************************************************************/

//	database functions :: MySQL

function db_connect($host, $user, $pass) //create connection
{
	$r = mysql_connect($host,$user,$pass) or die("<br/>Connect:".$user.':'.$pass.'@'.$host." --> ".db_error());
	if(preg_match('/^5\./',mysql_get_server_info($r)))db_query('SET SESSION sql_mode=0');
	return $r;
}

function db_select_db($name) //select database
{
	return mysql_select_db($name) or die("<br/>Select db:".$name." --> ".db_error());
}

function db_query($s) //database query
{
	$q = mysql_query($s) or die("<br/>query:".$s." --> ".db_error());
	return $q;
}

function db_fetch_row($q) //row fetching
{
	return mysql_fetch_row($q);
}

function db_fetch_field($q) //row fetching
{
	return mysql_fetch_field($q);
}

function db_fetch($q) //row fetching
{
	return mysql_fetch_assoc($q);
}

function db_insert_id()
{
	return mysql_insert_id();
}
function db_num_rows($q)
{
	return mysql_num_rows($q);
}

function db_error() //database error message
{
	return mysql_error();
}

?>

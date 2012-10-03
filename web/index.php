<?php
/*****************************************************************************
 *                                                                           *
 * Andrian Yablonskyy                                                         *
 * Copyright (c) 2011 Andrian Yablonskyy. All rights reserved.                *
 * andrian.yablonsky@gmail.com                                               *
 *                                                                           *
 ****************************************************************************/

define('__INDEX', 1);
define('debug',1);

if (defined('debug'))
{
//	if(file_exists("./log.txt"))
//		unlink("./log.txt");
	ini_set("display_errors", "1");
	error_reporting(E_ALL | E_STRICT);
}

session_start();

require 'smarty/smarty.class.php';
require 'include/connect.php';
require 'include/db.php';
require 'include/utils.php';
require 'include/profile_manager.php';
require 'include/content_manager.php';

$smarty = new Smarty();
$smarty->template_dir = TPL;

$db_link = db_connect(DB_HOST, DB_USER, DB_PASS);
db_query("SET character_set_results = 'utf8', character_set_client = 'utf8', character_set_connection = 'utf8', character_set_database = 'utf8', character_set_server = 'utf8'", $db_link);
db_select_db(DB_NAME);

$smarty->assign("PORTAL_TITLE", "Club profile");
$smarty->assign("PORTAL_COPYRIGHT", "Copyright (c) 2012. Andrian Yablonskyy, all rights reserved.");

//print_r($_POST);

$act = GetSentNdx('a');
if(($act == 'login' && UserLogin())
|| ($act != 'logout' && isUserLogined()))
{
	assign("user_logined", 1);
}

if($act == 'gc')
{
	getContent();
	exit();
}

if($act == 'logout' )
{
	UserLogout();
	assign("user_logined", 0);
}

$smarty->display("index.tpl.html");
?>

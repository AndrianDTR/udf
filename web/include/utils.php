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

function UserLogin()
{
	$reply = "Login failed";
	$error = false;

	$q = db_query("SELECT id, login FROM ".T_CLUBS." WHERE "
	."login='".$_POST['user']."' AND "
	."pass='".$_POST['pass']."'"
	);
	$count = db_num_rows($q);
	$row = db_fetch_row($q);
	
	if($count == 1 && $row)
	{
		setcookie("uid", $row[0], time()+7200);
		setcookie("s", md5(md5($_POST['pass'])), time()+7200);
		setcookie("l", $row[1], time()+7200);

		$reply = sd("Login OK.");

		db_query("update ".T_CLUBS." set online=ADDTIME(UTC_TIMESTAMP(), '2:00:00.0') where id=".$row[0]);
		$error = true;
	}
	else
	{
		setcookie("uid", NULL, time()-7200);
		setcookie("s", NULL, time()-7200);
		setcookie("l", NULL, time()-7200);
		$reply = sd("Login name or password is invalid. Please try again.");
	}

	assign("message", $reply);
	assign("error", $error);
	return $error;
}

function UserLogout()
{
	if(isset($_COOKIE["uid"]))
		db_query("update ".T_CLUBS." set online=UTC_TIMESTAMP() where id=".$_COOKIE["uid"]);

	setcookie("uid", NULL, time()-7200);
	setcookie("s", NULL, time()-7200);
	setcookie("l", NULL, time()-7200);

}
	
function GetUserInfo($uid)
{
	$ui = NULL;

	$res = db_query("select id as uid,login,pass from ".T_CLUBS." where id=$uid");
	if(db_num_rows($res) == 1 )
	{
		$ui = db_fetch($res);
		$ui['pass'] = md5(md5($ui['pass']));
  	}
	return $ui;
}

function isUserLogined()
{
	$res = false;
	do{
		if(isset($_COOKIE["uid"]))
  		{
			$ui = GetUserInfo($_COOKIE["uid"]);
			if(!$ui)
			{
				setcookie("uid", NULL, time()-7200);
				setcookie("s", NULL, time()-7200);
				setcookie("l", NULL, time()-7200);

				echo ("Obj NULL");
				break;
			}

			if(isset($_COOKIE["s"]) && $_COOKIE["s"] == $ui['pass'])
			{
				setcookie("uid", $_COOKIE["uid"], time()+7200);
				setcookie("s", $ui['pass'], time()+7200);
				setcookie("l", $ui['login'], time()+7200);

				db_query("update ".T_CLUBS." set online=ADDTIME(UTC_TIMESTAMP(), '2:00:00.0') where id=".$_COOKIE['uid']);
				$res = true;
			}
  		}
	}while(0);
	return $res;
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

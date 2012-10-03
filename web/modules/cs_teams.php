<?php
/*****************************************************************************
 *                                                                           *
 * Andrian Yablonskyy                                                        *
 * Copyright (c) 2011 Andrian Yablonskyy. All rights reserved.               *
 * andrian.yablonsky@gmail.com                                               *
 *                                                                           *
 ****************************************************************************/

defined('__INDEX') or die('Restricted access');

global $mod_name;
	
$mod_name = "cs_teams";

class cs_teams{
	function getCsCategoriesList($csId)
	{
		$catList = array();

		$res = db_query("select category_id from ".T_CS_CATEGORIES
		." where championship_id=$csId");
		while($row = db_fetch_row($res))
		{
			$name = "";
			$short_name = "";
			list($name, $short_name) = $this->getCategoryNameById($row[0]);
			$catList[] = $short_name;
		}
		//*/	
		return $catList;
	}
	
	function getCategoryNameById($catId)
	{
		$res = db_query("select name,short_name from ".T_CATEGORIES
		." where id=$catId");
		$row = db_fetch_row($res);
		return array($row[0], $row[1]);
	}
	
	function getTypeNameById($typeId)
	{
		$res = db_query("select name from ".T_CS_TYPES
		." where id=$typeId");
		$row = db_fetch_row($res);
		return $row[0];
	}
	
	function display($error, $data)
	{
		$data = "Get data from DB in ".get_class($this);
		/*
		$csList = array();
		$res = db_query("select id,type,name,additional_info,date,reg_open,reg_close from ".T_CS
		." where reg_close<NOW()");
		while($row = db_fetch_row($res))
		{
			$csRow = array();
			$csRow['id'] = $row[0];
			$csRow['type'] = $this->getTypeNameById($row[1]);
			$csRow['name'] = $row[2];
			$csRow['additional_info'] = $row[3];
			$csRow['date'] = $row[4];
			$csRow['reg_open'] = $row[5];
			$csRow['reg_close'] = $row[6];
			
			$csRow['categories_list'] = $this->getCsCategorieslist($csRow['id']);
			
			$csList[] = $csRow;
		}
		assign("csList", $csList);
		$data = fetch("cs_list.tpl.html");
		//*/
		return array($error, $data);
	}
}

?>

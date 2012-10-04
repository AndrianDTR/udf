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
	
$mod_name = "team_info";

class team_info{
	function getTeamDancersList($teamId)
	{
		$dancerList = array();
	
		$res = db_query("select id,dancer_id from ".T_CS_TEAM_DANCERS
		." where team_id=$teamId");
		while($row = db_fetch_row($res))
		{
			$dancerList[] = array('id'=>$row[0], 'name'=>$this->getDancerNameById($row[1]));
		}
		
		return $dancerList;
	}
	
	function getTeamCategoriesList($teamId)
	{
		$categoriesList = array();
	
		$res = db_query("select id,category_id,composition_name from ".T_CS_TEAM_CATEGORIES
		." where team_id=$teamId");
		while($row = db_fetch_row($res))
		{
			$categoriesList[] = array('id'=>$row[0], 'name'=>$this->getCategoryNameById($row[1]), 'composition'=>$row[2]);
		}
		
		return $categoriesList;
	}
	
	function getDancerNameById($dancerId)
	{
		$res = db_query("select name from ".T_DANCERS
		." where id=$dancerId");
		$row = db_fetch_row($res);
		return $row[0];
	}
	
	function getCategoryNameById($catId)
	{
		$res = db_query("select name from ".T_CATEGORIES
		." where id=$catId");
		$row = db_fetch_row($res);
		return $row[0];
	}
	
	function display($error, $data)
	{
		$teamId = GetSentNdx('id');
		$rmId = GetSentNdx('rm');
		if("" != $rmId)
		{
			db_query("delete from ".T_CS_TEAM
			." where id=$teamId");
		}
		else if($teamId != -1) 
		{
			$teamInfo = array();
			$res = db_query("select name, championship_id from ".T_CS_TEAM
			." where id=$teamId");
			if($row = db_fetch_row($res))
			{
				$teamInfo['name'] = $row[0];
				$teamInfo['csId'] = $row[1];
				$teamInfo['categories'] = $this->getTeamCategoriesList($teamId);
				$teamInfo['dancers'] = $this->getTeamDancersList($teamId);
			}
						
			assign("team", $teamInfo);
			$data = fetch("team_info.tpl.html");
		}
		//*/
		return array($error, $data);
	}
}

?>

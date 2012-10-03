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
	function getTeamDancersList($teamId)
	{
		$dancerList = array();
	
		$res = db_query("select dancer_id from ".T_CS_TEAM_DANCERS
		." where team_id=$teamId");
		while($row = db_fetch_row($res))
		{
			$dancerList[] = $this->getDancerNameById($row[0]);
		}
		
		return $dancerList;
	}
	
	function getDancerNameById($dancerId)
	{
		$res = db_query("select name from ".T_DANCERS
		." where id=$dancerId");
		$row = db_fetch_row($res);
		return $row[0];
	}
	
	function display($error, $data)
	{
		$clId = getCurrentUserId();
		$csId = GetSentNdx('id');
		
		$teamsList = array();
		$res = db_query("select id,name from ".T_CS_TEAM
		." where championship_id=$csId and club_id=$clId");
		while($row = db_fetch_row($res))
		{
			$teamRow = array();
			$teamRow['id'] = $row[0];
			$teamRow['name'] = $row[1];
			$teamRow['team_categories'] = $this->getTeamDancersList($row[0]);
			$teamRow['team_dancers'] = $this->getTeamDancersList($row[0]);
			$teamsList[] = $teamRow;
		}
		assign("teamList", $teamsList);
		$data = fetch("cs_teams.tpl.html");
		//*/
		return array($error, $data);
	}
}

?>

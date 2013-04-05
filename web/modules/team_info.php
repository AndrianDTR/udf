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
	
	function getCsCategories($csId)
	{
		$categoriesList = array();
	
		$res = db_query("select id,category_id from ".T_CS_CATEGORIES
		." where championship_id=$csId");
		while($row = db_fetch_row($res))
		{
			$categoriesList[] = array('id'=>$row[1], 'name'=>$this->getCategoryNameById($row[1]));
		}
		
		return $categoriesList;
	}
	
	function getClDancers($clId)
	{
		$dancerList = array();
	
		$res = db_query("select id,name from ".T_DANCERS
		." where club_id=$clId");
		while($row = db_fetch_row($res))
		{
			$dancerList[] = array('id'=>$row[0], 'name'=>$row[1]);
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
	
	function getCategoryNameById($catId)
	{
		$res = db_query("select name from ".T_CATEGORIES
		." where id=$catId");
		$row = db_fetch_row($res);
		return $row[0];
	}
	
	function display($error, $data)
	{
		do
		{
			$clId = getCurrentUserId();
			
			
			$teamId = GetSentNdx('id');

			$cat = GetSentNdx('cat');
			$dancer = GetSentNdx('dancer');
			$rm = GetSentNdx('rm');
			$add = GetSentNdx('add');
			$upd = GetSentNdx('upd');
			$name = GetSentNdx('name');
			$csId = GetSentNdx('cs');
			
			if("1" == $dancer)
			{
				if("" != $rm)
				{	
					db_query("delete from ".T_CS_TEAM_DANCERS
					." where team_id=$teamId and id=$rm");		
				}
				else
				{
					$res = db_query("select id from ".T_CS_TEAM_DANCERS
					." where team_id = $teamId and dancer_id = $add");
					if(0 < db_num_rows($res))
					{
						$error = 1;
						$data = "Dancer alredy in the list.";
						break;
					}
				
					db_query("insert into ".T_CS_TEAM_DANCERS
					."(team_id,dancer_id) values($teamId, $add)");
				}
			}
			else if("1" == $cat)
			{
				if("" != $rm)
				{
					db_query("delete from ".T_CS_TEAM_CATEGORIES
					." where team_id=$teamId and id=$rm");
				}
				else
				{
					$res = db_query("select id from ".T_CS_TEAM_CATEGORIES
					." where team_id = $teamId and category_id = $add");
					if(0 < db_num_rows($res))
					{
						$error = 1;
						$data = "Category alredy in the list.";
						break;
					}
					
					db_query("insert into ".T_CS_TEAM_CATEGORIES
					."(team_id,category_id,composition_name) values($teamId, $add, '$name')");
				}

			}
			else if("1" == $add)
			{
				$res = db_query("insert into ".T_CS_TEAM
				."(championship_id, club_id, name) values($csId, $clId, 'New team name')");
				$teamId = db_insert_id();
			}
			else if("1" == $rm)
			{
				db_query("delete from ".T_CS_TEAM
				." where id=$teamId");	
			}
			else if("1" == $upd)
			{
				db_query("update ".T_CS_TEAM
				." set name='$name' where id=$teamId");	
			}
		
			if($teamId != -1) 
			{
				$teamInfo = array();
				$res = db_query("select name, championship_id, club_id from ".T_CS_TEAM
				." where id=$teamId");
				if($row = db_fetch_row($res))
				{
					$teamInfo['id'] = $teamId;
					$teamInfo['name'] = $row[0];
					$teamInfo['csId'] = $row[1];
					$teamInfo['clId'] = $row[2];
					$teamInfo['categories'] = $this->getTeamCategoriesList($teamId);
					$teamInfo['dancers'] = $this->getTeamDancersList($teamId);
				}
			
				assign("csCategories", $this->getCsCategories($teamInfo['csId']));
				assign("clDancers", $this->getClDancers($teamInfo['clId']));
				assign("team", $teamInfo);
				$data = fetch("team_info.tpl.html");
			}
		}while(0);
		//*/
		return array($error, $data);
	}
}

?>

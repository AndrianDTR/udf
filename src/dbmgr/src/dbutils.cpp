#include "dbutils.h"

CDbConnection* g_pCon = NULL;

void SetGlobalDbConnection(CDbConnection* pCon)
{
	if (pCon)
		g_pCon = pCon;
}

CDbConnection* GetGlobalDbConnection()
{
	return g_pCon;
}

void dbmgr_version()
{
	printf("\n");
	printf("Library: dbmgr\n");
	printf("Version: %d.%d.%d\n", UDF_VERSION_MAJOR, UDF_VERSION_MINOR, UDF_VERSION_EXT);
	printf("Build: %d\n", UDF_VERSION_BUILDNUMBER);
	printf("Hash: %s\n", UDF_VERSION_HASH);
	printf("\n");
}

std::string date2str(time_t date)
{
	char buff[20];
	strftime(buff, 20, "%Y-%m-%d", localtime(&date));
	return std::string(buff);
}

time_t str2date(std::string str)
{
	time_t res;
	struct tm _date = {0};
    str += " 23:59:59";
	strptime(str.c_str(), "%Y-%m-%d %T", &_date);

	res = mktime(&_date);

	return res;
}

std::string time2str(time_t tTime)
{
	char buff[20];
	strftime(buff, 20, "%T", localtime(&tTime));
	return std::string(buff);
}

time_t str2time(std::string str)
{
	time_t res;
	struct tm _time = {0};
    strptime(str.c_str(), "%T", &_time);

	res = mktime(&_time);

	return res;
}

long GetTeamsCountForChampionship(unsigned int nId, int& count)
{
	long res = UDF_E_FAIL;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		sprintf(query, "select count(id) as count from %s where "
			"championship_id=%u", TABLE_CHAMPIONSHIPTEAM, nId);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		if(qRes->next())
			count = atoi(string(qRes->getString("count")).c_str());
	}while(0);

	return res;
}

long GetBlockLenById(unsigned int nId, time_t& len)
{
	long res = UDF_E_FAIL;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		//Calculate summary registereg teams(time) + pause*(len(teams)-1)
		/*
		select sec_to_time(tlen.len+tpause.len) total from (
		select sum(tt.TT) len from (select t1.name, sum(time_to_sec(t2.lenght)) as TT
		from championship_team t1 inner join (select b1.championship_id csId, b2.cs_cat_id catId
		from championship_blocks b1 inner join championship_block_j2c b2 on b1.id=b2.block_id and b1.id=2 group by b2.cs_cat_id) bc
		inner join championship_team_categories t2 on t1.id=t2.team_id and t1.championship_id=bc.csId and t2.category_id=bc.catId group by t1.name) tt) tlen,
		(select (count(t1.id)-1)*t.pause `len` from championship_team t1 inner join ( select t2.team_id tid, bc.pause `pause`
		from (select b1.championship_id `csId`, b2.cs_cat_id `catId`, b1.pause `pause` from championship_blocks b1 inner join championship_block_j2c b2
		on b1.id=b2.block_id and b1.id=1 group by catId) bc inner join championship_team_categories t2 on bc.catId=t2.category_id) t on t1.id=t.tid) tpause
		*/

		sprintf(query, "select sec_to_time(tlen.len+tpause.len) total from ("
			" select sum(tt.TT) len from (select t1.name, sum(time_to_sec(t2.lenght)) as TT "
			" from %s t1 inner join (select b1.championship_id csId,"
			" b2.cs_cat_id catId from %s b1 inner join "
			" %s b2 on b1.id=b2.block_id and b1.id=%d "
			" group by b2.cs_cat_id) bc inner join %s"
			" t2 on t1.id=t2.team_id and t1.championship_id=bc.csId and"
			" t2.category_id=bc.catId group by t1.name) tt) tlen, "
			" (select (count(t1.id)-1)*t.pause `len` from %s t1 "
			" inner join ( select t2.team_id tid, bc.pause `pause` "
			" from (select b1.championship_id `csId`, b2.cs_cat_id `catId`, "
			" b1.pause `pause` from %s b1 inner join "
			" %s b2 on b1.id=b2.block_id and b1.id=%d "
			" group by catId) bc inner join %s t2 "
			" on bc.catId=t2.category_id) t on t1.id=t.tid) tpause"
			, TABLE_CHAMPIONSHIPTEAM
			, TABLE_CHAMPIONSHIPBLOCKS
			, TABLE_CHAMPIONSHIPBLOCKJ2C
			, nId
			, TABLE_CHAMPIONSHIPTEAMCATEGORIES
			, TABLE_CHAMPIONSHIPTEAM
			, TABLE_CHAMPIONSHIPBLOCKS
			, TABLE_CHAMPIONSHIPBLOCKJ2C
			, nId
			, TABLE_CHAMPIONSHIPTEAMCATEGORIES
			);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		if(!qRes->next())
		{
			res = UDF_E_NOTFOUND;
		}

		len = str2time(qRes->getString("total"));
		res = UDF_OK;
	}while(0);

	return res;
}

long JudgeHaveCategory(unsigned int judId, unsigned int catId, unsigned int& rowId)
{
	long res = UDF_E_FAIL;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		sprintf(query, "select id from %s where judge_id=%d and cat_id=%d"
			, TABLE_JUDGESCATEGORIESHAVE
			, judId
			, catId);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		if(!qRes->next())
		{
			res = UDF_E_NOTFOUND;
			break;
		}

		rowId = qRes->getUInt("id");
		res = UDF_OK;
	}while(0);

	return res;
}

long JudgeHaveCsCategory(unsigned int judId, unsigned int csId)
{
	long res = UDF_E_FAIL;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		sprintf(query, "select judge_id, count(cat_id) as `count` from %s t1 join %s t2"
			" on t1.cat_id=t2.category_id and t2.championship_id=%d and t1.judge_id=%d group by judge_id"
			, TABLE_JUDGESCATEGORIESHAVE
			, TABLE_CHAMPIONSHIPCATEGORIES
			, csId
			, judId);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		if(!qRes->next())
		{
			res = UDF_E_NOTFOUND;
			break;
		}

		res = UDF_OK;
	}while(0);

	return res;
}

long GetTeamsInCategory(unsigned int nId, tUIList& teamsList)
{
	long res = UDF_E_FAIL;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		// select t1.id `id` from championship_team t1 inner join championship_team_categories t2 on t1.id=t2.team_id and t2.category_id=27
		sprintf(query, "select t1.id `id` from %s t1 inner join"
			" %s t2 on t1.id=t2.team_id and t2.category_id=%d order by t1.start_number "
			, TABLE_CHAMPIONSHIPTEAM
			, TABLE_CHAMPIONSHIPTEAMCATEGORIES
			, nId
			);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		teamsList.clear();
		while(qRes->next())
		{
			teamsList.push_back(qRes->getUInt("id"));
		}

		res = UDF_OK;
	}while(0);

	return res;
}

long IsCategoryUsedOnCsById(unsigned int nId, unsigned int blockId)
{
	long res = UDF_E_FAIL;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		/* select t1.cs_cat_id from championship_block_j2c t1 inner join
		(select  tb.id `id` from championship_blocks tb, (select championship_id `csid` from championship_blocks where id=1) bt where tb.championship_id=bt.csid and tb.id<>1) t2
		on t1.block_id=t2.id and t1.cs_cat_id=26
		//*/
		sprintf(query, "select t1.cs_cat_id from %s t1 inner join"
			" (select tb.id `id` from %s tb, (select championship_id `csid`"
			" from %s where id=%d) bt where tb.championship_id=bt.csid"
			" and tb.id<>%d) t2 on t1.block_id=t2.id and t1.cs_cat_id=%d"
			, TABLE_CHAMPIONSHIPBLOCKJ2C
			, TABLE_CHAMPIONSHIPBLOCKS
			, TABLE_CHAMPIONSHIPBLOCKS
			, blockId
			, blockId
			, nId
			);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		if(!qRes->next())
		{
			res = UDF_E_NOTFOUND;
			break;
		}

		res = UDF_OK;
	}while(0);

	return res;
}

long GetBlockCategories(unsigned int nId, tUIList& cats)
{
	long res = UDF_E_FAIL;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		// select cs_cat_id from championship_block_j2c where block_id = 1 group by cs_cat_id
		sprintf(query, "select cs_cat_id `id` from %s where block_id = %d group by cs_cat_id"
			, TABLE_CHAMPIONSHIPBLOCKJ2C
			, nId
			);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		cats.clear();
		while(qRes->next())
		{
			cats.push_back(qRes->getUInt("id"));
		}

		res = UDF_OK;
	}while(0);

	return res;
}

std::string GetTourTypeNameById(unsigned int nId)
{
	std:;string res;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			break;
		}
		// select t1.id `id` from tour_types t1 where t1.min <= 70 and t1.max > 70
		sprintf(query, "select name from %s t1 where id = %d"
			, TABLE_TOURTYPES
			, nId
			);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			break;
		}

		if(!qRes->next())
		{
			break;
		}

		res = qRes->getString("name");
	}while(0);

	return res;
}

long GetTourTypeByDancersCount(unsigned int nDancers, unsigned int& typeId)
{
	long res = UDF_E_FAIL;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		// select t1.id `id` from tour_types t1 where t1.min <= 70 and t1.max > 70
		sprintf(query, "select t1.id `id` from %s t1 where t1.min <= %d and t1.max > %d"
			, TABLE_TOURTYPES
			, nDancers
			, nDancers
			);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		if(!qRes->next())
		{
			res = UDF_E_NOTFOUND;
			break;
		}

		typeId = qRes->getUInt("id");
		res = UDF_OK;
	}while(0);

	return res;
}

long GetJudgesForCategory(unsigned int catId, tUIList& judges)
{
	long res = UDF_E_FAIL;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		// select t1.cs_judge_id `id` from championship_block_j2c t1 where t1.cs_cat_id=26
		sprintf(query, "select t1.cs_judge_id `id` from %s t1 where t1.cs_cat_id=%d"
			, TABLE_CHAMPIONSHIPBLOCKJ2C
			, catId
			);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		judges.clear();
		while(qRes->next())
		{
			judges.push_back(qRes->getUInt("id"));
		}

		res = UDF_OK;
	}while(0);

	return res;
}

long GetTeamStartNumber(unsigned int teamId, unsigned int& startNum)
{
	long res = UDF_E_FAIL;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		// select t1.start_number `start_num` from %s t1 where t1.id=%d
		sprintf(query, "select t1.start_number `start_num` from %s t1 where t1.id=%d"
			, TABLE_CHAMPIONSHIPTEAM
			, teamId
			);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		if(!qRes->next())
		{
			res = UDF_E_NOTFOUND;
			break;
		}

		startNum = qRes->getUInt("start_num");
		res = UDF_OK;
	}while(0);

	return res;
}

long GetTourCategoryId(unsigned int tourId, unsigned int& catId)
{
	long res = UDF_E_FAIL;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		sprintf(query, "select cs_cat_id `id` from %s where id=%d"
			, TABLE_CHAMPIONSHIPTOUR
			, tourId
			);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		if(!qRes->next())
		{
			res = UDF_E_NOTFOUND;
			break;
		}

		catId = qRes->getUInt("id");
		res = UDF_OK;
	}while(0);

	return res;
}

long GetTourMarks(unsigned int tourId, const tUIList& judges, tTourMarksList& marks, bool final /*= false*/)
{
	long res = UDF_E_FAIL;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;
		std::string			sQuery;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		/*
		select d.id `id`, d.start_number `sNum`, IFNULL(j1.mark,0)+IFNULL(j2.mark,0)+IFNULL(j3.mark,0) `sum`, IFNULL(j1.mark,0), IFNULL(j2.mark,0), IFNULL(j3.mark,0) from championship_team d
		-- ______________________________________^_________________^_________________^________________________^__________________^__________________^_________________________________________
		-- dynamicaly formed
		left join (select cjm1.team_id `team_id`, cjm1.mark `mark` from championship_judges_mark cjm1 where cjm1.tour_id=8 and cjm1.judge_id=55) j1 on j1.team_id=d.id
		left join (select cjm2.team_id `team_id`, cjm2.mark `mark` from championship_judges_mark cjm2 where cjm2.tour_id=8 and cjm2.judge_id=56) j2 on j2.team_id=d.id
		left join (select cjm3.team_id `team_id`, cjm3.mark `mark` from championship_judges_mark cjm3 where cjm3.tour_id=8 and cjm3.judge_id=57) j3 on j3.team_id=d.id
		order by sum desc
		*/
		sQuery = "select d.id `id`, d.start_number `sNum`, ";
		std::string sum;
		std::string mark;
		std::string join;
		int n = 0;
		int len = judges.size();

		for(tUIListCIt jud = judges.begin(); jud != judges.end(); jud++, n++)
		{
			sprintf(query, "ifnull(j%d.mark, 0)", n);
			sum += query;

			sprintf(query, "ifnull(j%d.mark, 0) `jm%d`", n, n);
			mark += query;
			if(n != len-1)
			{
				sum += " + ";
				mark += ", ";
			}

			unsigned int j = *jud;
			sprintf(query, " left join (select cjm%d.team_id `team_id`, cjm%d.mark `mark` from %s cjm%d "
				"where cjm%d.tour_id=%d and cjm%d.judge_id=%d) j%d on j%d.team_id=d.id  "
				, n, n
				, TABLE_CHAMPIONSHIPJUDGESMARK
				, n, n
				, tourId
				, n
				, j
				, n, n
				);
			join += query;
		}

		sQuery += sum+" `sum`,";
		sprintf(query, " from %s d ", TABLE_CHAMPIONSHIPTEAM);
		sQuery += mark + query;
		sQuery += join;
		sprintf(query, " inner join (select ctc.team_id `team_id` "
			"from %s ctc inner join %s cst"
			" on ctc.category_id=cst.cs_cat_id and cst.id=%d) a"
			" on d.id=a.team_id "
			, TABLE_CHAMPIONSHIPTEAMCATEGORIES
			, TABLE_CHAMPIONSHIPTOUR
			, tourId
			);
		sQuery += query;

		unsigned int prevTourId = 0;
		if(UDF_OK == GetPrevTourId(tourId, prevTourId))
		{
			sprintf(query, "inner join %s tp on tp.team_id = d.id and tp.tour_id=%d "
			, TABLE_CHAMPIONSHIPTOURPASS
			, prevTourId
			);

			sQuery += query;
		}
		if(!final)
			sQuery += "order by sum desc, sNum, id ";
		else
			sQuery += "order by sNum, id ";

		qRes = pCon->ExecuteQuery(sQuery);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		marks.clear();
		while(qRes->next())
		{
			tTourMarks tourMarks = {0};
			tourMarks.id = qRes->getUInt("id");
			tourMarks.startNum = qRes->getUInt("sNum");
			tourMarks.sum = qRes->getInt("sum");
			tourMarks.marksList.clear();

			int j = 0;
			for(j = 0; j < len; ++j)
			{
				sprintf(query, "jm%d", j);
				tourMarks.marksList.push_back(qRes->getInt(query));
			}
			marks.push_back(tourMarks);
		}

		res = UDF_OK;
	}while(0);

	return res;
}

bool GetTeamPassTour(unsigned int teamId, unsigned int tourId)
{
	bool res = false;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			break;
		}
		// select t1.start_number `start_num` from %s t1 where t1.id=%d
		sprintf(query, "select id from %s where tour_id=%d and team_id=%d"
			, TABLE_CHAMPIONSHIPTOURPASS
			, tourId
			, teamId
			);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			break;
		}

		if(!qRes->next())
		{
			break;
		}

		res = true;
	}while(0);

	return res;
}

long SetTeamPassTour(unsigned int teamId, unsigned int tourId, bool pass)
{
	long res = false;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		if(pass)
		{
			// insert into %s(`tour_id`,`team_id`) values(%d, %d)
			sprintf(query, "insert into %s(`tour_id`,`team_id`) values(%d, %d)"
				, TABLE_CHAMPIONSHIPTOURPASS
				, tourId
				, teamId
				);
		}
		else
		{
			sprintf(query, "delete from %s where tour_id=%d and team_id=%d"
				, TABLE_CHAMPIONSHIPTOURPASS
				, tourId
				, teamId
				);
		}

		res = pCon->Execute(query);

	}while(0);

	return res;
}

long GetTourTeams(unsigned int catId, unsigned int tourId, tUIList& teamsList)
{
	long res = UDF_E_FAIL;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		/*
		 * 1. Get previous tour
		 * 2. If none return GetCategoryTeams
		 *    else return list of teams from previous tour that is listed in cs_tour_pass table
		 */

		// Get category tours
		if(0 != tourId)
		{
			// Get previous tour in cat
			// select t.id `id` from championship_tours t inner join (select ct.type_id `tpid` from championship_tours ct where ct.id=3) c on t.cs_cat_id=36 and t.type_id>c.tpid order by t.type_id limit 1
			sprintf(query, "select t.id `id` from %s t"
				" inner join (select ct.type_id `tpid`, ct.cs_cat_id `cat` from %s ct"
				" where ct.id=%d) c on t.cs_cat_id=c.cat and"
				" t.type_id>c.tpid order by t.type_id limit 1"
				, TABLE_CHAMPIONSHIPTOUR
				, TABLE_CHAMPIONSHIPTOUR
				, tourId
				);
		}
		else
		{
			// Get last tour in cat
			// select t.id `id` from championship_tours t where t.cs_cat_id=36 order by t.type_id limit 1
			sprintf(query, "select t.id `id` from %s t where t.cs_cat_id=%d order by t.type_id limit 1"
				, TABLE_CHAMPIONSHIPTOUR
				, catId
				);
		}

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		unsigned int prevTour = -1;
		if(!qRes->next())
		{
			res = GetTeamsInCategory(catId, teamsList);
			break;
		}

		prevTour = qRes->getUInt("id");

		__info("Add sorting by start numbers");
		sprintf(query, "select tp.id `id`, tp.team_id `tid` from %s tp where"
			" tp.tour_id=%d"
			, TABLE_CHAMPIONSHIPTOURPASS
			, prevTour
			);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		teamsList.clear();

		while(qRes->next())
		{
			teamsList.push_back(qRes->getUInt("tid"));
		}

		res = UDF_OK;
	}while(0);

	return res;
}

long GetPrevTourId(unsigned int tourId, unsigned int& prevTourId)
{
	long res = UDF_E_FAIL;

	do
	{
		CDbConnection*		pCon = GetGlobalDbConnection();
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! pCon)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		sprintf(query, "select t.id `id` from %s t"
			" inner join (select ct.type_id `tpid`, ct.cs_cat_id `cat` from %s ct"
			" where ct.id=%d) c on t.cs_cat_id=c.cat and"
			" t.type_id>c.tpid order by t.type_id limit 1"
			, TABLE_CHAMPIONSHIPTOUR
			, TABLE_CHAMPIONSHIPTOUR
			, tourId
			);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		if(!qRes->next())
		{
			res = UDF_E_NOTFOUND;
			break;
		}

		prevTourId = qRes->getUInt("id");

		res = UDF_OK;
	}while(0);

	return res;
}

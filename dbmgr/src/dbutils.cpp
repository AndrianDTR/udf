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
	printf("Version: %d.%d\n", UDF_VERSION_MAJOR, UDF_VERSION_MINOR);
	printf("Version code name: %s\n", UDF_VERSION_NAME);
	printf("Build: %d\n", UDF_VERSION_PATCH);
	printf("Git hash: %s\n", UDF_VERSION_DESCR);
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

long GetRegisteredTeamsForCategory(unsigned int nId, int& count)
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

		sprintf(query, "select count(t2.team_id) as `count` from %s t1"
		" inner join %s t2 on t1.id=t2.category_id and t2.category_id=%d group by t1.id"
			, TABLE_CHAMPIONSHIPTEAM
			, TABLE_CHAMPIONSHIPTEAMCATEGORIES
			, nId);

		qRes = pCon->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		if(qRes->next())
			count = atoi(string(qRes->getString("count")).c_str());
		__debug("Count : %i", count);

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
		select sec_to_time(sum(tt.TT)) total from (select t1.name, sum(time_to_sec(t2.lenght)) as TT from championship_team t1 inner join (select b1.championship_id csId, b2.cs_cat_id catId from championship_blocks b1 inner join championship_block_j2c b2 on b1.id=b2.block_id and b1.id=2 group by b2.cs_cat_id) bc inner join championship_team_categories t2 on t1.id=t2.team_id and t1.championship_id=bc.csId and t2.category_id=bc.catId group by t1.name) tt
		*/
		
		sprintf(query, "select sec_to_time(sum(tt.TT)) total from"
			" (select t1.name, sum(time_to_sec(t2.lenght)) as TT from"
			" %s t1 inner join (select b1.championship_id csId,"
			" b2.cs_cat_id catId from %s b1 inner join"
			" %s b2 on b1.id=b2.block_id and b1.id=%d"
			" group by b2.cs_cat_id) bc inner join %s"
			" t2 on t1.id=t2.team_id and t1.championship_id=bc.csId and"
			" t2.category_id=bc.catId group by t1.name) tt"
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

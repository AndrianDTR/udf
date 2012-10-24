#include "tcsblocksj2c.h"

#define	TABLE	TABLE_CHAMPIONSHIPBLOCKJ2C

CCsBlockJ2CTable::CCsBlockJ2CTable(CDbConnection* pCon)
: CDbTable(pCon)
{
}

CCsBlockJ2CTable::~CCsBlockJ2CTable(void)
{
}

long CCsBlockJ2CTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};

	return Find(data, filter);
}

std::string CCsBlockJ2CTable::GetFilterString(const tDATA& filter)
{
	char 				query[MAX_QUERY_LEN] = {0};
	char 				tmp[MAX_QUERY_LEN] = {0};

	if (0 != filter.blockId)
	{
		sprintf(tmp, "%sand `block_id` like %d ", query, filter.blockId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter.csJudgeId)
	{
		sprintf(tmp, "%sand `cs_judge_id` like %d ", query, filter.csJudgeId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}
	
	if (0 != filter.csCatId)
	{
		sprintf(tmp, "%sand `cs_cat_id` like %d ", query, filter.csCatId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	return string(query);
}


long CCsBlockJ2CTable::Find(tTableMap& data, const tDATA& filter)
{
	long res = UDF_E_FAIL;

	do
	{
		std::string 		szQuery;
		std::string 		szFilter;
		sql::ResultSet*		qRes = NULL;

		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		szFilter = GetFilterString(filter);
		szQuery = GetQuery(TABLE, szFilter);
		qRes = m_pConnection->ExecuteQuery(szQuery);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		data.clear();

		while( qRes && qRes->next())
		{
			tDATA el = {0};

			el.id = qRes->getUInt("id");
			el.blockId = qRes->getUInt("block_id");
			el.csJudgeId = qRes->getUInt("cs_judge_id");
			el.csCatId = qRes->getUInt("cs_cat_id");

			data.insert(make_pair(el.id, el));
		}

		res = UDF_OK;
	}while(0);

	return res;
}

long CCsBlockJ2CTable::AddRow(tDATA& rec)
{
	long res = UDF_E_FAIL;

	do
	{
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		sprintf(query, "insert into %s(`block_id`,`cs_judge_id`, `cs_cat_id`) values(%d, %d, %d)"
			, TABLE
			, rec.blockId
			, rec.csJudgeId
			, rec.csCatId
			);
		res = m_pConnection->Execute(query);

		rec.id = m_pConnection->GetLastInsertId();
	}while(0);

	return res;
}

long CCsBlockJ2CTable::DelRow(unsigned int nId)
{
	long res = UDF_E_FAIL;

	do
	{
		char query[MAX_QUERY_LEN] = {0};
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		sprintf(query, "delete from %s where id = %d", TABLE, nId);
		res = m_pConnection->Execute(query);
	}while(0);

	return res;
}

long CCsBlockJ2CTable::GetRow(unsigned int nId, tDATA& data)
{
	long res = UDF_E_FAIL;

	do
	{
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;

		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		sprintf(query, "select * from %s where id = %d", TABLE, nId);
		qRes = m_pConnection->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}
		qRes->next();
		data.id = qRes->getUInt("id");
		data.blockId = qRes->getUInt("block_id");
		data.csJudgeId = qRes->getUInt("cs_judge_id");
		data.csCatId = qRes->getUInt("cs_cat_id");

		res = UDF_OK;
	}while(0);

	return res;
}

long CCsBlockJ2CTable::UpdateRow(unsigned int nId, const tDATA& data)
{
	long res = UDF_E_FAIL;

	do
	{
		char 				query[MAX_QUERY_LEN] = {0};
		char 				tmp[MAX_QUERY_LEN] = {0};
		bool 				useFilter = false;

		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		if (0 != data.blockId)
		{
			sprintf(tmp, "%s `block_id` = %d,", query, data.blockId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (0 != data.csJudgeId)
		{
			sprintf(tmp, "%s `cs_judge_id` = %d,", query, data.csJudgeId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (0 != data.csCatId)
		{
			sprintf(tmp, "%s `cs_cat_id` = %d,", query, data.csCatId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if(useFilter)
		{
			sprintf(tmp, "update %s set %s `id`=%d where `id`=%d", TABLE, query, nId, nId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			res = m_pConnection->Execute(query);
		}

	}while(0);

	return res;
}

long CCsBlockJ2CTable::FindId(unsigned int& id, const tDATA& filter)
{
	long res = UDF_E_FAIL;

	do
	{
		std::string 		szQuery;
		std::string 		szFilter;
		sql::ResultSet*		qRes = NULL;

		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		szFilter = GetFilterString(filter) + " limit 1";
		szQuery = GetQuery(TABLE, szFilter);
		qRes = m_pConnection->ExecuteQuery(szQuery);
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
			
		id = qRes->getUInt("id");

		res = UDF_OK;
	}while(0);

	return res;
}
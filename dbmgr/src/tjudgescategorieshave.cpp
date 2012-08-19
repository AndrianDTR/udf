
#include "stdio.h"

#include "dberrors.h"
#include "tjudgescategorieshave.h"

#define	TABLE	TABLE_JUDGESCATEGORIESHAVE

CJudgesCategoriesHaveTable::CJudgesCategoriesHaveTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CJudgesCategoriesHaveTable::~CJudgesCategoriesHaveTable(void)
{
}

long CJudgesCategoriesHaveTable::GetTable(tTableSet** data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CJudgesCategoriesHaveTable::Find(tTableSet** data, const tDATA& filter)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[MAX_QUERY_LEN] = {0};
		char 				tmp[MAX_QUERY_LEN] = {0};
		tTableSet*			table = NULL;
		sql::ResultSet*		qRes = NULL;
		bool 				useFilter = false;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		table = new tTableSet();
		if(!table)
		{
			res = UDF_E_NOMEMORY;
			break;
		}
		
		if (filter.judgeId != -1)
		{
			sprintf(tmp, "%sand `judge_id` like %d ", query, filter.judgeId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (filter.judCatId != -1)
		{
			sprintf(tmp, "%sand `cat_id` like %d ", query, filter.judCatId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if(useFilter)
		{
			sprintf(tmp, "select * from %s where 1=1 %s", TABLE, query);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
		}
		else
		{
			sprintf(query, "select * from %s", TABLE);
		}
		
		qRes = m_pConnection->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}
		
		table->clear();
		
		while( qRes && qRes->next())
		{
			tDATA el = {0};
			
			el.judgeId = qRes->getUInt(1);
			el.judCatId = qRes->getUInt(2);
		
			table->insert(el);
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CJudgesCategoriesHaveTable::AddRow(tDATA& rec)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[500] = {0};
		sql::ResultSet*		qRes = NULL;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		sprintf(query, "insert into %s(%d, %d)"
			, TABLE
			, rec.judgeId
			, rec.judCatId);
		m_pConnection->Execute(query);
		
		//rec.id = m_pConnection->GetLastInsertId();
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CJudgesCategoriesHaveTable::DelRow(unsigned int nId)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char query[500] = {0};
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		sprintf(query, "delete from %s where id = %d", TABLE, nId);
		m_pConnection->Execute(query);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CJudgesCategoriesHaveTable::GetRow(unsigned int nId, tDATA& data)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[500] = {0};
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
		data.judgeId = qRes->getUInt(1);
		data.judCatId = qRes->getUInt(2);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

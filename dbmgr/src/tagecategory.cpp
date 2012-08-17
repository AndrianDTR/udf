
#include "stdio.h"

#include "dberrors.h"
#include "tagecategory.h"

CAgeCategoryTable::CAgeCategoryTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CAgeCategoryTable::~CAgeCategoryTable(void)
{
}

long CAgeCategoryTable::GetTable(tAgeCategoryMap** data)
{
	long res = UDF_E_FAIL;
	
	do
	{
		tAgeCategoryMap*	table = NULL;
		sql::ResultSet*		qRes = NULL;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		table = new tAgeCategoryMap();
		if(!table)
		{
			res = UDF_E_NOMEMORY;
			break;
		}
		
		qRes = m_pConnection->ExecuteQuery("select * from age_category");
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}
		
		table->clear();
		
		while( qRes && qRes->next())
		{
			tDATA el = {0};
			
			el.id = qRes->getInt(1);
			el.descr = qRes->getString(2);
		
			table->insert(make_pair(el.id, el));
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CAgeCategoryTable::Find(tAgeCategoryMap** data, const tDATA& filter)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char query[500] = {0};
		tAgeCategoryMap*	table = NULL;
		sql::ResultSet*		qRes = NULL;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		table = new tAgeCategoryMap();
		if(!table)
		{
			res = UDF_E_NOMEMORY;
			break;
		}
		
		sprintf(query, "select * from age_category where descr like '%%%s%%'", filter.descr.c_str());
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
			
			el.id = qRes->getInt(1);
			el.descr = qRes->getString(2);
		
			table->insert(make_pair(el.id, el));
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CAgeCategoryTable::AddRow(tDATA& rec)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char query[500] = {0};
		sql::ResultSet*		qRes = NULL;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		sprintf(query, "insert into age_category(`descr`) values('%s')", rec.descr.c_str());
		m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CAgeCategoryTable::DelRow(unsigned int nId)
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
		
		sprintf(query, "delete from age_category where id = %d", nId);
		m_pConnection->Execute(query);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CAgeCategoryTable::GetRow(unsigned int nId, tDATA& data)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char query[500] = {0};
		sql::ResultSet*		qRes = NULL;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		sprintf(query, "select * from age_category where id = %d", nId);
		qRes = m_pConnection->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}
		qRes->next();
		data.id = qRes->getInt(1);
		data.descr = qRes->getString(2);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

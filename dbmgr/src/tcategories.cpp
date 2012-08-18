
#include "stdio.h"

#include "dberrors.h"
#include "tcategories.h"

#define	TABLE	TABLE_CATEGORIES

CCategoriesTable::CCategoriesTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CCategoriesTable::~CCategoriesTable(void)
{
}

long CCategoriesTable::GetTable(tTableMap** data)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char				query[500] = {0};
		tTableMap*		table = NULL;
		sql::ResultSet*		qRes = NULL;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		table = new tTableMap();
		if(!table)
		{
			res = UDF_E_NOMEMORY;
			break;
		}
		
		sprintf(query, "select * from %s", TABLE);
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
			
			el.id = qRes->getUInt64(1);
			el.dance = qRes->getUInt(2);
			el.liga = qRes->getInt(3);
			el.gender = qRes->getInt(4);
		
			table->insert(make_pair(el.id, el));
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CCategoriesTable::Find(tTableMap** data, const tDATA& filter)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[500] = {0};
		tTableMap*		table = NULL;
		sql::ResultSet*		qRes = NULL;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		table = new tTableMap();
		if(!table)
		{
			res = UDF_E_NOMEMORY;
			break;
		}
		
		sprintf(query, "select * from %s where dance like '%%%ul%%' or liga like '%%%ul%%' or gender like '%%%ul%%'", 
		TABLE, filter.dance, filter.liga, filter.gender);
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
			
			el.id = qRes->getUInt64(1);
			el.dance = qRes->getUInt(2);
			el.liga = qRes->getInt(3);
			el.gender = qRes->getInt(4);
		
			table->insert(make_pair(el.id, el));
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CCategoriesTable::AddRow(tDATA& rec)
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
		
		sprintf(query, "insert into %s(`dance`,`liga`,`gender`) values(%ul, %ul, %ul)", 
			TABLE, rec.dance, rec.liga, rec.gender);
		m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CCategoriesTable::DelRow(unsigned long nId)
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

long CCategoriesTable::GetRow(unsigned long nId, tDATA& data)
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
		data.id = qRes->getUInt64(1);
		data.dance = qRes->getUInt(2);
		data.liga = qRes->getInt(3);
		data.gender = qRes->getInt(4);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

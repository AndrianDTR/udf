
#include "stdio.h"

#include "dberrors.h"
#include "tchampionshipteam.h"

#define	TABLE	TABLE_CHAMPIONSHIPTEAM

CChampionshipTeamsTable::CChampionshipTeamsTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CChampionshipTeamsTable::~CChampionshipTeamsTable(void)
{
}

long CChampionshipTeamsTable::GetTable(tTableSet** data)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char				query[500] = {0};
		tTableSet*			table = NULL;
		sql::ResultSet*		qRes = NULL;
		
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
			
			el.id = qRes->getUInt(1);
			el.dancerId = qRes->getUInt(2);
			el.championshipId = qRes->getUInt(3);
			el.compositionName = qRes->getString(4);
			el.startNumber = qRes->getUInt(5);
		
			table->insert(el);
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipTeamsTable::Find(tTableSet** data, const tDATA& filter)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[500] = {0};
		tTableSet*			table = NULL;
		sql::ResultSet*		qRes = NULL;
		
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
		
		sprintf(query, "select * from %s where (``=%d and ``=%d and ``=%d) \
or `` like %s or ``=%d"
		, TABLE
		, filter.id
		, filter.dancerId
		, filter.championshipId
		, filter.compositionName.c_str()
		, filter.startNumber);
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
			
			el.id = qRes->getUInt(1);
			el.dancerId = qRes->getUInt(2);
			el.championshipId = qRes->getUInt(3);
			el.compositionName = qRes->getString(4);
			el.startNumber = qRes->getUInt(5);
		
			table->insert(el);
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipTeamsTable::AddRow(tDATA& rec)
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
		
		sprintf(query, "insert into %s(%d,%d,%d,'%s',%d)"
		, TABLE
		, rec.id
		, rec.dancerId
		, rec.championshipId
		, rec.compositionName.c_str()
		, rec.startNumber);
		m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipTeamsTable::DelRow(unsigned int nId)
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

long CChampionshipTeamsTable::GetRow(unsigned int nId, tDATA& data)
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
		data.id = qRes->getUInt(1);
		data.dancerId = qRes->getUInt(2);
		data.championshipId = qRes->getUInt(3);
		data.compositionName = qRes->getString(4);
		data.startNumber = qRes->getUInt(5);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

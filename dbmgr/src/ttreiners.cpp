
#include "stdio.h"

#include "dberrors.h"
#include "ttreiners.h"

#define	TABLE	TABLE_TRAINERS

CTarinersTable::CTarinersTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CTarinersTable::~CTarinersTable(void)
{
}

long CTarinersTable::GetTable(tTableMap** data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CTarinersTable::Find(tTableMap** data, const tDATA& filter)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[500] = {0};
		tTableMap*			table = NULL;
		sql::ResultSet*		qRes = NULL;
		bool 				useFilter = false;
		
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
		
		if (!filter.name.empty())
		{
			sprintf(query, "%sand `name` like '%%%s%%' ", query, filter.name.c_str());
			useFilter = true;
		}
		
		if (!filter.clubId != -1)
		{
			sprintf(query, "%sand `club_id` = %d ", query, filter.clubId);
			useFilter = true;
		}
		
		if (!filter.phone.empty())
		{
			sprintf(query, "%sand `phone` like '%%%s%%' ", query, filter.phone.c_str());
			useFilter = true;
		}
		
		if (!filter.email.empty())
		{
			sprintf(query, "%sand `email` like '%%%s%%' ", query, filter.email.c_str());
			useFilter = true;
		}
		
		if (!filter.contactInfo.empty())
		{
			sprintf(query, "%sand `cantact_info` like '%%%s%%' ", query, filter.contactInfo.c_str());
			useFilter = true;
		}
		
		if (!filter.pay_date.empty())
		{
			sprintf(query, "%sand `pay_date` like '%%%s%%' ", query, filter.pay_date.c_str());
			useFilter = true;
		}
		
		if (!filter.exp_date.empty())
		{
			sprintf(query, "%sand `expire_date` like '%%%s%%' ", query, filter.exp_date.c_str());
			useFilter = true;
		}
		
		if(useFilter)
		{
			sprintf(query, "select * from %s where 1=1 %s", TABLE, query);
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
			
			el.id = qRes->getUInt(1);
			el.clubId = qRes->getUInt(2);
			el.name = qRes->getString(3);
			el.bd = qRes->getString(4);
			el.cityId = qRes->getUInt(5);
			el.phone = qRes->getString(6);
			el.contactInfo = qRes->getString(7);
			el.email = qRes->getString(8);
			el.pay_date = qRes->getString(9);
			el.exp_date = qRes->getString(10);
			
			table->insert(make_pair(el.id, el));
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CTarinersTable::AddRow(tDATA& rec)
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
		
		sprintf(query, "insert into %s(%d,'%s','%s',%d,'%s','%s','%s','%s','%s')"
		, TABLE
		, rec.clubId
		, rec.name.c_str()
		, rec.bd.c_str()
		, rec.cityId
		, rec.phone.c_str()
		, rec.contactInfo.c_str()
		, rec.email.c_str()
		, rec.pay_date.c_str()
		, rec.exp_date.c_str());
		m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CTarinersTable::DelRow(unsigned int nId)
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

long CTarinersTable::GetRow(unsigned int nId, tDATA& data)
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
		data.clubId = qRes->getUInt(2);
		data.name = qRes->getString(3);
		data.bd = qRes->getString(4);
		data.cityId = qRes->getUInt(5);
		data.phone = qRes->getString(6);
		data.contactInfo = qRes->getString(7);
		data.email = qRes->getString(8);
		data.pay_date = qRes->getString(9);
		data.exp_date = qRes->getString(10);
			
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

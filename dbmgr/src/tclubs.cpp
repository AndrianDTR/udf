
#include "stdio.h"

#include "dberrors.h"
#include "tclubs.h"

#define	TABLE	TABLE_CLUBS

CClubsTable::CClubsTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CClubsTable::~CClubsTable(void)
{
}

long CClubsTable::GetTable(tTableMap** data)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char				query[500] = {0};
		tTableMap*	table = NULL;
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

			el.id = qRes->getUInt(1);
			el.name = qRes->getString(2);
			el.city = qRes->getUInt(3);
			el.login = qRes->getString(4);
			el.pass = qRes->getString(5);
			el.email = qRes->getString(6);
			el.contacts = qRes->getString(7);
			el.web = qRes->getString(8);
			el.location = qRes->getString(9);
			el.pay_date = qRes->getString(10);
			el.exp_date = qRes->getString(11);
			el.director = qRes->getString(12);
			el.director_bd = qRes->getString(13);
			el.director_phone = qRes->getString(14);
			el.director_email = qRes->getString(15);
			
			table->insert(make_pair(el.id, el));
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CClubsTable::Find(tTableMap** data, const tDATA& filter)
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
		
		sprintf(query, "select * from %s where `name` like '%%%s%%' or `city` = %d or `director_name` like '%%%s%%'"
			, TABLE
			, filter.name.c_str()
			, filter.city
			, filter.director.c_str());
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
			el.name = qRes->getString(2);
			el.city = qRes->getUInt(3);
			el.login = qRes->getString(4);
			el.pass = qRes->getString(5);
			el.email = qRes->getString(6);
			el.contacts = qRes->getString(7);
			el.web = qRes->getString(8);
			el.location = qRes->getString(9);
			el.pay_date = qRes->getString(10);
			el.exp_date = qRes->getString(11);
			el.director = qRes->getString(12);
			el.director_bd = qRes->getString(13);
			el.director_phone = qRes->getString(14);
			el.director_email = qRes->getString(15);
		
			table->insert(make_pair(el.id, el));
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CClubsTable::AddRow(tDATA& rec)
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
		
		sprintf(query, "insert into %s('%s',%d,'%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')"
			, TABLE
			, rec.name.c_str()
			, rec.city
			, rec.login.c_str()
			, rec.pass.c_str()
			, rec.email.c_str()
			, rec.contacts.c_str()
			, rec.web.c_str()
			, rec.location.c_str()
			, rec.pay_date.c_str()
			, rec.exp_date.c_str()
			, rec.director.c_str()
			, rec.director_bd.c_str()
			, rec.director_phone.c_str()
			, rec.director_email.c_str());
		m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CClubsTable::DelRow(unsigned int nId)
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

long CClubsTable::GetRow(unsigned int nId, tDATA& data)
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
		data.name = qRes->getString(2);
		data.city = qRes->getUInt(3);
		data.login = qRes->getString(4);
		data.pass = qRes->getString(5);
		data.email = qRes->getString(6);
		data.contacts = qRes->getString(7);
		data.web = qRes->getString(8);
		data.location = qRes->getString(9);
		data.pay_date = qRes->getString(10);
		data.exp_date = qRes->getString(11);
		data.director = qRes->getString(12);
		data.director_bd = qRes->getString(13);
		data.director_phone = qRes->getString(14);
		data.director_email = qRes->getString(15);

		res = UDF_OK;
	}while(0);
	
	return res;
}

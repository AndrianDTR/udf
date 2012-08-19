
#include "stdio.h"

#include "dberrors.h"
#include "tdancers.h"

#define	TABLE	TABLE_DANCERS

CDancersTable::CDancersTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CDancersTable::~CDancersTable(void)
{
}

long CDancersTable::GetTable(tTableMap** data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CDancersTable::Find(tTableMap** data, const tDATA& filter)
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
		
		if (!filter.trainerId != -1)
		{
			sprintf(query, "%sand `trener_id` = %d ", query, filter.trainerId);
			useFilter = true;
		}
		
		if (!filter.regBook.empty())
		{
			sprintf(query, "%sand `reg_book_num` like '%%%s%%' ", query, filter.regBook.c_str());
			useFilter = true;
		}
		
		if (!filter.raiting != -1)
		{
			sprintf(query, "%sand `raiting` = %d ", query, filter.raiting);
			useFilter = true;
		}
		
		if (!filter.liga != -1)
		{
			sprintf(query, "%sand `liga` = %d ", query, filter.liga);
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
			el.trainerId = qRes->getUInt(3);
			el.regBook = qRes->getString(4);
			el.name = qRes->getString(5);
			el.raiting = qRes->getUInt(6);
			el.liga = qRes->getInt(7);
			el.bd = qRes->getString(8);
			el.gender = qRes->getInt(9);
			el.pay_date = qRes->getString(10);
			el.exp_date = qRes->getString(11);
			el.reg_date = qRes->getString(12);
		
			table->insert(make_pair(el.id, el));
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CDancersTable::AddRow(tDATA& rec)
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
		
		sprintf(query, "insert into %s(`club_id`,`trener_id`,`reg_book_num`,\
		`name`,`raiting`,`liga`,`bd`,`gender`,`pay_date`,`expire_date`) \
		values(%d,%d,'%s','%s',%d,%d,'%s',%d,'%s','%s','%s')"
			, TABLE
			, rec.clubId
			, rec.trainerId
			, rec.regBook.c_str()
			, rec.name.c_str()
			, rec.raiting
			, rec.liga
			, rec.bd.c_str()
			, rec.gender
			, rec.pay_date.c_str()
			, rec.exp_date.c_str());
		m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CDancersTable::DelRow(unsigned int nId)
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

long CDancersTable::GetRow(unsigned int nId, tDATA& data)
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
		data.trainerId = qRes->getUInt(3);
		data.regBook = qRes->getString(4);
		data.name = qRes->getString(5);
		data.raiting = qRes->getUInt(6);
		data.liga = qRes->getInt(7);
		data.bd = qRes->getString(8);
		data.liga = qRes->getInt(9);
		data.bd = qRes->getString(10);
		data.bd = qRes->getString(11);
		data.bd = qRes->getString(12);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

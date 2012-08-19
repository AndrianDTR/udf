
#include "stdio.h"

#include "dberrors.h"
#include "tjudges.h"

#define	TABLE	TABLE_JUDGES

CJudgesTable::CJudgesTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CJudgesTable::~CJudgesTable(void)
{
}

long CJudgesTable::GetTable(tTableMap** data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CJudgesTable::Find(tTableMap** data, const tDATA& filter)
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
		
		if (!filter.countryId != -1)
		{
			sprintf(query, "%sand `country` = %d ", query, filter.countryId);
			useFilter = true;
		}
		
		if (!filter.cityId != -1)
		{
			sprintf(query, "%sand `city` = %d ", query, filter.cityId);
			useFilter = true;
		}
		
		if (!filter.attestationInfo.empty())
		{
			sprintf(query, "%sand `attestation_info` like '%%%s%%' ", query, filter.attestationInfo.c_str());
			useFilter = true;
		}
		
		if (!filter.clubId != -1)
		{
			sprintf(query, "%sand `club` = %d ", query, filter.clubId);
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
			el.name = qRes->getString(2);
			el.countryId = qRes->getUInt(3);
			el.cityId = qRes->getUInt(4);
			el.clubId = qRes->getUInt(5);
			el.attestationInfo = qRes->getString(6);
			el.pay_date = qRes->getString(7);
			el.exp_date = qRes->getString(8);
		
			table->insert(make_pair(el.id, el));
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CJudgesTable::AddRow(tDATA& rec)
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
		
		sprintf(query, "insert into %s(`name`,`country`,`city`,`club`,\
		`attestation_info`,`pay_date`,`expire_date`) values('%s')"
			, TABLE
			, rec.name.c_str()
			, rec.countryId
			, rec.cityId
			, rec.clubId
			, rec.attestationInfo.c_str()
			, rec.pay_date.c_str()
			, rec.exp_date.c_str());
		m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CJudgesTable::DelRow(unsigned int nId)
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

long CJudgesTable::GetRow(unsigned int nId, tDATA& data)
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
		data.countryId = qRes->getUInt(3);
		data.cityId = qRes->getUInt(4);
		data.clubId = qRes->getUInt(5);
		data.attestationInfo = qRes->getString(6);
		data.pay_date = qRes->getString(7);
		data.exp_date = qRes->getString(8);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

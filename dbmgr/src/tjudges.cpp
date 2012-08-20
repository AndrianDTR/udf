
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
		char 				query[MAX_QUERY_LEN] = {0};
		char 				tmp[MAX_QUERY_LEN] = {0};
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
			sprintf(tmp, "%sand `name` like '%%%s%%' ", query, filter.name.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.countryId != -1)
		{
			sprintf(tmp, "%sand `country` = %d ", query, filter.countryId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.cityId != -1)
		{
			sprintf(tmp, "%sand `city` = %d ", query, filter.cityId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.attestationInfo.empty())
		{
			sprintf(tmp, "%sand `attestation_info` like '%%%s%%' ", query, filter.attestationInfo.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.clubId != -1)
		{
			sprintf(tmp, "%sand `club` = %d ", query, filter.clubId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.pay_date.empty())
		{
			sprintf(tmp, "%sand `pay_date` like '%%%s%%' ", query, filter.pay_date.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.exp_date.empty())
		{
			sprintf(tmp, "%sand `expire_date` like '%%%s%%' ", query, filter.exp_date.c_str());
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
		char 				query[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		sprintf(query, "insert into %s(`name`,`country`,`city`,`club`,\
		`attestation_info`,`pay_date`,`expire_date`) values('%s', %d, %d, %d, '%s', '%s', '%s')"
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
		char query[MAX_QUERY_LEN] = {0};
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

long CJudgesTable::UpdateRow(unsigned int nId, const tDATA& data)
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
		/*
			el.cityId = qRes->getUInt(4);
			el.clubId = qRes->getUInt(5);
			el.attestationInfo = qRes->getString(6);
			el.pay_date = qRes->getString(7);
			el.exp_date = qRes->getString(8);
		
		*/
		if (data.countryId != -1)
		{
			sprintf(tmp, "%s `country` = %d,", query, data.countryId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (data.cityId != -1)
		{
			sprintf(tmp, "%s `city` = %d,", query, data.cityId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (data.clubId != -1)
		{
			sprintf(tmp, "%s `club` = %d,", query, data.clubId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.name.empty())
		{
			sprintf(tmp, "%s `name` = '%s',", query, data.name.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.attestationInfo.empty())
		{
			sprintf(tmp, "%s `attestation_info` = '%s',", query, data.attestationInfo.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.pay_date.empty())
		{
			sprintf(tmp, "%s `pay_date` = '%s',", query, data.pay_date.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.pay_date.empty())
		{
			sprintf(tmp, "%s `expire_date` = '%s',", query, data.pay_date.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if(useFilter)
		{
			sprintf(tmp, "update %s set %s `id`=%d where `id`=%d", TABLE, query, nId, nId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			m_pConnection->Execute(query);
		}
		
		res = UDF_OK;
	}while(0);
	
	return res;
}
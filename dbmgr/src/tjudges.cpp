
#include "stdio.h"

#include "dberrors.h"
#include "dbutils.h"
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

long CJudgesTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CJudgesTable::Find(tTableMap& data, const tDATA& filter)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[MAX_QUERY_LEN] = {0};
		char 				tmp[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;
		bool 				useFilter = false;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		if (!filter.name.empty())
		{
			sprintf(tmp, "%sand `name` like '%%%s%%' ", query, filter.name.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.practicer)
		{
			sprintf(tmp, "%sand `practicer` = '%c' ", query, filter.practicer);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.cityId)
		{
			sprintf(tmp, "%sand `city` = %d ", query, filter.cityId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.phone.empty())
		{
			sprintf(tmp, "%sand `phone` like '%%%s%%' ", query, filter.phone.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.email.empty())
		{
			sprintf(tmp, "%sand `email` like '%%%s%%' ", query, filter.email.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.additionalInfo.empty())
		{
			sprintf(tmp, "%sand `aditional_info` like '%%%s%%' ", query, filter.attestationInfo.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.attestationInfo.empty())
		{
			sprintf(tmp, "%sand `attestation_info` like '%%%s%%' ", query, filter.attestationInfo.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.pay_date)
		{
			sprintf(tmp, "%sand `pay_date` like '%%%s%%' ", query, date2str(filter.pay_date).c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.exp_date)
		{
			sprintf(tmp, "%sand `expire_date` like '%%%s%%' ", query, date2str(filter.exp_date).c_str());
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
		
		data.clear();
		
		while( qRes && qRes->next())
		{
			tDATA el = {0};
			
			el.id = qRes->getUInt(1);
			el.name = qRes->getString(2);
			el.cityId = qRes->getUInt(3);
			el.practicer = qRes->getString(4)[0];
			el.attestationInfo = qRes->getString(5);
			el.phone = qRes->getString(6);
			el.email = qRes->getString(7);
			el.additionalInfo = qRes->getString(8);
			el.pay_date = str2date(qRes->getString(9));
			el.exp_date = str2date(qRes->getString(10));
		
			data.insert(make_pair(el.id, el));
		}
		
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
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		sprintf(query, "insert into %s(`name`,`city`,`practicer`,`attestation_info`,"
			"`phone`,`email`,`additional_info`,`pay_date`,`expire_date`)"
			"values('%s', %d, '%c', '%s', '%s', '%s', '%s', '%s', '%s')"
			, TABLE
			, rec.name.c_str()
			, rec.cityId
			, rec.practicer
			, rec.attestationInfo.c_str()
			, rec.phone.c_str()
			, rec.email.c_str()
			, rec.additionalInfo.c_str()
			, date2str(rec.pay_date).c_str()
			, date2str(rec.exp_date).c_str());
		res = m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
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
		res = m_pConnection->Execute(query);
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
		data.cityId = qRes->getUInt(3);
		data.practicer = qRes->getString(4)[0];
		data.attestationInfo = qRes->getString(5);
		data.phone = qRes->getString(6);
		data.email = qRes->getString(7);
		data.additionalInfo = qRes->getString(8);
		data.pay_date = str2date(qRes->getString(9));
		data.exp_date = str2date(qRes->getString(10));
		
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
		
		if (0 != data.cityId)
		{
			sprintf(tmp, "%s `city` = %d,", query, data.cityId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != data.practicer)
		{
			sprintf(tmp, "%s `practicer` = '%c',", query, data.practicer);
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
		
		if (!data.phone.empty())
		{
			sprintf(tmp, "%s `phone` = '%s',", query, data.phone.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.email.empty())
		{
			sprintf(tmp, "%s `email` = '%s',", query, data.email.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.additionalInfo.empty())
		{
			sprintf(tmp, "%s `additional_info` = '%s',", query, data.additionalInfo.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
			
		if (0 != data.pay_date)
		{
			sprintf(tmp, "%s `pay_date` = '%s',", query, date2str(data.pay_date).c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != data.exp_date)
		{
			sprintf(tmp, "%s `expire_date` = '%s',", query, date2str(data.exp_date).c_str());
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
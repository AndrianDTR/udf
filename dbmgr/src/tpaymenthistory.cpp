

#include "dbutils.h"
#include "dberrors.h"
#include "tpaymenthistory.h"

#define	TABLE	TABLE_PAYMENTHISTORY

CPaymentHistoryTable::CPaymentHistoryTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CPaymentHistoryTable::~CPaymentHistoryTable(void)
{
}

long CPaymentHistoryTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CPaymentHistoryTable::Find(tTableMap& data, const tDATA& filter)
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
		
		if (0 != filter.personId)
		{
			sprintf(tmp, "%sand `person_id` = %d ", query, filter.personId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.type)
		{
			sprintf(tmp, "%sand `type` = %c ", query, filter.type);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0.0001f < filter.sum || -0.0001f > filter.sum)
		{
			sprintf(tmp, "%sand `sum` = %f ", query, filter.sum);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.pay_date)
		{
			sprintf(tmp, "%sand `pay_date` like '%s' ", query, date2str(filter.pay_date).c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.exp_date)
		{
			sprintf(tmp, "%sand `exp_date` like '%s' ", query, date2str(filter.exp_date).c_str());
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
			el.personId = qRes->getUInt(2);
			el.type = qRes->getString(3)[0];
			el.pay_date = str2date(qRes->getString(4));
			el.exp_date = str2date(qRes->getString(5));
			el.sum = qRes->getDouble(6);
			
			data.insert(make_pair(el.id, el));
		}
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CPaymentHistoryTable::AddRow(tDATA& rec)
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
		sprintf(query, "insert into %s(`person_id`,`type`,`pay_date`,`exp_date`,`sum`)"
		"values(%ld, %c, '%s', '%s', '%f')"
			, TABLE
			, rec.personId
			, rec.type
			, date2str(rec.pay_date).c_str()
			, date2str(rec.exp_date).c_str()
			, rec.sum);
		res = m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
	}while(0);
	
	return res;
}

long CPaymentHistoryTable::DelRow(unsigned int nId)
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

long CPaymentHistoryTable::GetRow(unsigned int nId, tDATA& data)
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
		data.personId = qRes->getUInt(2);
		data.type = qRes->getString(3)[0];
		data.pay_date = str2date(qRes->getString(4));
		data.exp_date = str2date(qRes->getString(5));
		data.sum = qRes->getDouble(6);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CPaymentHistoryTable::UpdateRow(unsigned int nId, const tDATA& data)
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
		
		if (-1 != data.personId)
		{
			sprintf(tmp, "%s `person_id` = %ld,", query, data.personId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (-1 != data.type)
		{
			sprintf(tmp, "%s `type` = %c,", query, data.type);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0.0001f < data.sum || -0.0001f > data.sum)
		{
			sprintf(tmp, "%s `sum` = '%s',", query, data.sum);
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
			sprintf(tmp, "%s `exp_date` = '%s',", query, date2str(data.exp_date).c_str());
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
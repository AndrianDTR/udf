
#include "common.h"

#include "dbutils.h"
#include "dberrors.h"
#include "tpaymenthistory.h"

#define	TABLE	TABLE_PAYMENTHISTORY

CChampionshipTable::CChampionshipTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CChampionshipTable::~CChampionshipTable(void)
{
}

long CChampionshipTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CChampionshipTable::Find(tTableMap& data, const tDATA& filter)
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
		
		if (0 != filter.date)
		{
			sprintf(tmp, "%sand `date` like '%%%s%%' ", query, date2str(filter.date).c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.exp)
		{
			sprintf(tmp, "%sand `expire` like '%%%s%%' ", query, date2str(filter.exp).c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.type)
		{
			sprintf(tmp, "%sand `type` like %c ", query, filter.type);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.personId)
		{
			sprintf(tmp, "%sand `person_id` like %d ", query, filter.personId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 < filter.sum)
		{
			sprintf(tmp, "%sand `sum` like %f ", query, filter.sum);
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
			el.date = str2date(qRes->getString(4));
			el.exp = str2date(qRes->getString(5));
			el.sum = qRes->getFloat(6);
			
			data.insert(make_pair(el.id, el));
		}
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipTable::AddRow(tDATA& rec)
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
		
		sprintf(query, "insert into %s(`person_id`, `type`, `date`, `expire`, `sum`)"
		" values(%d, %d, '%s', '%s', %f)"
		, TABLE
		, rec.personId
		, rec.type
		, date2str(rec.date).c_str()
		, date2str(rec.exp).c_str()
		, rec.sum
		);
		res = m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();

	}while(0);
	
	return res;
}

long CChampionshipTable::DelRow(unsigned int nId)
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

long CChampionshipTable::GetRow(unsigned int nId, tDATA& data)
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
		data.date = str2date(qRes->getString(4));
		data.exp = str2date(qRes->getString(5));
		data.sum = qRes->getFloat(6);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipTable::UpdateRow(unsigned int nId, const tDATA& data)
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
		
		if (0 != data.personId)
		{
			sprintf(tmp, "%sand `person_id` like %d ", query, data.personId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
				
		if (0 != data.type)
		{
			sprintf(tmp, "%s `type` = %d,", query, data.type);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != data.date)
		{
			sprintf(tmp, "%s `date` = '%s',", query, date2str(data.date).c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != data.exp)
		{
			sprintf(tmp, "%s `expire` = '%s',", query, date2str(data.exp).c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 < data.sum)
		{
			sprintf(tmp, "%s `sum` = '%f',", query, data.sum);
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


#include "stdio.h"

#include "dberrors.h"
#include "dbutils.h"
#include "ttreiners.h"

#define	TABLE	TABLE_TRAINERS

CTrainersTable::CTrainersTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CTrainersTable::~CTrainersTable(void)
{
}

long CTrainersTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CTrainersTable::Find(tTableMap& data, const tDATA& filter)
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
		
		if (0 != filter.clubId)
		{
			sprintf(tmp, "%sand `club_id` = %d ", query, filter.clubId);
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
			sprintf(tmp, "%sand `contact_info` like '%%%s%%' ", query, filter.additionalInfo.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.bd)
		{
			sprintf(tmp, "%sand `bd` like '%%%s%%' ", query, date2str(filter.bd).c_str());
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
			el.clubId = qRes->getUInt(2);
			el.name = qRes->getString(3);
			el.bd = str2date(qRes->getString(4));
			el.phone = qRes->getString(5);
			el.additionalInfo = qRes->getString(6);
			el.email = qRes->getString(7);
			el.pay_date = str2date(qRes->getString(8));
			el.exp_date = str2date(qRes->getString(9));
			
			data.insert(make_pair(el.id, el));
		}
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CTrainersTable::AddRow(tDATA& rec)
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
		
		sprintf(query, "insert into %s(`club_id`,`name`,`bd`,`phone`,`contact_info`,`email`,`pay_date`,`expire_date`) \
		values(%d, '%s', '%s', '%s', '%s', '%s', '%s', '%s')"
		, TABLE
		, rec.clubId
		, rec.name.c_str()
		, date2str(rec.bd).c_str()
		, rec.phone.c_str()
		, rec.additionalInfo.c_str()
		, rec.email.c_str()
		, date2str(rec.pay_date).c_str()
		, date2str(rec.exp_date).c_str()
		);
		
		res = m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
	}while(0);
	
	return res;
}

long CTrainersTable::DelRow(unsigned int nId)
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

long CTrainersTable::GetRow(unsigned int nId, tDATA& data)
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
		data.clubId = qRes->getUInt(2);
		data.name = qRes->getString(3);
		data.bd = str2date(qRes->getString(4));
		data.phone = qRes->getString(5);
		data.additionalInfo = qRes->getString(6);
		data.email = qRes->getString(7);
		data.pay_date = str2date(qRes->getString(8));
		data.exp_date = str2date(qRes->getString(9));
			
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CTrainersTable::UpdateRow(unsigned int nId, const tDATA& data)
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

		if (0 != data.clubId)
		{
			sprintf(tmp, "%s `club_id` = %d,", query, data.clubId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.name.empty())
		{
			sprintf(tmp, "%s `name` = '%s',", query, data.name.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != data.bd)
		{
			sprintf(tmp, "%s `bd` = '%s',", query, date2str(data.bd).c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.phone.empty())
		{
			sprintf(tmp, "%s `phone` = '%s',", query, data.phone.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.additionalInfo.empty())
		{
			sprintf(tmp, "%s `contact_info` = '%s',", query, data.additionalInfo.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.email.empty())
		{
			sprintf(tmp, "%s `email` = '%s',", query, data.email.c_str());
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
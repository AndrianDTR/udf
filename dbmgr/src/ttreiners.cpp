
#include "stdio.h"

#include "dberrors.h"
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
		
		if (!filter.contactInfo.empty())
		{
			sprintf(tmp, "%sand `contact_info` like '%%%s%%' ", query, filter.contactInfo.c_str());
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
		
		data.clear();
		
		while( qRes && qRes->next())
		{
			tDATA el = {0};
			
			el.id = qRes->getUInt(1);
			el.clubId = qRes->getUInt(2);
			el.name = qRes->getString(3);
			el.bd = qRes->getString(4);
			el.phone = qRes->getString(5);
			el.contactInfo = qRes->getString(6);
			el.email = qRes->getString(7);
			el.pay_date = qRes->getString(8);
			el.exp_date = qRes->getString(9);
			
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
		, rec.bd.c_str()
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
		m_pConnection->Execute(query);
		
		res = UDF_OK;
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
		data.bd = qRes->getString(4);
		data.phone = qRes->getString(5);
		data.contactInfo = qRes->getString(6);
		data.email = qRes->getString(7);
		data.pay_date = qRes->getString(8);
		data.exp_date = qRes->getString(9);
			
		
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

		if (data.clubId != -1)
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
		
		if (!data.bd.empty())
		{
			sprintf(tmp, "%s `bd` = '%s',", query, data.bd.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.phone.empty())
		{
			sprintf(tmp, "%s `phone` = '%s',", query, data.phone.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.contactInfo.empty())
		{
			sprintf(tmp, "%s `contact_info` = '%s',", query, data.contactInfo.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.email.empty())
		{
			sprintf(tmp, "%s `email` = '%s',", query, data.email.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.pay_date.empty())
		{
			sprintf(tmp, "%s `pay_date` = '%s',", query, data.pay_date.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.exp_date.empty())
		{
			sprintf(tmp, "%s `expire_date` = '%s',", query, data.exp_date.c_str());
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
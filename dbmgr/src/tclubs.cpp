
#include "stdio.h"

#include "dberrors.h"
#include "dbutils.h"
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

long CClubsTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CClubsTable::Find(tTableMap& data, const tDATA& filter)
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
		
		if (0 != filter.city)
		{
			sprintf(tmp, "%sand `city` like %d ", query, filter.city);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.email.empty())
		{
			sprintf(tmp, "%sand `email` like '%%%s%%' ", query, filter.email.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.contacts.empty())
		{
			sprintf(tmp, "%sand `contacts` like '%%%s%%' ", query, filter.contacts.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.web.empty())
		{
			sprintf(tmp, "%sand `web` like '%%%s%%' ", query, filter.web.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.additionalInfo.empty())
		{
			sprintf(tmp, "%sand `additional_info` like '%%%s%%' ", query, filter.additionalInfo.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.name.empty())
		{
			sprintf(tmp, "%sand `name` like '%%%s%%' ", query, filter.name.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.director.empty())
		{
			sprintf(tmp, "%sand `director_name` like '%%%s%%' ", query, filter.director.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
			
		if (0 != filter.director_bd)
		{
			sprintf(tmp, "%sand `director_bd` like '%%%s%%' ", query, date2str(filter.director_bd).c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
			
		if (!filter.director_phone.empty())
		{
			sprintf(tmp, "%sand `director_phone` like '%%%s%%' ", query, filter.director_phone.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
			
		if (!filter.director_email.empty())
		{
			sprintf(tmp, "%sand `director_email` like '%%%s%%' ", query, filter.director_email.c_str());
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
			el.city = qRes->getUInt(3);
			el.login = qRes->getString(4);
			el.pass = qRes->getString(5);
			el.email = qRes->getString(6);
			el.contacts = qRes->getString(7);
			el.web = qRes->getString(8);
			el.additionalInfo = qRes->getString(9);
			el.director = qRes->getString(10);
			el.director_bd = str2date(qRes->getString(11));
			el.director_phone = qRes->getString(12);
			el.director_email = qRes->getString(13);
		
			data.insert(make_pair(el.id, el));
		}
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CClubsTable::AddRow(tDATA& rec)
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
		
		sprintf(query, "insert into %s(`name`,`city`,`login`,`pass`,`email`,`contacts`,\
		`web`,`additional_info`,`director_name`,`director_bd`,`director_phone`,`director_email`) \
		values('%s',%d,'%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')"
			, TABLE
			, rec.name.c_str()
			, rec.city
			, rec.login.c_str()
			, rec.pass.c_str()
			, rec.email.c_str()
			, rec.contacts.c_str()
			, rec.web.c_str()
			, rec.additionalInfo.c_str()
			, rec.director.c_str()
			, date2str(rec.director_bd).c_str()
			, rec.director_phone.c_str()
			, rec.director_email.c_str());
		res = m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
	}while(0);
	
	return res;
}

long CClubsTable::DelRow(unsigned int nId)
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
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CClubsTable::GetRow(unsigned int nId, tDATA& data)
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
		data.city = qRes->getUInt(3);
		data.login = qRes->getString(4);
		data.pass = qRes->getString(5);
		data.email = qRes->getString(6);
		data.contacts = qRes->getString(7);
		data.web = qRes->getString(8);
		data.additionalInfo = qRes->getString(9);
		data.director = qRes->getString(10);
		data.director_bd =  str2date(qRes->getString(11));
		data.director_phone = qRes->getString(12);
		data.director_email = qRes->getString(13);

		res = UDF_OK;
	}while(0);
	
	return res;
}

long CClubsTable::UpdateRow(unsigned int nId, const tDATA& data)
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

		if (0 != data.city)
		{
			sprintf(tmp, "%s `city` = %d,", query, data.city);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.name.empty())
		{
			sprintf(tmp, "%s `name` = '%s',", query, data.name.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.login.empty())
		{
			sprintf(tmp, "%s `login` = '%s',", query, data.login.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.pass.empty())
		{
			sprintf(tmp, "%s `pass` = '%s',", query, data.pass.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.email.empty())
		{
			sprintf(tmp, "%s `email` = '%s',", query, data.email.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.contacts.empty())
		{
			sprintf(tmp, "%s `contacts` = '%s',", query, data.contacts.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.web.empty())
		{
			sprintf(tmp, "%s `web` = '%s',", query, data.web.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.additionalInfo.empty())
		{
			sprintf(tmp, "%s `additional_info` = '%s',", query, data.additionalInfo.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.director.empty())
		{
			sprintf(tmp, "%s `director_name` = '%s',", query, data.director.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != data.director_bd)
		{
			sprintf(tmp, "%s `director_bd` = '%s',", query, date2str(data.director_bd).c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.director_phone.empty())
		{
			sprintf(tmp, "%s `director_phone` = '%s',", query, data.director_phone.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.director_email.empty())
		{
			sprintf(tmp, "%s `director_email` = '%s',", query, data.director_email.c_str());
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
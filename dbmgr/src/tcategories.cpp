
#include "stdio.h"

#include "dberrors.h"
#include "tcategories.h"

#define	TABLE	TABLE_CATEGORIES

CCategoriesTable::CCategoriesTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CCategoriesTable::~CCategoriesTable(void)
{
}

long CCategoriesTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CCategoriesTable::Find(tTableMap& data, const tDATA& filter)
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
		
		if (0 != filter.dance)
		{
			sprintf(tmp, "%sand `dance` like %d ", query, filter.dance);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.liga)
		{
			sprintf(tmp, "%sand `liga` like %d ", query, filter.liga);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.age_category)
		{
			sprintf(tmp, "%sand `age_category` like %d ", query, filter.age_category);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.name.empty())
		{
			sprintf(tmp, "%sand `name` like '%%%s%%' ", query, filter.name.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.shortName.empty())
		{
			sprintf(tmp, "%sand `short_name` like '%%%s%%' ", query, filter.shortName.c_str());
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
			
			el.id = qRes->getUInt64(1);
			el.dance = qRes->getUInt(2);
			el.liga = qRes->getInt(3);
			el.age_category = qRes->getInt(4);
			el.name = qRes->getString(5);
			el.shortName = qRes->getString(6);
		
			data.insert(make_pair(el.id, el));
		}
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CCategoriesTable::AddRow(tDATA& rec)
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
		sprintf(query, "insert into %s(`dance`,`liga`,`age_category`,`name`,`short_name`) values(%d, %d, %d,'%s','%s')", 
			TABLE, rec.dance, rec.liga, rec.age_category, rec.name.c_str(), rec.shortName.c_str());
		res = m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
	}while(0);
	
	return res;
}

long CCategoriesTable::DelRow(unsigned long nId)
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

long CCategoriesTable::GetRow(unsigned long nId, tDATA& data)
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
		data.id = qRes->getUInt64(1);
		data.dance = qRes->getUInt(2);
		data.liga = qRes->getInt(3);
		data.age_category = qRes->getInt(4);
		data.name = qRes->getString(5);
		data.shortName = qRes->getString(6);
		
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CCategoriesTable::UpdateRow(unsigned int nId, const tDATA& data)
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
		
		if (0 != data.dance)
		{
			sprintf(tmp, "%s `dance` = %d,", query, data.dance);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != data.liga)
		{
			sprintf(tmp, "%s `liga` = %d,", query, data.liga);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != data.age_category)
		{
			sprintf(tmp, "%s `age_category` = %d,", query, data.age_category);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.name.empty())
		{
			sprintf(tmp, "%s `name` = '%s',", query, data.name.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!data.shortName.empty())
		{
			sprintf(tmp, "%s `short_name` = '%s',", query, data.shortName.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if(useFilter)
		{
			sprintf(tmp, "update %s set %s `id`=%u where `id`=%u", TABLE, query, nId, nId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			res = m_pConnection->Execute(query);
		}

	}while(0);
	
	return res;
}
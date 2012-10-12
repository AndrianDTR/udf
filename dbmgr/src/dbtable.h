#ifndef __dbtable_h__
#define __dbtable_h__

#include "dberrors.h"
#include "dbconnection.h"

#define TABLE_AGECATEGORY						"age_category"
#define TABLE_AGECODE							"age_code"
#define TABLE_CATEGORIES						"categories"
#define TABLE_CHAMPIONSHIP						"championship"
#define TABLE_CHAMPIONSHIPCATEGORIES			"championship_categories"
#define TABLE_CHAMPIONSHIPJUDGESMARK			"championship_judges_mark"
#define TABLE_CHAMPIONSHIPJUDGESTEAM			"championship_judges_team"
#define TABLE_CHAMPIONSHIPTEAM					"championship_team"
#define TABLE_CHAMPIONSHIPTOUR					"championship_tours"
#define TABLE_CHAMPIONSHIPTYPE					"championship_type"
#define TABLE_CHAMPIONSHIPTEAMCATEGORIES		"championship_team_categories"
#define TABLE_CHAMPIONSHIPTEAMDANCERS			"championship_team_dancers"
#define TABLE_CITIES							"cities"
#define TABLE_CLUBS								"clubs"
#define TABLE_COUNTRIES							"countries"
#define TABLE_DANCETYPES						"dance_types"
#define TABLE_DANCERS							"dancers"
#define TABLE_GENDER							"gender"
#define TABLE_JUDGES							"judges"
#define TABLE_JUDGESCATEGORIESHAVE				"judges_categories_have"
#define TABLE_JUDGESCATEGORIESNAME				"judges_categories_name"
#define TABLE_LIGA								"liga"
#define TABLE_TRAINERS							"treners"
#define TABLE_PAYMENTHISTORY					"payment_history"

#define MAX_QUERY_LEN							1500

#define udfYES									'Y'
#define	udfNO									'N'

#define udfPT_CLUB								'C'
#define udfPT_DANCER							'D'
#define udfPT_JUDGE								'J'
#define udfPT_TRAINER 							'T'

#include "stdio.h"
#include "string.h"

#include <list>
#include <map>

using namespace std;

class CDbTable
{
public:
typedef enum{
	ST_NONE = 0,
	ST_ASCENDING,
	ST_DESCENDING
} tSORT_TYPE;

typedef struct{
	std::string		szName;
	tSORT_TYPE		sort;
} tORDER;
	
typedef std::list<tORDER> tOrder;
typedef std::list<tORDER>::iterator tOrderIt;

typedef struct{
} tDATA;

typedef map<unsigned int, tDATA> tTableMap;
typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	tOrder					m_OrderMap;
public:
    CDbTable(CDbConnection* pCon){};
    virtual ~CDbTable(void){};

protected:
	virtual std::string		GetOrderString();
	virtual std::string		GetFieldList();
	virtual std::string		GetFilterString(const tDATA& filter) { return "";};
	virtual std::string		GetQuery(const char* table, const std::string& filter = "");
	
public:
	virtual long			CreateTable(){ return UDF_OK;};
	virtual long			DropTable(){ return UDF_OK;};
	virtual std::string		GetTableName(){ return "";};
	
	virtual long			Reload(){ return UDF_OK;};
	
	virtual void			AddOrder(std::string szName, tSORT_TYPE sort = ST_NONE);
	virtual void			SetOrderMap(const tOrder& orderMap){m_OrderMap = orderMap;};
	virtual tOrder&			GetOrderMap(){return m_OrderMap;};
	virtual void			ClearOrder();
};

#endif //__dbtable_h__

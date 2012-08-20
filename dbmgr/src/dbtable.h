#ifndef __dbtable_h__
#define __dbtable_h__

#include "dbconnection.h"

#define TABLE_AGECATEGORY						"age_category"
#define TABLE_AGECODE							"age_code"
#define TABLE_CATEGORIES						"categories"
#define TABLE_CHAMPIONSHIP						"championship"
#define TABLE_CHAMPIONSHIPCATEGORIES			"championship_categories"
#define TABLE_CHAMPIONSHIPJUDGESMARK			"championship_judges_mark"
#define TABLE_CHAMPIONSHIPJUDGESTEAM			"championship_judges_team"
#define TABLE_CHAMPIONSHIPTEAM					"championship_team"
#define TABLE_CHAMPIONSHIPTYPE					"championship_type"
#define TABLE_CHAMPIONSHIPTEAMCATEGORIES		"championshit_team_categories"
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

#define MAX_QUERY_LEN							1500

#include "stdio.h"
#include "string.h"

class CDbTable
{
public:
    CDbTable(CDbConnection* pCon){};
    virtual ~CDbTable(void){};

public:
	virtual long		CreateTable(){ return UDF_OK;};
	virtual long		DropTable(){ return UDF_OK;};
	
	virtual long		Reload(){ return UDF_OK;};
};

#endif //__dbtable_h__

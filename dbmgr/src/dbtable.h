#ifndef __DbTable_h__
#define __DbTable_h__

#include "dbconnection.h"

#define TABLE_AGECATEGORY						"age_category"
#define TABLE_AGECODE							"age_code"
#define TABLE_CATEGORIES						"categories"
#define TABLE_CHAMPIONSHIP						"championship"
#define TABLE_CHAMPIONSHIPCATEGORIES			"championship_categories"
#define TABLE_championshipjudgesmark			"championship_judges_mark"
#define TABLE_championshipjudgesteam			"championship_judges_team"
#define TABLE_championshipteam					"championship_team"
#define TABLE_championship_type					"championship_type"
#define TABLE_championship_team_categories		"championshit_team_categories"
#define TABLE_cities							"cities"
#define TABLE_clubs								"clubs"
#define TABLE_countries							"countries"
#define TABLE_dance_types						"dance_types"
#define TABLE_dancers							"dancers"
#define TABLE_gender							"gender"
#define TABLE_judges							"judges"
#define TABLE_judges_categories_have			"judges_categories_have"
#define TABLE_judges_categories_name			"judges_categories_name"
#define TABLE_liga								"liga"
#define TABLE_trainers							"treners"

class CDbTable
{
public:
    CDbTable(CDbConnection* pCon){};
    virtual ~CDbTable(void){};

public:
	virtual long		CreateTable(){};
	virtual long		DropTable(){};
	
	virtual long		Reload(){};
    /*
	virtual long		GetTable(CDbTable* data, const CDbTable& pFilter) = 0;
    virtual long		Find(CDbTable* data, const CDbTable& pFilter) = 0;
    virtual long		AddRow(const CDbTable& rec) = 0;
    virtual long		DelRow(const CDbTable& rec) = 0;
    virtual long		GetRow(CDbTable& rec) = 0;
	 */
};

#endif //__DbTable_h__

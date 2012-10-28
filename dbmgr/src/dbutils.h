#ifndef __udfutils_h__
#define __udfutils_h__

#include "db.h"

typedef std::list<unsigned int> tUIList;
typedef std::list<unsigned int>::iterator tUIListIt;

void dbmgr_version();

std::string date2str(time_t date);
time_t str2date(std::string str);

std::string time2str(time_t tTime);
time_t str2time(std::string str);

void SetGlobalDbConnection(CDbConnection* pCon);
CDbConnection* GetGlobalDbConnection();

long GetTeamsCountForChampionship(unsigned int nId, int& count);

long GetBlockLenById(unsigned int nId, time_t& len);
long GetTeamsInCategory(unsigned int nId, tUIList& teamsList);
long IsCategoryUsedOnCsById(unsigned int nId, unsigned int blockId);
long GetBlockCategories(unsigned int nId, tUIList& cats);

long JudgeHaveCategory(unsigned int judId, unsigned int catId, unsigned int& rowId);
long JudgeHaveCsCategory(unsigned int judId, unsigned int csId);

long GetFirtsTourType(unsigned int nDancers, unsigned int& typeId);

long GetJudgesForCategory(unsigned int catId, tUIList& judges);

long GetTeamStartNumber(unsigned int teamId, unsigned int& startNum);

#endif // __udfutils_h__

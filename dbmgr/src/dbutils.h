#ifndef __udfutils_h__
#define __udfutils_h__

#include "db.h"

void dbmgr_version();

std::string date2str(time_t date);
time_t str2date(std::string str);

std::string time2str(time_t tTime);
time_t str2time(std::string str);

void SetGlobalDbConnection(CDbConnection* pCon);
CDbConnection* GetGlobalDbConnection();

long GetTeamsCountForChampionship(unsigned int nId, int& count);
long GetRegisteredTeamsForCategory(unsigned int nId, int& count);

long GetBlockLenById(unsigned int nId, time_t& len);


#endif // __udfutils_h__

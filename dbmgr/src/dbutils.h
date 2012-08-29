#ifndef __udfutils_h__
#define __udfutils_h__

#include "string"
#include "time.h"

void dbmgr_version();

std::string date2str(time_t date);
time_t str2date(std::string str);

#endif // __udfutils_h__

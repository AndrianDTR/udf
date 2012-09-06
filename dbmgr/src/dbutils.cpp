#include "dbutils.h"
#include "version.h"
#include "stdio.h"
#include "locale.h"


void dbmgr_version()
{
	printf("\n");
	printf("Library: dbmgr\n");
	printf("Version: %d.%d\n", UDF_VERSION_MAJOR, UDF_VERSION_MINOR);
	printf("Version code name: %s\n", UDF_VERSION_NAME);
	printf("Build: %d\n", UDF_VERSION_PATCH);
	printf("Git hash: %s\n", UDF_VERSION_DESCR);
	printf("\n");
}

std::string date2str(time_t date)
{
	char buff[20];
	strftime(buff, 20, "%Y-%m-%d", localtime(&date));
	return std::string(buff);
}

time_t str2date(std::string str)
{
	time_t res;
	struct tm _date = {0};
    str += " 23:59:59";
	setlocale(LC_ALL, "POSIX");
    strptime(str.c_str(), "%Y-%m-%d %T", &_date);
	
	res = mktime(&_date);
    	
	return res;
}

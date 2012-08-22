#include "dbutils.h"
#include "version.h"
#include "stdio.h"

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

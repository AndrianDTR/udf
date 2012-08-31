#ifndef __udf_common_h__
#define __udf_common_h__

#include "string"
#include "stdio.h"

#ifdef _DEBUG
	#define	DEBUG_PRINTF(FMT, ... )	\
	{	\
		char modInfo[300] = {0};	\
		std::string fmt = std::string(FMT);	\
		sprintf(modInfo, "\n----------------------------------------------------------------\nDebug info:\nFile: %s: %d\nFunction: %s\n%s\n----------------------------------------------------------------\n\n", __FILE__, __LINE__, __FUNCTION__, fmt.c_str());	\
		printf(modInfo, __VA_ARGS__);\
	}
	#define	DEBUG_PRINT(FMT)	\
	{	\
		char modInfo[300] = {0};	\
		std::string fmt = std::string(FMT);	\
		sprintf(modInfo, "\n----------------------------------------------------------------\nDebug info:\nFile: %s: %d\nFunction: %s\n%s\n----------------------------------------------------------------\n\n", __FILE__, __LINE__, __FUNCTION__, fmt.c_str());	\
		printf(modInfo);\
	}
#else
	#define	DEBUG_PRINTF(FMT, ... )
	#define	DEBUG_PRINTF(FMT)
#endif //_DEBUG

#endif //__udf_common_h__
#ifndef __udf_common_h__
#define __udf_common_h__

#include "string"
#include "stdio.h"

#ifdef _DEBUG
	#define	DEBUG_PRINTF(FMT, ... )	\
	{	\
		char modInfo[300] = {0};	\
		std::string fmt = std::string(FMT);	\
		sprintf(modInfo, "\n----------------------------------------------------------------\nDebug info:\nFile: %s: %d\n%s\n----------------------------------------------------------------\n\n", __FILE__, __LINE__, fmt.c_str());	\
		printf(modInfo, __VA_ARGS__);\
	}
#else
	#define	DEBUG_PRINTF(FMT, ... )
#endif //_DEBUG

#endif //__udf_common_h__
#ifndef __udfDebug_h__
#define __udfDebug_h__

#include "stdio.h"

using namespace std;

#ifdef _DEBUG
	#define	__debug(...) \
	{	\
		printf("\n----------------------------------------------------------------"); \
		printf("\nDebug info:\nFile: %s: %d\nFunction: %s\n", __FILE__, __LINE__, __FUNCTION__);	\
		printf(__VA_ARGS__); \
		printf("\n----------------------------------------------------------------\n\n"); \
	}
	#define	__info(...)	\
	{	\
		printf("\nFile: %s: %d\n", __FILE__, __LINE__); \
		printf(__VA_ARGS__); \
		printf("\n\n"); \
	}
	#define	__msg(...)	\
	{	\
		printf(__VA_ARGS__); \
		printf("\n\n"); \
	}
	#define Enter(); printf("Function %s enter...\n", __FUNCTION__);
	#define Leave(); printf("Function %s leave.\n", __FUNCTION__);
#else
	#define	__debug( ... )
	#define	__info( ... )
	#define	__msg( ... )
	#define Enter();
	#define Leave();
#endif //_DEBUG

#endif //__udfDebug_h__

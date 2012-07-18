
#if defined(WINDOWS)
	#ifdef DBMGR_EXPORTS
		#define DBMGR_API __declspec(dllexport)
	#else
		#define DBMGR_API __declspec(dllimport)
	#endif
#else
	#define DBMGR_API
#endif

DBMGR_API void dbmgr_test();

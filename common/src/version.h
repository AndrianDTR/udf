/* 
 * 
 */

#ifndef __VERSION_H__
#define __VERSION_H__

/*-------------------------------------------------------------------------//
//      CONSTANTS                                                          //
//-------------------------------------------------------------------------*/

// Define version
#define UDF_VERSION_MAJOR   0
#define UDF_VERSION_MINOR   1
#define UDF_VERSION_NAME 	"InitialAlpha"

#ifndef UDF_VERSION_PATCH
	#define UDF_VERSION_PATCH   0
#endif

#ifndef UDF_VERSION_DESCR
#define UDF_VERSION_DESCR	"cdfds"
#endif

#define UDF_VERSION UDF_VERSION_MAJOR.UDF_VERSION_MINOR.UDF_VERSION_PATCH

/*-------------------------------------------------------------------------*/

#endif /* __VERSION_H__ ? */

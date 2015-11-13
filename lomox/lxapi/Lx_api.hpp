/*******************************************************************************
* 版权所有(C) 1988-2012 All Rights Reserved.
*
* 文件名称	: Lx_api.h
* 作    者	: 詹晨辉 (mailto:zch.fly@gmail.com)
* 创建日期	: 2012/12/21
* 功能描述	:
* 备    注	:
********************************************************************************/
#ifndef LOMOX_API_H
#define LOMOX_API_H

#ifdef WIN32
	#ifndef LOMOX_EXPORT
	#ifdef	LOMOX_LIB
	#define LOMOX_EXPORT __declspec(dllexport)
	#else
	#define LOMOX_EXPORT __declspec(dllimport)
	#endif
	#endif
#else
	#include <QtCore/qglobal.h>
	#ifndef LOMOX_EXPORT
	#ifdef LOMOX_LIB
	# define LOMOX_EXPORT Q_DECL_EXPORT
	#else
	# define LOMOX_EXPORT Q_DECL_IMPORT
	#endif
	#endif
#endif




#ifdef __cplusplus
extern "C" {
#endif
    LOMOX_EXPORT void LomoxAppRun(int argc, char *argv[]);
#ifdef __cplusplus
};
#endif // __cplusplus

#endif

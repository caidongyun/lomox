/*******************************************************************************
* 版权所有(C) 1988-2012 All Rights Reserved.
*
* 文件名称	: Lx_api.cpp
* 作    者	: 詹晨辉 (mailto:zch.fly@gmail.com)
* 创建日期	: 2012/12/21
* 功能描述	: 
* 备    注	: 
********************************************************************************/
// #ifdef WIN32
// #define LOMOX_EXPORT __declspec(dllexport)
// #endif

#include "Lx_api.hpp"
#include "../lxcoreprivate.h"

LOMOX_EXPORT void LomoxAppRun(int argc, char *argv[])
{
	lxCoreApp->runLomoxApp(argc,argv);
}
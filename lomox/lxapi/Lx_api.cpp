/*******************************************************************************
* ��Ȩ����(C) 1988-2012 All Rights Reserved.
*
* �ļ�����	: Lx_api.cpp
* ��    ��	: ղ���� (mailto:zch.fly@gmail.com)
* ��������	: 2012/12/21
* ��������	: 
* ��    ע	: 
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
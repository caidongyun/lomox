// Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "../lomox/lxapi/Lx_api.hpp"
//#pragma comment(linker, "/subsystem:windows /entry:wmainCRTStartup") //关闭console
int _tmain(int argc, char* argv[])
{
	LomoxAppRun(argc, argv);
	return 0;
}


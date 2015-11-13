/*******************************************************************************
* 版权所有(C) 2010-2012 LomoX. All Rights Reserved.
*
* 文件名称	: main.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012-12-24
* 功能描述	: 
* 备    注	: 
********************************************************************************/

#include <Windows.h>
#include <shlwapi.h>
#include <assert.h>

#include "lxdylink.h"


int main()
{
	TCHAR buffer[MAX_PATH] = {0};
	::GetModuleFileNameW(NULL, buffer, MAX_PATH);
	std::wstring wstrPath(buffer);

	std::wstring::size_type  pos = wstrPath.find_last_of(L'\\');//
	if (pos != std::wstring::npos)
	{
 		std::wstring wstrDllPath = wstrPath.substr(0, pos);
		wstrDllPath.append(L"\\lomox.dll");

		//
		LxDybamicLink lxlink(wstrDllPath);
		lxlink.RunLomoxApp(0,  NULL);
	}

	return 0;
}
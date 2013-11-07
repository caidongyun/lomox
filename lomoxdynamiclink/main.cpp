/*******************************************************************************
* ��Ȩ����(C) 2010-2012 LomoX. All Rights Reserved.
*
* �ļ�����	: main.cpp
* ��    ��	: �̶��S (mailto:caidongyun19@qq.com)
* ��������	: 2012-12-24
* ��������	: 
* ��    ע	: 
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
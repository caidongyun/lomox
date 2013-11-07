/*******************************************************************************
* ��Ȩ����(C) 2010-2012 LomoX. All Rights Reserved.
*
* �ļ�����	: lxdylink.cpp
* ��    ��	: �̶��S (mailto:caidongyun19@qq.com)
* ��������	: 2012-12-23
* ��������	: 
* ��    ע	: ������������demo��������ʹ�� 
********************************************************************************/
#include <windows.h>
#include <shlwapi.h>
#include <assert.h>

#include "lxdylink.h"

LxDybamicLink::LxDybamicLink( std::wstring wstrLxDllFilePath )
{
	m_bHadLoad = false;
	m_hModule = NULL;
	m_wstrFilePath = wstrLxDllFilePath;
	Init();
}

LxDybamicLink::~LxDybamicLink()
{
	if (m_bHadLoad == TRUE)
			UnInit();
}


bool LxDybamicLink::Init()
{
	if (m_wstrFilePath.empty())
		return false;

	if (m_bHadLoad)
		return true;

// 	if (!PathFileExists(m_wstrFilePath.c_str()))
// 	{
// 		LogDebug(m_wstrFilePath.c_str(), L"file is not exits!");
// 		return false;
// 	}

	m_hModule = ::LoadLibrary(m_wstrFilePath.c_str());
	if (NULL == m_hModule)
	{
		assert(0);
		return false;
	}

	_pRunLomox = (LomoxAppRun)GetProcAddress(m_hModule, "LomoxAppRun");


	m_bHadLoad = true;

	return false;
}

bool LxDybamicLink::UnInit()
{
	if (false == m_bHadLoad && NULL == m_hModule)
		return false;

	try
	{
		FreeLibrary(m_hModule);
	}
	catch (...)
	{
		LogDebug(L"free lib error");
	}
	m_bHadLoad = false;
	m_hModule = NULL;
	return true;
}

void LxDybamicLink::RunLomoxApp( int argc, char *argv[] )
{
	if (!m_bHadLoad)
	{
		if (!Init())
			return ;
	}

	if (_pRunLomox)
	{
		try
		{
			_pRunLomox(argc, argv);
		}
		catch (...)
		{
			LogDebug(L"run lomox app error ! LomoxAppRun(int argc, char *argv[]) ");
		}
	}
}

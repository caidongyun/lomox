/*******************************************************************************
* ��Ȩ����(C) 2010-2012 LomoX. All Rights Reserved.
*
* �ļ�����	: lxdylink.h
* ��    ��	: �̶��S caidongyun (mailto:caidongyun19@qq.com)
* ��������	: 2012-12-23
* ��������	: 
						tech: win32
						for windows os , load the lomox.dll and run ;
						lomox has it's messageloop ,and it is Synchronous blocking.

* ��    ע	: 
********************************************************************************/
#ifndef __LXDYLINK_H__
#define __LXDYLINK_H__


#include <iostream>
#include <string>


/*******************************************************************************
* ��������	: LogDebug
* ��������	: ��ʱ���
* �Ρ�����	: const wchar_t *pMsgStr1 = NULL
* �Ρ�����	: const wchar_t *pMsgStr2 = NULL
* �Ρ�����	: const wchar_t *pMsgStr3 = NULL
* �� �� ֵ	: inlinevoid 
* ������ע	: �̶��S[2012/12/24]
*******************************************************************************/
inline void LogDebug(const wchar_t *pMsgStr1 = NULL,  const wchar_t *pMsgStr2 = NULL,  const wchar_t *pMsgStr3 = NULL)
{
	std::cout<<pMsgStr1;
	if (!pMsgStr2)
		std::cout<<pMsgStr2;
	if (!pMsgStr3)
		std::cout<<pMsgStr3;
	return;
}


typedef  void (*LomoxAppRun)(int argc, char *argv[]);

class LxDybamicLink 
{
public:
	LxDybamicLink(std::wstring wstrLxDllFilePath);
	virtual ~LxDybamicLink();

public:
	bool Init();//���ŵģ��ÿͻ�֪���Ƿ�loadok��
	bool UnInit();

public:
	 void RunLomoxApp(int argc, char *argv[]);

//handle or other
private:
	HMODULE m_hModule;
	bool m_bHadLoad;
	std::wstring m_wstrFilePath;

//funtion
private:
	LomoxAppRun _pRunLomox;
};


#endif // end of __LXDYLINK_H__

/*******************************************************************************
* 版权所有(C) 2010-2012 LomoX. All Rights Reserved.
*
* 文件名称	: lxdylink.h
* 作    者	: 蔡东赟 caidongyun (mailto:caidongyun19@qq.com)
* 创建日期	: 2012-12-23
* 功能描述	: 
						tech: win32
						for windows os , load the lomox.dll and run ;
						lomox has it's messageloop ,and it is Synchronous blocking.

* 备    注	: 
********************************************************************************/
#ifndef __LXDYLINK_H__
#define __LXDYLINK_H__


#include <iostream>
#include <string>


/*******************************************************************************
* 函数名称	: LogDebug
* 功能描述	: 临时输出
* 参　　数	: const wchar_t *pMsgStr1 = NULL
* 参　　数	: const wchar_t *pMsgStr2 = NULL
* 参　　数	: const wchar_t *pMsgStr3 = NULL
* 返 回 值	: inlinevoid 
* 备　　注	: 蔡东赟[2012/12/24]
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
	bool Init();//开放的，让客户知道是否loadok了
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

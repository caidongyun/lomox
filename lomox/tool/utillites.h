/*******************************************************************************
* 版权所有(C) 1988-2011 All Rights Reserved.
*
* 文件名称	: utillites.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011/11/4
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#include "time.h"

// inline void ForceCreateDir(std::string strPath)
// {
// 	QDir dir(QString::fromLocal8Bit(strPath.c_str()));
// 	dir.mkdir(QString::fromLocal8Bit(strPath.c_str()));
// }

//----------------------------------------------------------------------------------------------------
//写日志，写到%appdata%\目录下。
//----------------------------------------------------------------------------------------------------
inline void LogEx(const char* MsgStr,const char *MsgStr2 = NULL,const char *MsgStr3 = NULL)
{
	qDebug()<<MsgStr;
	if (!MsgStr2)
		qDebug()<<MsgStr2;
	if (!MsgStr3)
		qDebug()<<MsgStr3;
	return;
}

//---------------------------------------------------------------------------
inline bool AppIsRunning(int dwWaitTime)
{
	return true;
}

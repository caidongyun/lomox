/*******************************************************************************
* 版权所有(C) 2011-2011 LomoX. caidongyun All Rights Reserved.
*
* 文件名称	: localtool.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011/12/13
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __LOCALTOOL_H__
#define __LOCALTOOL_H__

#include "stdafx.h"
namespace LX_UTILITYTOOL
{
	inline bool setupApiObject(QWebPage* pWebPage, QString strApiName, QObject *object) 
	{
		if (!pWebPage || !object)
			return false;
		QWebFrame *pFrame = pWebPage->mainFrame();
		if (pFrame)
		{
			pFrame->addToJavaScriptWindowObject(strApiName, object);
			return true;
		}
		return false;
	}
};

#endif // end of __LOCALTOOL_H__



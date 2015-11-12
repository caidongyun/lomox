/*******************************************************************************
* 版权所有(C) 2011-2011 LomoX. caidongyun All Rights Reserved.
*
* 文件名称	: operate.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011/12/14
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#include "lomox_global.h"
#include "lxoperate.h"

LxOperate::LxOperate( QObject *parent /*= NULL*/, QWebView* pWebView /*= NULL*/, QString strApiName /*= QString("")*/ )
:QObject(parent)
{
	m_strApiName = strApiName;
	if (pWebView)
	{
		m_ptrWebView = pWebView;
		m_ptrWebPage = pWebView->page();
		QWebFrame* pWebFrame = m_ptrWebPage->mainFrame();
		if (pWebFrame)
			connect(pWebFrame, SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(setupJsAPIObject()));
	}
}

LxOperate::~LxOperate()
{
}

bool LxOperate::setupJsAPIObject()
{
	Q_CHECK_PTR(m_ptrWebPage);
	return LX_UTILITYTOOL::setupApiObject(m_ptrWebPage, m_strApiName, this);
}

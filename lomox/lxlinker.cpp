/*******************************************************************************
* 版权所有(C) 2011-2012www.LomoX.hk All Rights Follow Lomox licence.
*
* 文件名称	: lxlinker.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/2/19
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#include "lomox_global.h"
#include "lxbasewin.h"
#include "lxlinker.h"



LxLinker::LxLinker( QObject* parent /*= 0*/ )
:QObject(parent)
{

}


LxLinker::~LxLinker()
{

}


bool LxLinker::setupJsApiObject()
{
	Q_CHECK_PTR(m_ptrPage);
	return LM_UTILITYTOOL::setupApiObject(m_ptrPage, m_strApiName, m_ptrObj);
}


bool LxLinker::linkObject( LxBaseWin* pView, QString strApiName, QObject* pObj )
{
	LX_VERIFY_IN_2_POINTERS(pView, pObj);
	m_ptrObj = pObj;
	m_ptrWebview = pView;
	m_strApiName = strApiName;
	m_ptrPage = m_ptrWebview->page();
	QWebFrame* pWebFrame = m_ptrPage->mainFrame();
	if (pWebFrame)
	{
		bool bRes =  m_ptrObj->connect(pWebFrame, SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(setupJsApiObject()));
		return bRes;
	}
	return false;
}

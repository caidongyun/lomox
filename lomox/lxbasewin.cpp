/*******************************************************************************
* 版权所有(C) 1988-2011 All Rights Reserved.
*
* 文件名称	: basewin.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011/11/3
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#include "lomox_global.h"
#include "lxbasewin.h"
#include <QWebPage>
#include "lxdialogoperate.h"
#include "lxdialogs.h"
#include "lxwebpluginfactory.h"

LxBaseWin::LxBaseWin(QWidget *parent)
:QWebView(parent)
{
	//_initWidget();
	m_strApiName = LOMOX_API_DIALOG ;
	this->setRenderHints(QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);
	QObject::connect(this, SIGNAL(linkClicked(const QUrl&)), this, SLOT(linkClickedAction(const QUrl&)));
}

LxBaseWin::~LxBaseWin()
{
}

bool LxBaseWin::initWidget()
{
	setObjectName("lomoxwin");
 	this->setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::Dialog);
	//this->setAttribute(Qt::WA_TranslucentBackground, true);background-color:transparent}
	this->setStyleSheet("#lomoxwin{ QMenu{background-color:none;}");
	QPointer<QWebPage> ptrWebPage = this->page();
	QPointer<LxWebPluginFactory> ptrPlugin = new LxWebPluginFactory(ptrWebPage);
	ptrWebPage->setPluginFactory(ptrPlugin);
	ptrWebPage->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);//LinkDelegationPolicy::DelegateAllLinks
	return true;
}

bool LxBaseWin::event(QEvent* e)
{
	return QWebView::event(e);
}

void LxBaseWin::showEvent( QShowEvent *e )
{
 	this->repaint();
 	return QWebView::showEvent(e);
}


void LxBaseWin::linkClickedAction( const QUrl& url )
{
	LxDialogs* pDialogs = lxCoreApp->getDialogs();
	if (pDialogs)
	{
		QString strUrl = url.toString();
		QPointer<LxDialogBase> ptrDialog = reinterpret_cast<LxDialogBase*>(pDialogs->add(strUrl,strUrl));
		if (ptrDialog)
		{
			ptrDialog->show();
		}
	}
	return ;
}

// void LxBaseWin::setDefaultApiName( QString strName /*= LOMOX_API_DIALOG*/ )
// {
// 	m_strApiName = strName;
// }

// bool LxBaseWin::setupJsApiObject()
// {
// 	Q_CHECK_PTR(m_ptrPage);
// 	return LM_UTILITYTOOL::setupApiObject(m_ptrPage, m_strApiName, this);
// }
// 
// void LxBaseWin::setDialogWH( QVariant Weight, QVariant Hight )
// {
// 	LogEx("voikd LomoX::setDialogWH()");
// 	if (Weight.isNull()|| Hight.isNull())
// 		return;
// 
// 	int nWidth = 0, nHeight = 0;
// 
// 	if (QVariant::Double == Weight.type() && QVariant::Double == Hight.type())
// 	{
// 		nWidth = (int) Weight.toDouble()  + 1;
// 		nHeight = (int) Hight.toDouble() + 1;
// 		QSize size(nWidth, nHeight);
// 		this->resize(size);
// 	}
// 	else
// 	{
// 		//默认
// 	}
// }



	

/*******************************************************************************
* 版权所有(C) 1988-2014 All Rights Reserved.
*
* 文件名称	: basewin.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2014/3/9
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#include "lomox_global.h"
#include "lxmainwin.h"
#include <QWebPage>
#include "lxdialogoperate.h"
#include "lxdialogs.h"
#include "lxwebpluginfactory.h"


#include <QNetworkAccessManager>

LxMainWindow::LxMainWindow( QWidget* prarent /*= 0*/ )
:LxBaseWin(prarent)
{
/*	m_strApiName = LOMOX_API_DIALOG ;*/
	_initWidget();
	this->setRenderHints(QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);
 	QObject::connect(this, SIGNAL(linkClicked(const QUrl&)), this, SLOT(linkClickedAction(const QUrl&)));

	QNetworkAccessManager* pNetworkAccessManager = this->page()->networkAccessManager();
	
	LxOption* pOption = lxCoreApp->getOption();
	if (pOption && pNetworkAccessManager)
	{
		QString strCookies = pOption->getCookieFilePath();
		LxNetWorkCookies* pCookies = new LxNetWorkCookies(strCookies, this);
		pNetworkAccessManager->setCookieJar(pCookies);

		QNetworkDiskCache *diskCache = new QNetworkDiskCache(this);
		QString location = QDesktopServices::storageLocation(QDesktopServices::CacheLocation);
		diskCache->setCacheDirectory(location);
		diskCache->setMaximumCacheSize(1024);//byte
		pNetworkAccessManager->setCache(diskCache);

		pNetworkAccessManager->setNetworkAccessible(QNetworkAccessManager::Accessible);
	}

}



LxMainWindow::~LxMainWindow()
{

}
bool LxMainWindow::_initWidget()
{
	setObjectName("lomoxwin");

	do 
	{
		LxOption* pOption = lxCoreApp->getOption();

		if (!pOption)
			break;

		Qt::WindowFlags winType = Qt::Dialog ;

		if (pOption->getNeedShowMainNcFrame())
		{
			winType |=  Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint;
		}
		else
		{
			winType |= Qt::FramelessWindowHint;
			this->setAttribute(Qt::WA_TranslucentBackground, true);
			this->setStyleSheet("#lomoxwin{background-color:transparent} QMenu{background-color:none;}");
		}

		if (pOption->getMainWindowStaysOnTopHint())
			winType |= Qt::WindowStaysOnTopHint;

		this->setWindowFlags(winType);

		QPointer<QWebPage> ptrWebPage = this->page();
		QPointer<LxWebPluginFactory> ptrPlugin = new LxWebPluginFactory(ptrWebPage);
		ptrWebPage->setPluginFactory(ptrPlugin);

		ptrWebPage->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);//LinkDelegationPolicy::DelegateAllLinks
	} while (false);


	return true;
}

 
 
 void LxMainWindow::linkClickedAction( const QUrl& url )
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

/*******************************************************************************
* 版权所有(C) 1988-2014 All Rights Reserved.
*
* 文件名称	: basewin.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011/11/3
* 功能描述	:
* 备    注  ：
* 修    改  ：詹晨辉(KeoJam)(mailto:zch.fly@gmail.com)
********************************************************************************/
#include "lomox_global.h"
#include "lxmainwin.h"
#include <QWebPage>
#include "lxdialogoperate.h"
#include "lxdialogs.h"
#include "lxwebpage.h"
#include "lxwebpluginfactory.h"


#include <QNetworkAccessManager>

LxMainWindow::LxMainWindow( QWidget* prarent /*= 0*/ )
:QWebView(prarent)
{
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
		QString location = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
		//QString location = QDesktopServices::storageLocation(QDesktopServices::CacheLocation);
		diskCache->setCacheDirectory(location);
		diskCache->setMaximumCacheSize(1024);//byte
		pNetworkAccessManager->setCache(diskCache);

		pNetworkAccessManager->setNetworkAccessible(QNetworkAccessManager::Accessible);

		m_bLoadHrefInCurrent = pOption->getLoadHrefInCurrentMainDialog();

	}
	QString iconName = pOption->getSystemTrayIconName();
	QString iconPath = QCoreApplication::applicationDirPath() + "/" + iconName;
	qDebug("show path %s", qPrintable(iconPath));
	QIcon icon(iconPath);
	this->setWindowIcon(icon);
}



LxMainWindow::~LxMainWindow()
{
	if (!lxCoreApp->getOption()->getDialogsRelationShip())//如果不存在父子关系，主窗口关闭要手动关闭所有窗口
	{
		LxDialogs* pDialogs = lxCoreApp->getDialogs();
		pDialogs->closeAll();
	}
	
}

bool LxMainWindow::event(QEvent* e)
{
	return QWebView::event(e);
}

void LxMainWindow::showEvent( QShowEvent *e )
{
	this->repaint();
	return QWebView::showEvent(e);
}
void LxMainWindow::showMax()
{
	QDesktopWidget desk;
	this->setGeometry(desk.availableGeometry());
	this->show();
}
bool LxMainWindow::_initWidget()
{
	setObjectName("lomoxwin");
	setAttribute(Qt::WA_DeleteOnClose);//主窗口关闭时析构

	do 
	{
		LxOption* pOption = lxCoreApp->getOption();

		if (!pOption)
			break;

		Qt::WindowFlags winType = Qt::Dialog ;

		if (pOption->getNeedShowMainNcFrame())
		{
			winType |= Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint;
		}
		else
		{
			winType |= Qt::FramelessWindowHint;
			winType |= Qt::WindowSystemMenuHint;//不加不出现窗口 modify by KeoJam 2015-04-19
			this->setAttribute(Qt::WA_TranslucentBackground, true);
			this->setStyleSheet("#lomoxwin{background-color:transparent} QMenu{background-color:none;}");
		}

		if (pOption->getMainWindowStaysOnTopHint())
			winType |= Qt::WindowStaysOnTopHint;

		this->setWindowFlags(winType);

		QWebPage* ptrWebPage = new LxWebPage(this);
		this->setPage(ptrWebPage);//add  by KeoJam 启用自定义LxWebPage用于Permission处理
		//QPointer<QWebPage> ptrWebPage = this->page();
		QPointer<LxWebPluginFactory> ptrPlugin = new LxWebPluginFactory(ptrWebPage);
		ptrWebPage->setPluginFactory(ptrPlugin);
		//ptrWebPage->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);//LinkDelegationPolicy::DelegateAllLinks
	} while (false);


	return true;
}

 
 
void LxMainWindow::linkClickedAction( const QUrl& url )
{
	if (m_bLoadHrefInCurrent)
	{
		this->load(url);
	}
	else
	{
		LxDialogs* pDialogs = lxCoreApp->getDialogs();
		if (pDialogs)
		{
			QString strUrl = url.toString();
			QPointer<LxDialogBase> ptrDialog = reinterpret_cast<LxDialogBase*>(pDialogs->add(strUrl,strUrl));
			if (ptrDialog)
				ptrDialog->show();
		}
	}
 	return ;
}

void LxMainWindow::triggerPageAction(QWebPage::WebAction action, bool checked /*= false*/)
{
	qDebug()<<"action:"<<action<<"\r\n";
}
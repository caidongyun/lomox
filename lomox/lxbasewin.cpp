/*******************************************************************************
* 版权所有(C) 1988-2011 All Rights Reserved.
*
* 文件名称	: basewin.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011/11/3
* 功能描述	: 
* 备    注	: 
* 修    改  ：詹晨辉(KeoJam)(mailto:zch.fly@gmail.com)
********************************************************************************/
#include "lomox_global.h"
#include "lxbasewin.h"
#include <QWebPage>
#include "lxdialogoperate.h"
#include "lxdialogs.h"
#include "lxwebpage.h"
#include "lxwebpluginfactory.h"

LxBaseWin::LxBaseWin(QWidget *parent)
:QWebView(parent)
{
	_initWidget();
	m_strApiName = LOMOX_API_DIALOG ;
	this->setRenderHints(QPainter::SmoothPixmapTransform | QPainter::HighQualityAntialiasing);
	QObject::connect(this, SIGNAL(linkClicked(const QUrl&)), this, SLOT(linkClickedAction(const QUrl&)));

	this->setAttribute(Qt::WA_DeleteOnClose);

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

		m_bLoadHrefInCurrent = pOption->getLoadHrefInCurrentChildDialog();
	}

	QString iconName = pOption->getSystemTrayIconName();
	QString iconPath = QCoreApplication::applicationDirPath() + "/" + iconName;
	qDebug("show path %s", qPrintable(iconPath));
	QIcon icon(iconPath);
	this->setWindowIcon(icon);
}

LxBaseWin::~LxBaseWin()
{
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



bool LxBaseWin::_initWidget()
{
	setObjectName("lomoxchildwin");

	do
	{
		LxOption* pOption = lxCoreApp->getOption();

		if (!pOption)
			break;

		Qt::WindowFlags winType = Qt::Dialog;

		if (pOption->getNeedShowChildNcFrame())
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

		if (pOption->getChildWindowStaysOnTopHint())
			winType |= Qt::WindowStaysOnTopHint;
		this->setWindowFlags(winType);
#ifdef Q_OS_WIN
		SetWindowLong((HWND)this->winId(), GWL_EXSTYLE, WS_EX_APPWINDOW);//add  by KeoJam 强制子窗口最小化显示在任务
#endif
		QWebPage* ptrWebPage = new LxWebPage(this);
		this->setPage(ptrWebPage);//add  by KeoJam 启用自定义LxWebPage用于Permission处理
		//QPointer<QWebPage> ptrWebPage = this->page();
		QPointer<LxWebPluginFactory> ptrPlugin = new LxWebPluginFactory(ptrWebPage);
		ptrWebPage->setPluginFactory(ptrPlugin);
		//ptrWebPage->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);//LinkDelegationPolicy::DelegateAllLinks
	} while (false);


	return true;
}



void LxBaseWin::linkClickedAction( const QUrl& url )
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

void LxBaseWin::triggerPageAction(QWebPage::WebAction action, bool checked /*= false*/)
{
	qDebug()<<"action:"<<action<<"\r\n";
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



	

/*******************************************************************************
* 版权所有(C) 2011-2012www.LomoX.hk All Rights Follow Lomox licence.
*
* 文件名称	: lxcoreprivate.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/2/20
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#include "lomox_global.h"
#include "lxdialogoperate.h"
#include "lxdialogs.h"
#include "lxcoreprivate.h"
#include <QtWebKit/QWebSettings>

#include "lxmainwin.h"

LxCoreApplicationPrivate::~LxCoreApplicationPrivate()
{
	if (m_pMainWin)
		m_pMainWin->deleteLater();

    if (m_pDialogs)
        m_pDialogs->deleteLater();

	if (m_pOption)
		m_pOption->deleteLater();
}

void LxCoreApplicationPrivate::showMainDialog( QUrl URL /*= ""*/ )
{
    qDebug(" LxCoreApplicationPrivate::showMainDialog()");
	
	do 
	{
		if (!m_pMainWin)
			m_pMainWin = new LxMainWindow();

		m_pMainWin->setUrl(URL);

		LxOption* pOption = getOption();

		if (!pOption)
			break;

// 		Qt::WindowFlags winType = Qt::Dialog ;
// 
// 		if (pOption->getNeedShowMainNcFrame())
// 			winType = Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint;
// 
// 		if (pOption->getMainWindowStaysOnTopHint())
// 			winType |= Qt::WindowStaysOnTopHint;
// 
// 		m_pMainWin->setWindowFlags(winType);


		if (lxCoreApp->getDialogs())
		{
			m_pDialogs->append(QString("LomoX-Main"),m_pDialog);
		}

		new LxCoreApplication((QObject*)m_pMainWin, m_pMainWin,QString(LOMOX_API_COREAPP));

		m_pMainWin->show();
		
		qDebug("LomoX.dialogs.count=%d",m_pDialogs->count().toInt());

	} while (false);
	
	
	return ;

 
}


LxDialogs* LxCoreApplicationPrivate::getDialogs()
{
    qDebug(" LxCoreApplicationPrivate::getDialogs()");
    if (!m_pDialogs)
    {
        m_pDialogs = new LxDialogs(this);
        m_pDialogs->append(QString("start"),m_pDialog);
    }
	return m_pDialogs;
}


LxMainWindow* LxCoreApplicationPrivate::getMainWin()
{
	if (!m_pMainWin)
		m_pMainWin = new LxMainWindow();
	return m_pMainWin;
}

void LxCoreApplicationPrivate::runLomoxApp(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages,true);
//#ifdef  DEBUG
	QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled,true);
//#endif

	QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::OfflineWebApplicationCacheEnabled,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalStorageEnabled,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalContentCanAccessFileUrls,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptCanOpenWindows,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::LinksIncludedInFocusChain,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::PrintElementBackgrounds, true);

	//QWebSettings::globalSettings()->setObjectCacheCapacities(0,0,0); 降低内存用的，但是速度回变低

	QString strStoragePath = QCoreApplication::applicationDirPath() + QDir::separator() + QString("Storage\\");
	QWebSettings::globalSettings()->enablePersistentStorage(strStoragePath);

	do 
	{
		QString strUrl;
		LxOption* pOtion = getOption();
		if (pOtion)
		{
			strUrl = pOtion->getStartUrl();
		}
		else
			Q_ASSERT(pOtion == nullptr);


		if (!strUrl.isEmpty())
		{
			if (-1 == strUrl.indexOf(':'))
			{
				strUrl = QString::fromLocal8Bit("http://") + strUrl;
			}

			lxCoreApp->showMainDialog(QUrl(strUrl));

			if (!pOtion)
				break;

			QString strTitle = pOtion->getMainTitle();
			if (!strTitle.isEmpty())
				lxCoreApp->setMainDialogTitle(strTitle);
		}
		else
		{
			Q_ASSERT(!strUrl.isEmpty());
			return ;
		}

	} while (false);

	a.exec();
}

void LxCoreApplicationPrivate::quit()
{
    qApp->quit();
}

LxOption* LxCoreApplicationPrivate::getOption()
{
	if (!m_pOption)
	{
		m_pOption = new LxOption(this);
	}

	return m_pOption;
}


void LxCoreApplicationPrivate::setMainDialogTitle( QString &strTitle )
{
	if (m_pMainWin)
	{
		m_pMainWin->setWindowTitle(strTitle);
	}
	return ;
}


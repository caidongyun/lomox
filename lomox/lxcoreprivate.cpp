/*******************************************************************************
* 版权所有(C) 2011-2012www.LomoX.hk All Rights Follow Lomox licence.
*
* 文件名称	: lxcoreprivate.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/2/20
* 功能描述	: 
* 备    注	: 
* 修    改  ：詹晨辉(KeoJam)(mailto:zch.fly@gmail.com)
********************************************************************************/
#include "lomox_global.h"
#include "lxdialogoperate.h"
#include "lxdialogs.h"
#include "lxcoreprivate.h"
#include <QtWebKit/QWebSettings>

#include "lxmainwin.h"
#include "lxsystemtray.h"
#include "lxdownloadmanager.h"

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

		if (lxCoreApp->getDialogs())
		{
			m_pDialogs->append(QString("LomoX-Main"),m_pDialog);
		}

		new LxCoreApplication((QObject*)m_pMainWin, m_pMainWin,QString(LOMOX_API_COREAPP));
		bool bshowloading = false;
		int gifW = 0;
		int gifH = 0;
		if (pOption->getNeedShowLoadingGif())
		{
			gifW = pOption->getLoadingGifWidth();
			gifH = pOption->getLoadingGifHeight();
			if (gifW > 0 && gifH > 0)
			{
				bshowloading = true;
			}
		}
		LxDialogBase* pDialogOp = new LxDialogBase(this, m_pMainWin, "LxDialog", bshowloading, gifW, gifH);

		LxSystemTray *pSystemTray = NULL;
		if (pOption->getNeedSystemTray())
		{
			QString iconName = pOption->getSystemTrayIconName();
			QString iconPath = QCoreApplication::applicationDirPath() + "/" + iconName;

			qDebug() << "Show Path:" << iconPath;
			
			QIcon icon(iconPath);
			pSystemTray = new LxSystemTray(icon, pOption->getMainTitle(), pDialogOp);
		}
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
        //m_pDialogs->append(QString("start"),m_pDialog);//modify by KeoJam
    }
	return m_pDialogs;
}

//add by Keojam 下载器
LxDownloadManager* LxCoreApplicationPrivate::getDownloadManager()
{
	qDebug(" LxCoreApplicationPrivate::getDownloadManager()");
	if (!m_pdownloadmanager)
	{
		m_pdownloadmanager = new LxDownloadManager(this);
		//m_pDialogs->append(QString("start"),m_pDialog);//modify by KeoJam
	}
	return m_pdownloadmanager;
}

LxMainWindow* LxCoreApplicationPrivate::getMainWin()
{
	if (!m_pMainWin)
	{
		m_pMainWin = new LxMainWindow();
	}
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
	QWebSettings::globalSettings()->setAttribute(QWebSettings::XSSAuditingEnabled, false);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::NotificationsEnabled, true);
	
	//QWebSettings::globalSettings()->setObjectCacheCapacities(0,0,0); 降低内存用的，但是速度回变低
	QString libraryPath = QCoreApplication::applicationDirPath() + QDir::separator() + QString("plugins\\");
	QStringList libraryPaths;
	libraryPaths.append(libraryPath);
	QCoreApplication::setLibraryPaths(libraryPaths);
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
            //Mac版文件路径开始为/需要,排除 by Colin3dmax
            if (-1 == strUrl.indexOf(':') && strUrl.indexOf("/")!=0)
			{
				strUrl = QString::fromLocal8Bit("http://") + strUrl;
			}
			QFileInfo qFileInfo(strUrl);
			if (qFileInfo.isAbsolute())//add by KeoJam 如果是本地文件强制加file:///
			{
				strUrl = QString::fromLocal8Bit("file:///") + strUrl;
			}

			if (!pOtion)
				break;

			QString strTitle = pOtion->getMainTitle();
			if (!strTitle.isEmpty())
				lxCoreApp->setMainDialogTitle(strTitle);
			lxCoreApp->showMainDialog(QUrl(strUrl));
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


QString LxOption::getCookieFilePath()
{
	QString strCookieCache = QCoreApplication::applicationDirPath() + QString::fromLocal8Bit("/cache/");
	QDir dir(strCookieCache);
	dir.mkpath(strCookieCache);
	strCookieCache += "cookie.dat";

	return strCookieCache;
}

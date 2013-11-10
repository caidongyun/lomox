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


LxCoreApplicationPrivate::~LxCoreApplicationPrivate()
{
	if (m_pMainWin)
		m_pMainWin->deleteLater();

    if (m_pDialogs)
        m_pDialogs->deleteLater();
}

void LxCoreApplicationPrivate::showMainDialog( QUrl URL /*= ""*/ )
{
    qDebug(" LxCoreApplicationPrivate::showMainDialog()");
	if (!m_pMainWin)
		m_pMainWin = new LxBaseWin();
	m_pMainWin->setUrl(URL);
	m_pMainWin->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog | Qt::WindowStaysOnTopHint);
	//m_pMainWin->setWindowFlags( Qt::Dialog | Qt::WindowStaysOnTopHint);

    m_pDialog = new LxDialogBase(m_pMainWin, m_pMainWin, "LxDialog");

    if (lxCoreApp->getDialogs())
    {
		m_pDialogs->append(QString("LomoX-Main"),m_pDialog);
    }

	new LxCoreApplication((QObject*)m_pMainWin, m_pMainWin,QString(LOMOX_API_COREAPP));

	m_pMainWin->show();

    qDebug("LomoX.dialogs.count=%d",m_pDialogs->count().toInt());
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


LxBaseWin* LxCoreApplicationPrivate::getMainWin()
{
	if (!m_pMainWin)
		m_pMainWin = new LxBaseWin();
	return m_pMainWin;
}

void LxCoreApplicationPrivate::runLomoxApp(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages,true);
#ifdef  DEBUG
	QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled,true);
#endif

	QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::OfflineWebApplicationCacheEnabled,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalStorageEnabled,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::LocalContentCanAccessFileUrls,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptCanOpenWindows,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::LinksIncludedInFocusChain,true);
	QWebSettings::globalSettings()->setAttribute(QWebSettings::PrintElementBackgrounds, true);

	QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);


	//QWebSettings::globalSettings()->setObjectCacheCapacities(0,0,0); 降低内存用的，但是速度回变低

	QString strStoragePath = QCoreApplication::applicationDirPath() + QDir::separator() + QString("Storage\\");
	QWebSettings::globalSettings()->enablePersistentStorage(strStoragePath);
    QString strFile = "file:///"+QCoreApplication::applicationDirPath() + "/Resources/main.html";
	qDebug() << strFile.toLatin1();
    lxCoreApp->showMainDialog(strFile);
	a.exec();
}

void LxCoreApplicationPrivate::quit()
{
    qApp->quit();
}



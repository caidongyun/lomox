/*******************************************************************************
* 版权所有(C) 2011-2015www.LomoX.hk All Rights Follow Lomox licence.
*
* 文件名称	: lxdownloadmanager.cpp
* 作    者	: 詹晨辉 (mailto:zch.fly@gmail.com)
* 创建日期	: 2015/04/20
* 功能描述	:
* 备    注	:
********************************************************************************/
#include "lxdownloadmanager.h"
#include "lxdialogoperate.h"
#include "lxcoreapplication.h"

LxDownloadItem::LxDownloadItem(QNetworkReply *pReply, LxDialogBase* pLxDialogBase, QObject *parent)
:QObject(parent)
{
	m_pReply = pReply;
	m_pLxDialogBase = pLxDialogBase;
	startDownloading(m_pReply->url());
}
LxDownloadItem::~LxDownloadItem()
{
}

void LxDownloadItem::startDownloading(QUrl url)
{
	m_pReply = LxDownloadManager::getNetworkAccessManager()->get(QNetworkRequest(url));
	QUrl locationHeader = m_pReply->header(QNetworkRequest::LocationHeader).toUrl();
	bool hasFtpUrlInHeader = locationHeader.isValid() && (locationHeader.scheme() == "ftp");
	LogEx(locationHeader.toString().toStdString().data());
	if (m_pReply->url().scheme() == "ftp" || hasFtpUrlInHeader) {
		LogEx("ftp!!!");
		return;
	}

	if (locationHeader.isValid()) {
		m_pReply->abort();
		m_pReply->deleteLater();

		m_pReply = LxDownloadManager::getNetworkAccessManager()->get(QNetworkRequest(locationHeader));
	}
	m_pReply->setParent(this);
	connect(m_pReply, SIGNAL(finished()), this, SLOT(downloadFinished()));
	//connect(m_pReply, SIGNAL(readyRead()), this, SLOT(downloadReadyRead()));
	connect(m_pReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(downloadError(QNetworkReply::NetworkError)));
	//connect(m_pReply, SIGNAL(metaDataChanged()), this, SLOT(metaDataChanged()));
	downloadReadyRead();
}

void LxDownloadItem::downloadReadyRead()
{
}

void LxDownloadItem::downloadError(QNetworkReply::NetworkError)
{
	QString method = QString(QString::fromLocal8Bit("downloadfailed(\"%1\")")).arg(m_pReply->errorString());
	QVariant code = method;
	m_pLxDialogBase->eval(code);
}

void LxDownloadItem::downloadFinished()
{
	LogEx("downloadsuccess");
	int http_status = m_pReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
	m_pReply->close();
	if (http_status == 302)
	{
		m_pReply->rawHeader("Location");
		m_pReply->deleteLater();
		startDownloading(QUrl(m_pReply->rawHeader("Location")));
	}
	QString path = m_pReply->rawHeader("Content-Disposition");
	int npos = path.lastIndexOf("filename=");
	if (npos > 0)
	{
		path = path.right(npos);
	}
	if (path.isEmpty()) {
		path = m_pReply->url().path();
	}

	QFileInfo info(path);
	QString baseName = info.completeBaseName();
	QString endName = info.suffix();

	if (baseName.isEmpty()) {
		baseName = tr("NoNameDownload");
	}

	if (!endName.isEmpty()) {
		endName.prepend(QLatin1Char('.'));
	}

	QString name = baseName + endName;

	if (name.contains(QLatin1Char('"'))) {
		name.remove(QLatin1String("\";"));
	}
	QString strfilter = "";
	QString selectedFilter = "Images(*.png *.xpm *.jpg);; Text files(*.txt);; XML files(*.xml)";
	QString fileName = QFileDialog::getSaveFileName((QWidget*)m_pLxDialogBase->getCoreDialog(), QString::fromLocal8Bit("保存"),
		QCoreApplication::applicationDirPath() + "/download/" + name, "*" + endName);
	if (fileName.isEmpty()) {
		m_pReply->close();
		//fileNameLabel->setText(tr("Download canceled: %1").arg(QFileInfo(defaultFileName).fileName()));
		QString method = QString(QString::fromLocal8Bit("downloadfailed(\"%1\")")).arg(QString::fromLocal8Bit("下载取消"));
		QVariant code = method;
		m_pLxDialogBase->eval(code);
		return;
	}
	m_file.setFileName(fileName);
	if (!m_file.isOpen()) {
		if (!m_file.open(QIODevice::WriteOnly)) {
			QString method = QString(QString::fromLocal8Bit("downloadfailed(\"%1\")")).arg(QString::fromLocal8Bit("无法保存"));
			QVariant code = method;
			m_pLxDialogBase->eval(code);
			return;
		}
	}
	if (-1 == m_file.write(m_pReply->readAll())) {
		QString method = QString(QString::fromLocal8Bit("downloadfailed(\"%1\")")).arg(QString::fromLocal8Bit("保存失败"));
		QVariant code = method;
		m_pLxDialogBase->eval(code);
		m_file.close();
		return;
	}
	m_file.close();
	QString method = QString(QString::fromLocal8Bit("downloadsuccess(\"%1\")")).arg(m_file.fileName());
	QVariant code = method;
	m_pLxDialogBase->eval(code);
}

void LxDownloadItem::metaDataChanged()
{
	QUrl locationHeader = m_pReply->header(QNetworkRequest::LocationHeader).toUrl();
	if (locationHeader.isValid()) {
		m_pReply->close();
		m_pReply->deleteLater();
		//m_pReply = LxDownloadManager::getNetworkAccessManager()->get(QNetworkRequest(locationHeader));
		startDownloading(locationHeader);
	}
}

QNetworkAccessManager* LxDownloadManager::m_pNetworkAccessManager = nullptr;

LxDownloadManager::LxDownloadManager(QObject *parent)
	: QObject(parent)
{
	m_pNetworkAccessManager = new QNetworkAccessManager(this);
	LxOption* pOption = lxCoreApp->getOption();
	QString strCookies = pOption->getCookieFilePath();
	LxNetWorkCookies* pCookies = new LxNetWorkCookies(strCookies, this);
	m_pNetworkAccessManager->setCookieJar(pCookies);

	QNetworkDiskCache *diskCache = new QNetworkDiskCache(this);
	QString location = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
	//QString location = QDesktopServices::storageLocation(QDesktopServices::CacheLocation);
	diskCache->setCacheDirectory(location);
	diskCache->setMaximumCacheSize(1024);//byte
	m_pNetworkAccessManager->setCache(diskCache);

	m_pNetworkAccessManager->setNetworkAccessible(QNetworkAccessManager::Accessible);
	m_pNetworkAccessManager->setProperty("User-Agent", "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1)");
	m_pNetworkAccessManager->setProperty("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
}

LxDownloadManager::~LxDownloadManager()
{
	if (m_pNetworkAccessManager)
		m_pNetworkAccessManager->deleteLater();
}

void LxDownloadManager::download(const QNetworkRequest &request, LxDialogBase* pdiaglogbase, bool requestFileName)
{
	if (request.url().isEmpty())
		return;
	QNetworkReply *reply = m_pNetworkAccessManager->get(request);
	if (!reply || reply->url().isEmpty())
		return;
// 	QVariant header = reply->header(QNetworkRequest::ContentLengthHeader);
// 	bool ok;
// 	int size = header.toInt(&ok);
// 	if (ok && size == 0)
// 		return;
	QList<QByteArray> headerArray = reply->rawHeaderList();
	LxDownloadItem *item = new LxDownloadItem(reply, pdiaglogbase, this);
	m_downloads.append(item);
}

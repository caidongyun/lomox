/*******************************************************************************
* 版权所有(C) 2011-2015www.LomoX.hk All Rights Follow Lomox licence.
*
* 文件名称	: lxdownloadmanager.h
* 作    者	: 詹晨辉 (mailto:zch.fly@gmail.com)
* 创建日期	: 2015/04/20
* 功能描述	:
* 备    注	:
********************************************************************************/
#ifndef __LXDOWNLOADMANAGER_H__
#define __LXDOWNLOADMANAGER_H__

#include <QObject>
#include "lomox_global.h"

class  LxDialogBase;

class LOMOX_EXPORT LxDownloadItem : public QObject
{
	Q_OBJECT

public:
	LxDownloadItem(QNetworkReply *pReply, LxDialogBase* pLxDialogBase,QObject *parent);
	~LxDownloadItem();
	void startDownloading(QUrl url);
private:
	QNetworkReply* m_pReply;
	LxDialogBase* m_pLxDialogBase;
	QFile m_file;
private slots:
	void downloadReadyRead();
	void downloadError(QNetworkReply::NetworkError);
	void downloadFinished();
	void metaDataChanged();
};

class LOMOX_EXPORT LxDownloadManager : public QObject
{
	Q_OBJECT

public:
	LxDownloadManager(QObject *parent);
	~LxDownloadManager();
	static QNetworkAccessManager* getNetworkAccessManager()
	{
		return m_pNetworkAccessManager;
	}

private:
	QList<LxDownloadItem*> m_downloads;
	static QNetworkAccessManager* m_pNetworkAccessManager;
public slots :
	void download(const QNetworkRequest &request, LxDialogBase* pdiaglogbase, bool requestFileName = false);
	inline void download(const QUrl &url, LxDialogBase* pdiaglogbase, bool requestFileName = false)
	{
		download(QNetworkRequest(url), pdiaglogbase, requestFileName);
	}
};

#endif // LXDOWNLOADMANAGER_H

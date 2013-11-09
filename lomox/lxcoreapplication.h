/*******************************************************************************
* 版权所有(C) 2011-2012  caidongyun All Rights Reserved.
*
* 文件名称	: lxcoreapplication.h
* 作    者	: 蔡东赟
* 创建日期	: 2012/2/6
* 功能描述	: 
  add resources 陈湘跃 (mailto:291307963@qq.com)
* 备    注	: 
********************************************************************************/
#ifndef __LXCOREAPPLICATION_H__
#define __LXCOREAPPLICATION_H__

#include "lomox_global.h"
#include "stdafx.h"

#include "lxbasewin.h"
#include "lxdialogs.h"
#include "lxcoreprivate.h"
#include "lxlibmanager.h"
#include "lxfile.h"
#include "lxdir.h"


class LxOperate;
class LxDialogs;
class LxCoreApplicationPrivate;
class LxFile;
class LxDir;
class LxLibManager;

typedef QVector<LxBaseWin*> LxWinContainer;

class LOMOX_EXPORT LxCoreApplication : public LxOperate
{
	Q_OBJECT

    Q_PROPERTY (QObject* libs READ getLib)
	Q_PROPERTY (QObject* dialogs READ getDialogs)
    Q_PROPERTY(QObject* file READ getFile)
    Q_PROPERTY(QObject* dir READ getDir)
    Q_PROPERTY(QVariant appPath READ getAppPath)
    Q_PROPERTY(QVariant args READ getArguments)
    Q_PROPERTY(QVariant version READ getVersion)

	Q_PROPERTY(QObject* net	 READ getHttpTool)

	Q_PROPERTY(QObject* res READ getResources)

public:
    explicit LxCoreApplication(QObject* object, QWebView* pWebView, QString strApiName =  QString(LOMOX_API_COREAPP));
 	virtual ~LxCoreApplication();

private slots:
	QObject* getDialogs() const;
    QObject* getLib()const;
    QObject* getFile()const;
    QObject* getDir()const;
	QVariant getArguments() const;
	QVariant getVersion() const;
    QVariant getAppPath() const;
	void     clearMemoryCaches();

	QObject* getHttpTool();

	QObject* getResources();

public:
	LxBaseWin* getMainDialog();

private:
	QString m_strApiName;
	QPointer<LxBaseWin> m_ptrCurrentView;//LOMOX全局 关联到的page
	QPointer<QWebPage> m_ptrCurrentWebPage;//LOMOX全局 关联到的page
    QPointer<LxLibManager> m_pLibMgr;
    QPointer<LxFile> m_pFile;
    QPointer<LxDir> m_pDir;
	QPointer<QObject> m_pHttp;
	QPointer<QObject> m_pResource;
};
#endif // end of __LXCOREAPPLICATION_H__

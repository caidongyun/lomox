/*******************************************************************************
* 版权所有(C) 2011-2012  caidongyun All Rights Reserved.
*
* 文件名称	: lxwindows.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/2/6
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __LXDIALOGS_H__
#define __LXDIALOGS_H__

#include "lxdialogoperate.h"
#include "lxbasewin.h"
#include "lxcoreapplication.h"
#include "lxmainwin.h"
class LxMainWindow;


class LxCoreApplication;


class LOMOX_EXPORT LxDialogs : public QObject
{
	Q_OBJECT
public:
	LxDialogs(QObject* parent = 0);
	virtual ~LxDialogs();

public slots:
	//virtual QObject* item(QVariant varIndex);
	virtual void append(QString key,LxDialogBase* pLxDialog);
	virtual QObject* get(QString varKey);
	virtual QVariant count();
	virtual QObject* add( QString key,QString url );
	virtual QVariant remove( QString key);
	virtual void closeAll();
private:
	QMap<QString,LxDialogBase *> m_mapDialogs;
	QPointer<LxMainWindow> m_ptrMainWin;
};
#endif // end of __LXWINDOWS_H__

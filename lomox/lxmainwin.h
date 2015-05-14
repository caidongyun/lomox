

/*******************************************************************************
* 版权所有(C) 1988-2014 All Rights Reserved.
*
* 文件名称	: basewin.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011/11/3
* 功能描述	:
* 备    注	:
********************************************************************************/

#ifndef __LXMAINWIN_H__
#define __LXMAINWIN_H__

#include "lomox_global.h"

#include "lxoption.h"
#include "lxcoreapplication.h"
#include "lxcoreprivate.h"
#include <QtWidgets/QWidget>


class LOMOX_EXPORT LxMainWindow : public QWebView
{
	Q_OBJECT
public:
	explicit LxMainWindow(QWidget* prarent = 0);

	virtual ~LxMainWindow();

public:
	void triggerPageAction(QWebPage::WebAction action, bool checked /*= false*/);
	void showMax();
public slots:
 	void linkClickedAction( const QUrl& url );

protected:
	void showEvent(QShowEvent *e);
	bool event(QEvent* e);

private:
	bool _initWidget();

private:
	QString m_strApiName;
	QPointer<QWebPage> m_ptrPage;
	QPointer<LxWebPluginFactory> m_ptrPlugin;
	bool m_bLoadHrefInCurrent;
	
};


#endif

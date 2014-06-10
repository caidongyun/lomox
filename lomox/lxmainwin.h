

/*******************************************************************************
* ��Ȩ����(C) 1988-2014 All Rights Reserved.
*
* �ļ�����	: basewin.cpp
* ��    ��	: �̶��S (mailto:caidongyun19@qq.com)
* ��������	: 2014/3/9
* ��������	: 
* ��    ע	: 
********************************************************************************/

#ifndef __LXMAINWIN_H__
#define __LXMAINWIN_H__

#include "lomox_global.h"

#include "lxoption.h"
#include "lxcoreapplication.h"
#include "lxcoreprivate.h"
#include <QtGui/QWidget>


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

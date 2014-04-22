/*******************************************************************************
* 版权所有(C) 1988-2011 All Rights Reserved.
*
* 文件名称	: basewin.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011/11/3
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __BASEWIN_H__
#define __BASEWIN_H__

#include "lomox_global.h"
#include "stdafx.h"
class LxOperate;
class LxWebPluginFactory;

typedef QVector<LxOperate*> JsApiObjectContainer;

class LOMOX_EXPORT LxBaseWin : public QWebView
{
	Q_OBJECT

public:
	explicit LxBaseWin(QWidget *parent = 0);
	virtual ~LxBaseWin();

public:
	   void triggerPageAction(QWebPage::WebAction action, bool checked = false);

private:
	bool _initWidget();

public slots:
	void linkClickedAction(const QUrl& url);

protected:
	
	void showEvent(QShowEvent *e);
	bool event(QEvent* e);

private:
	JsApiObjectContainer m_vecApiObjectContain;
	QString m_strApiName;
	QPointer<QWebPage> m_ptrPage;
	QPointer<LxWebPluginFactory> m_ptrPlugin;
};
#endif // end of __BASEWIN_H__

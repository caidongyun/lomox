/*******************************************************************************
* 版权所有(C) 2011-2011 LomoX. caidongyun All Rights Reserved.
*
* 文件名称	: operate.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011/12/14
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __OPERATE_H__
#define __OPERATE_H__

#include "lomox_global.h"

#include <QObject>

class LOMOX_EXPORT LxOperate : public QObject
{
	Q_OBJECT
public:
	LxOperate(QObject *parent = 0, QWebView* pWebView = 0, QString strApiName = "");
	~LxOperate();

public slots:
	bool setupJsAPIObject();//封闭js api的名称 强制在内部实现

protected:
	QPointer<QWebView> m_ptrWebView;
	QPointer<QWebPage> m_ptrWebPage;
	QString m_strApiName;
};

#endif // end of __OPERATE_H__

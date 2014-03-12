/*******************************************************************************
* 版权所有(C) 2011-2012  caidongyun All Rights Reserved.
*
* 文件名称	: lxWebPage.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/2/13
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __LXWEBPAGE_H__
#define __LXWEBPAGE_H__

class LxWebPage : public QWebPage
{
public:
	explicit LxWebPage(QObject *parent = 0);
	virtual ~LxWebPage();
public slots:
};
#endif // end of __LXWEBPAGE_H__

/*******************************************************************************
* 版权所有(C) 2010-2013 caidongyun. All Rights Reserved.
*
* 文件名称	: lxpluginbase.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2013/4/23
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __LXPLUGINBASE_H__
#define __LXPLUGINBASE_H__


class LxPluginBase : public QObject
{
public:
	LxPluginBase(QObject* parent):QObject(parent){}
	virtual LxPluginBase(){}

};


#endif // end of __LXPLUGINBASE_H__

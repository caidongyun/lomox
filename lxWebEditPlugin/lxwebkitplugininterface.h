/*******************************************************************************
* 版权所有(C) 2011-2011 LomoX. zch.fly All Rights Reserved.
*
* 文件名称	: lxWebKitPluginInteface.h
* 作    者	: 詹晨辉 (mailto:zch.fly@gmail.com)
* 创建日期	: 2012/09/17
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __LXWEBKITPLUGININTEFACE_H__
#define __LXWEBKITPLUGININTEFACE_H__

#include <qwebpluginfactory.h>
class LxWebKitPluginInterface
{
public:
	virtual ~LxWebKitPluginInterface(){};
	virtual QList<QWebPluginFactory::Plugin> plugins()const =0;
	virtual QObject *create(const QString &mimeType,
		const QUrl &url,
		const QStringList &argumentNames,
		const QStringList &argumentValues) const =0;
};

Q_DECLARE_INTERFACE(LxWebKitPluginInterface, "LomoXTeam/1.0")

#endif // __LXWEBKITPLUGININTEFACE_H__
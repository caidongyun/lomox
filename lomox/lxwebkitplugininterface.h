/*******************************************************************************
* ��Ȩ����(C) 2011-2011 LomoX. zch.fly All Rights Reserved.
*
* �ļ�����	: lxWebKitPluginInteface.h
* ��    ��	: ղ���� (mailto:zch.fly@gmail.com)
* ��������	: 2012/09/17
* ��������	: 
* ��    ע	: 
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
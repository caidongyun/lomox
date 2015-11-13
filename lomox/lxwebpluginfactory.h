/*******************************************************************************
* 版权所有(C) 2011-2011 LomoX. zch.fly All Rights Reserved.
*
* 文件名称	: lxwebpluginfactory.h
* 作    者	: 詹晨辉 (mailto:zch.fly@gmail.com)
* 创建日期	: 2012/09/17
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __LXWEBPLUGINFACTORY_H__
#define __LXWEBPLUGINFACTORY_H__
#include <qwebpluginfactory.h>

class LxWebKitPluginInterface;

class LxWebPluginFactory: public QWebPluginFactory
{
	Q_OBJECT
public:
	LxWebPluginFactory(QObject *parent = 0);
	~LxWebPluginFactory();

	QList<QWebPluginFactory::Plugin> plugins()const;

	void getPluginsFromPath( QString strPath, QList<QWebPluginFactory::Plugin> &plugins ) const;
	//void refreshPlugins();

	QObject *create(const QString &mimeType,
		const QUrl &url,
		const QStringList &argumentNames,
		const QStringList &argumentValues) const ;

	bool extension(QWebPluginFactory::Extension extension,
		const QWebPluginFactory::ExtensionOption *option = 0, 
		QWebPluginFactory::ExtensionReturn *output = 0){return true;};

	bool supportsExtension(QWebPluginFactory::Extension extension) const{return true;};
private:
	// 用于将载入的插件记录下来
    mutable QList< QList<QWebPluginFactory::Plugin> > m_pluginslist;
	mutable QList<LxWebKitPluginInterface *> m_interfaces;
};



#endif	//__LXWEBPLUGINFACTORY_H__

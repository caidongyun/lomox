/*******************************************************************************
* 版权所有(C) 2011-2011 LomoX. zch.fly All Rights Reserved.
*
* 文件名称	: LxWebEditPlugin.h
* 作    者	: 詹晨辉 (mailto:zch.fly@gmail.com)
* 创建日期	: 2012/09/17
* 功能描述	: 
* 备    注	: 简单的一个插件
********************************************************************************/
#ifndef LXWEBEDITPLUGIN_H
#define LXWEBEDITPLUGIN_H

#include "lxwebeditplugin_global.h"
#include "lxwebkitplugininterface.h"
#include <QTextEdit>

class LXWEBEDITPLUGIN_EXPORT LxWebEditPlugin : public QObject, public LxWebKitPluginInterface
{
	Q_OBJECT
	Q_INTERFACES(LxWebKitPluginInterface) //声明lxWebKitPluginInteface是一个接口

public:
	LxWebEditPlugin(): LxWebKitPluginInterface(){};
	~LxWebEditPlugin() {};

	QList<QWebPluginFactory::Plugin> plugins()const ;
	QObject *create(const QString &mimeType,
		const QUrl &url,
		const QStringList &argumentNames,
		const QStringList &argumentValues) const ;

private:

};

class MyAddEdit :public QTextEdit
{
	Q_OBJECT
public:
	MyAddEdit():QTextEdit(){};
	~MyAddEdit(){};

public Q_SLOTS:
	//返回相加的结果并设置当前文本为结果
	int AddNum(int a, int b, int c);
};

#endif // LXWEBEDITPLUGIN_H

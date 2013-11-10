#ifndef LXWEBEDITPLUGIN_H
#define LXWEBEDITPLUGIN_H

#include "lxwebeditplugin_global.h"
#include "lxwebkitplugininterface.h"
#include <QTextEdit>

class LXWEBEDITPLUGIN_EXPORT LxWebEditPlugin : public QObject, public LxWebKitPluginInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")
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

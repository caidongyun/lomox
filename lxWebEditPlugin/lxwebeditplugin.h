#ifndef LXWEBEDITPLUGIN_H
#define LXWEBEDITPLUGIN_H

#include "lxwebeditplugin_global.h"
#include "lxwebkitplugininterface.h"
#include <QTextEdit>

class LXWEBEDITPLUGIN_EXPORT LxWebEditPlugin : public QObject, public LxWebKitPluginInterface
{
	Q_OBJECT
	Q_INTERFACES(LxWebKitPluginInterface) //����lxWebKitPluginInteface��һ���ӿ�

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
	//������ӵĽ�������õ�ǰ�ı�Ϊ���
	int AddNum(int a, int b, int c);
};

#endif // LXWEBEDITPLUGIN_H

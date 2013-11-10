#include "lxwebeditplugin.h"
#include <QtPlugin>
#include <QUrl>
#include <QDebug>
QList<QWebPluginFactory::Plugin> LxWebEditPlugin::plugins()const
{
	QWebPluginFactory::MimeType mimeType;
	mimeType.name = "application/x-lomox-MyAddEdit";
	mimeType.description = QObject::tr("edit");
	//mimeType.fileExtensions.append(".flv");

	QList<QWebPluginFactory::MimeType> mimeTypes;
	mimeTypes.append(mimeType);

	QWebPluginFactory::Plugin plugin;
	plugin.name = QObject::tr("MyAddEdit plugin");
	plugin.description = QObject::tr("MyAddEdit Test !!!");
	plugin.mimeTypes = mimeTypes;

	QList<QWebPluginFactory::Plugin> plugins ;
	plugins.append(plugin);
	return plugins;
}
QObject *LxWebEditPlugin::create(const QString &mimeType,
							 const QUrl &url,
							 const QStringList &argumentNames,
							 const QStringList &argumentValues) const
{
	//插件类型必须继承于QWidget或者QGraphicsWidget，下面edit就一个插件
	MyAddEdit * edit = new MyAddEdit();
	edit->setObjectName("我是插件");
	edit->setPlainText(mimeType + " : " + url.toString() +"\n\n"
		+QString::fromLocal8Bit("这里是一个重载QTextEdit的自定义控件，")+"\n"
		+QString::fromLocal8Bit("它有一个加法功能。点击sumall进行测试") );

	Q_UNUSED(argumentNames);
	Q_UNUSED(argumentValues);
	qDebug()<<"create MyAddEdit plugin";
	return edit;  //返回一个object 
}


//Q_EXPORT_PLUGIN2()必不可少，
//只有这样插件类才为外部可见，插件名为lxWebEditPlugin
//Q_EXPORT_PLUGIN("lxWebEditPlugin", LxWebEditPlugin)

int MyAddEdit::AddNum(int a, int b, int c)
{
	int sum = a + b + c;
	this->setPlainText(QString::fromLocal8Bit("你通过JS调用了该方法，Sum = ") + QString::number(sum,10));
	return sum;
}
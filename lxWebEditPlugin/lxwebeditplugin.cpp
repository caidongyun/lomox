/*******************************************************************************
* ��Ȩ����(C) 2011-2011 LomoX. zch.fly All Rights Reserved.
*
* �ļ�����	: LxWebEditPlugin.cpp
* ��    ��	: ղ���� (mailto:zch.fly@gmail.com)
* ��������	: 2012/09/17
* ��������	: 
* ��    ע	: �򵥵�һ�����
********************************************************************************/
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
	//������ͱ���̳���QWidget����QGraphicsWidget������edit��һ�����
	MyAddEdit * edit = new MyAddEdit();
	edit->setObjectName("���ǲ��");
	edit->setPlainText(mimeType + " : " + url.toString() +"\n\n"
		+QString::fromLocal8Bit("������һ������QTextEdit���Զ���ؼ���")+"\n"
		+QString::fromLocal8Bit("����һ���ӷ����ܡ����sumall���в���") );

	Q_UNUSED(argumentNames);
	Q_UNUSED(argumentValues);
	qDebug()<<"create MyAddEdit plugin";
	return edit;  //����һ��object 
}


//Q_EXPORT_PLUGIN2()�ز����٣�
//ֻ������������Ϊ�ⲿ�ɼ��������ΪlxWebEditPlugin
//Q_EXPORT_PLUGIN2("lxWebEditPlugin", LxWebEditPlugin)
Q_PLUGIN_METADATA("lxWebEditPlugin", LxWebEditPlugin)


int MyAddEdit::AddNum(int a, int b, int c)
{
	int sum = a + b + c;
	this->setPlainText(QString::fromLocal8Bit("��ͨ��JS�����˸÷�����Sum = ") + QString::number(sum,10));
	return sum;
}
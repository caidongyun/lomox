
#include "lxwebpluginfactory.h"
#include "lxWebKitPluginInterface.h"
#include "lxdir.h"

LxWebPluginFactory::LxWebPluginFactory(QObject *parent):QWebPluginFactory()
{
	qDebug()<<"debug : WebkitPluginFactory";
}

LxWebPluginFactory::~LxWebPluginFactory()
{
}


QList<QWebPluginFactory::Plugin> LxWebPluginFactory::plugins() const
{
	QStringList strList = QCoreApplication::libraryPaths();

	static bool isFirst = true;
	static QList<QWebPluginFactory::Plugin> plugins;
	if(!isFirst)
		return plugins;

	isFirst = false;
	plugins.clear();

	for (int i = 0; i < strList.size(); ++i)
			getPluginsFromPath(strList.at(i), plugins);

	if(plugins.isEmpty())
		qDebug()<<"no plugins is loaded!";

	return plugins;
}
// void LxWebPluginFactory::refreshPlugins()
// {
// 	Reload();
// }

QObject * LxWebPluginFactory::create(const QString &mimeType,
								   const QUrl &url,
								   const QStringList &argumentNames,
								   const QStringList &argumentValues) const
{
	for(int i=0; i<m_pluginslist.size(); i++)
	{
		for( int j=0; j< m_pluginslist[i].size(); j++)
		{
			foreach(LxWebPluginFactory::MimeType mt, m_pluginslist[i][j].mimeTypes)
			{
				if(mt.name.toUpper() == mimeType.toUpper()) //���ҵ�(�����ִ�Сд)������ʵ��
					return m_interfaces[i]->create( mimeType, url, argumentNames, argumentValues);
			}
		}
	}
	return NULL; //���û�У�ֱ�ӷ���NULL��webkit����д����
}

void LxWebPluginFactory::getPluginsFromPath( QString strPath, QList<QWebPluginFactory::Plugin> &plugins ) const
{
	QDir dir(strPath);
	QStringList filters;
	QString abspath = dir.absolutePath();
	qDebug()<<abspath;

	//��ȡָ��Ŀ¼�µ����в����linux���ǲ����ĺ�׺Ϊso��windows������dll��
#ifdef _WINDOWS_
	filters<<"*.dll";
#elif defined LINUX
	filters<<"lib*.so";
#endif

	QStringList files = dir.entryList(filters);
	qDebug()<<"files: "<<files;
	foreach(QString file , files)
	{
		qDebug()<<QLibrary::isLibrary(file);
		file = dir.filePath(file);
		qDebug()<<"path: "<<file;
		QPluginLoader loader(file);
		QObject * obj = loader.instance();
		if(obj==0)
			qDebug()<<"error: "<<loader.errorString();
		//�����������Զ���Ľӿڣ�ֻ����������֧�ֶ�̬�������������̶����ˣ�����������չ
		LxWebKitPluginInterface * interface = qobject_cast<LxWebKitPluginInterface*> (obj);
		if(nullptr == interface)
		{
			qDebug()<<"ignore error when loading plugin" ;
			continue;
		}
		qDebug()<<"load plugins: "<<interface->plugins().at(0).name;
		plugins.append(interface->plugins());
		m_pluginslist.append(interface->plugins());
		m_interfaces.append(interface);
	}
}


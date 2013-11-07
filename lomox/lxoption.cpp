/*******************************************************************************
* ��Ȩ����(C) 2010-2013 lomox caidongyun. All Rights Reserved.
*
* �ļ�����	: lxoption.cpp
* ��    ��	: �̶��S (mailto:caidongyun19@qq.com)
* ��������	: 2013/3/9
* ��������	: 
* ��    ע	: 
********************************************************************************/
#include "lomox_global.h"
#include "lxoption.h"


LxOption::LxOption( QObject* parent )
:QObject(parent)
{

}

LxOption::~LxOption()
{

}


QString LxOption::getStartResourceFileName()
{
	return QCoreApplication::applicationDirPath() + "/Resources/main.lx";
}

//����������Ŀ
/*
// main.lx //��Դ��
//main.html";
//lomoxdemo.html
//index.html
*/
QString LxOption::getStartUrl()
{
	QString strFilePath = QCoreApplication::applicationDirPath() + "/Resources/";

	QString strResCab = getStartResourceFileName();
	QString strMainHtml = strFilePath + "main.html";
	QString strDemoHtml = strFilePath + "lomoxdemo.html";
	QString strIndex = strFilePath + "index.html";

	
	if (QFile::exists(strResCab))
	{
		//ע����Դ������main ����index�ڵ�
		QResource::registerResource(strResCab);
		return QString::fromLocal8Bit("qrc:/pack/main.html");

	}
	else if (QFile::exists(strMainHtml))
	{
		return strMainHtml;
	}
	else if (QFile::exists(strDemoHtml))
	{
		return strDemoHtml;
	}
	else if (QFile::exists(strIndex))
	{
		return strIndex;
	}
	return QString();
}

QString LxOption::getAppPath()
{
	return QCoreApplication::applicationDirPath();
}

QObject* LxOption::getCoreAppOption()
{
	return qApp;
}

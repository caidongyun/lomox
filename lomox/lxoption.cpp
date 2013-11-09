/*******************************************************************************
* 版权所有(C) 2010-2013 lomox caidongyun. All Rights Reserved.
*
* 文件名称	: lxoption.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2013/3/9
* 功能描述	: 
* 备    注	: 
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

//兼容启动项目
/*
// main.lx //资源包
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
		//注册资源，返回main 或者index节点
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

/*******************************************************************************
* 版权所有(C) 
*
* 文件名称	: networkcookie.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011-6-30
* 功能描述	: 在程序结束的时候保存cookie在本地
* 备    注	: 
********************************************************************************/
#include "lomox_global.h"
#include "lxnetworkcookie.h"

LxNetWorkCookies::LxNetWorkCookies (QString path, QObject *parent) : QNetworkCookieJar(parent)
 {
    file=path; 

    QFile cookieFile(this->file);
	if (cookieFile.exists() && cookieFile.open(QIODevice::ReadOnly) )
	{
		QList<QNetworkCookie> list;
		QByteArray line;
		while(!(line = cookieFile.readLine()).isNull())
		{
			list.append(QNetworkCookie::parseCookies(line )); 
		}
		setAllCookies(list);
		cookieFile.close();
	}
	else  
	{
	
	}
	
}

LxNetWorkCookies::~LxNetWorkCookies ()
{
//	析构时不需要读取Cookie再重新保存，先屏蔽析构时保存Cookie
// 	SaveCookie();
}

QList<QNetworkCookie> LxNetWorkCookies::cookiesForUrl ( const QUrl & url ) const
{
	return QNetworkCookieJar::cookiesForUrl(url);
}

bool LxNetWorkCookies::setCookiesFromUrl ( const QList<QNetworkCookie> & cookieList, const QUrl & url )
{
	bool bOk = QNetworkCookieJar::setCookiesFromUrl(cookieList, url);
	QString strTest = url.toString();

	SaveCookie();
	return bOk;//只返回设置成功与否 保存失败不做处理
}

bool LxNetWorkCookies::SaveCookie()
{
	QList <QNetworkCookie> cookieList;
	cookieList = allCookies();

	QFile file(this->file);

	if (!file.open((QIODevice::ReadWrite | QIODevice::Text)))
	{
		qWarning() << "Impossible d'ouvrir "<< this->file << " pour y stocker les cookies !";
		return false;
	}
	std::vector<QString> vecString;
	QTextStream readFile(&file);
	while (!readFile.atEnd())
	{
		vecString.push_back(QString::fromUtf8(readFile.readLine().toUtf8()));
	}
	file.close();

	for (int i = 0; i < cookieList.size(); i++)
	{
		bool bFind = false;
		QString strLine = cookieList.at(i).toRawForm(QNetworkCookie::Full);
		QString strLineHeader = strLine.left(strLine.indexOf(QString("=")));
		for (size_t j = 0; j < vecString.size(); j++)
		{
			QString strElement = vecString.at(j);
			QString strElementHeader = strElement.left(strElement.indexOf(QString("=")));
			if (strLineHeader == strElementHeader)
			{
				bFind = true;
				vecString[j] = strLine;
				break;
			}
		}
		if (!bFind)
			vecString.push_back(strLine);
	}


	if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		qWarning() << "Impossible d'ouvrir "<< this->file << " pour y stocker les cookies !";
		return false;
	}

	QTextStream out(&file);

	for(size_t i = 0 ; i < vecString.size() ; i++)
	{
		QString line =  vecString.at(i);
		out << line.toUtf8() << "\n";
	}

	file.close();
	return true;
}
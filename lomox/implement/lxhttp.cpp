/*******************************************************************************
* 版权所有(C) 2010-2012 LomoX. All Rights Reserved.
*
* 文件名称	: lxhttp.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/10/19
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#include "lomox_global.h"
#include "lxHttp.h"


LxHttp::LxHttp( QObject* parent )
:QObject(parent)
{

}

LxHttp::~LxHttp()
{

}

QVariant LxHttp::httpRequest(QVariant varMethod,  QVariant varUrl ,  QVariant varPostData)//, QScriptEngine *interpreter
{
	enum LxHttpMethod
	{
		GET,
		POST
	};

	QString url = "";
	QString data ="";

	LxHttpMethod method = GET;

	if (varMethod.isNull() || varUrl.isNull()) 
	{
		return QVariant(0);
	}

		QString arg = varMethod.toString().trimmed().toUpper();
		method = (arg == "POST") ?  POST : GET;

		url = varUrl.toString().trimmed();

	if (0 != url.toLower().indexOf("http://")) 
	{
		return QVariant("URIError: URL is not http://");
	}

	data = varPostData.toString();

	QNetworkReply* reply;
	QNetworkRequest req;
	QNetworkAccessManager* manager = new QNetworkAccessManager();

	if (method == POST) 
	{
		// post 数据编码
		req.setUrl(QUrl(url));
		req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
		reply = manager->post(req, QUrl(data).toEncoded());
	} else
	{
		if (data != "")
		{
			if (url.indexOf("?") != -1)
			{
				if (url.lastIndexOf("&") == url.size() - 1)
				{
					url = url + data;
				}
				else
				{
					url = url + "&" + data;
				}
			}
			else 
			{
				url= url + "?" + data;
			}
		}

		reply = manager->get(QNetworkRequest(QUrl(url)));
	}

	// 开启局部事件循环
	QEventLoop eventLoop;
	connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	eventLoop.exec();

	QByteArray responseData;
	responseData = reply->readAll();

	QString charset = QString(reply->rawHeader("Content-Type")).toLower();
	QRegExp charsetRegExp("charset=([\\w-]+)\\b");
	int pos = charset.indexOf(charsetRegExp);
	if (pos > 0) 
	{
		if (charsetRegExp.cap().size() < 2) 
		{
			charset = "";
		}
		else 
		{
			charset = charsetRegExp.cap(1);
		}
	} 
	else 
	{
		charset = "";
	}

	QTextStream stream(responseData);
	stream.setCodec(QTextCodec::codecForName(QByteArray("utf-8")));//charset.toLocal8Bit()
	return QVariant(QString(stream.readAll()));
}

QVariant LxHttp::httpRequestWithEncode(QVariant varMethod,  QVariant varUrl ,  QVariant varPostData, QVariant varEncode)//
{
	enum LxHttpMethod
	{
		GET,
		POST
	};

	QString url = "";
	QString data ="";

	LxHttpMethod method = GET;

	if (varMethod.isNull() || varUrl.isNull()) 
	{
		return QVariant(0);
	}

	QString arg = varMethod.toString().trimmed().toUpper();
	method = (arg == "POST") ?  POST : GET;

	url = varUrl.toString().trimmed();

	if (0 != url.toLower().indexOf("http://")) 
	{
		return QVariant("URIError: URL is not http://");
	}

	data = varPostData.toString();

	QNetworkReply* reply;
	QNetworkRequest req;
	QNetworkAccessManager* manager = new QNetworkAccessManager();

	if (method == POST) 
	{
		// post 数据编码
		req.setUrl(QUrl(url));
		req.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
		reply = manager->post(req, QUrl(data).toEncoded());
	} else
	{
		if (data != "")
		{
			if (url.indexOf("?") != -1)
			{
				if (url.lastIndexOf("&") == url.size() - 1)
				{
					url = url + data;
				}
				else
				{
					url = url + "&" + data;
				}
			}
			else 
			{
				url= url + "?" + data;
			}
		}

		reply = manager->get(QNetworkRequest(QUrl(url)));
	}

	// 开启局部事件循环
	QEventLoop eventLoop;
	connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
	eventLoop.exec();

	QByteArray responseData;
	responseData = reply->readAll();

	QString charset = QString(reply->rawHeader("Content-Type")).toLower();
	QRegExp charsetRegExp("charset=([\\w-]+)\\b");
	int pos = charset.indexOf(charsetRegExp);
	if (pos > 0) 
	{
		if (charsetRegExp.cap().size() < 2) 
		{
			charset = "";
		}
		else 
		{
			charset = charsetRegExp.cap(1);
		}
	} 
	else 
	{
		charset = "";
	}


	QString strCodeDec = QString::fromLocal8Bit("utf-8");
	if (!varEncode.isNull() && varEncode.isValid())
	{
		QString strTemp = varEncode.toString() ;
		if (!strTemp.isEmpty())
		{
			strCodeDec = strTemp;
		}
	}
	QTextStream stream(responseData);
	stream.setCodec(QTextCodec::codecForName(strCodeDec.toLocal8Bit()));//
	return QVariant(QString(stream.readAll()));
}


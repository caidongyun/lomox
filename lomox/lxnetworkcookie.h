/*******************************************************************************
* 版权所有(C)
*
* 文件名称	: networkcookie.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011-6-30
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __NETWORKCOOKIE_H__
#define __NETWORKCOOKIE_H__
#include <QtNetwork/QNetworkCookie>
#include <QNetworkCookieJar>
class LxNetWorkCookies : public QNetworkCookieJar
{
	Q_OBJECT
public:
    LxNetWorkCookies (QString path, QObject *parent = 0);  
    ~LxNetWorkCookies (); 
    QList<QNetworkCookie> cookiesForUrl ( const QUrl & url ) const;//返回指定url的cookie
    bool setCookiesFromUrl ( const QList<QNetworkCookie> & cookieList, const QUrl & url );// 写cookie的时候会调用到

	bool SaveCookie();//保存到自己指定的地方，未加密

private:
	QString file; 
};

#endif // end of __NETWORKCOOKIE_H__

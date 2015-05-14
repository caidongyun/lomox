/*******************************************************************************
* 版权所有(C) 2011-2012  caidongyun All Rights Reserved.
*
* 文件名称	: lxwebpage.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/2/13
* 功能描述	:
* 备    注	:
********************************************************************************/
#include "lomox_global.h"
#include "lxwebpage.h"


LxWebPage::LxWebPage(QObject *parent /*= 0*/)
:QWebPage(parent)
{
	setForwardUnsupportedContent(true);
	connect(this, SIGNAL(featurePermissionRequested(QWebFrame*, QWebPage::Feature)), this, SLOT(permissionRequested(QWebFrame*, QWebPage::Feature)));
	connect(this, SIGNAL(unsupportedContent(QNetworkReply*)), this, SLOT(handleUnsupportedContent(QNetworkReply*)));
}

LxWebPage::~LxWebPage()
{

}

void LxWebPage::permissionRequested(QWebFrame* frame, QWebPage::Feature feature)
{
	setFeaturePermission(frame, feature, PermissionGrantedByUser);
}

void LxWebPage::handleUnsupportedContent(QNetworkReply *reply)
{
	if (!reply) {
		return;
	}

	const QUrl url = reply->url();

	switch (reply->error()) {
	case QNetworkReply::NoError:{
		if (0 == reply->header(QNetworkRequest::ContentTypeHeader).toString().toLower().indexOf("text"))
		{
			qDebug() << "QNetworkReply::NoError -- openwindow" <<url;
			emit linkClicked(url);//发送打开新连接信号(发给webpage==>webview)
		}
		qDebug() << "QNetworkReply::NoError -- downlaod" << url;
		QNetworkRequest request(url);
		emit downloadRequested(request);
		return;
	}
	case QNetworkReply::ProtocolUnknownError:{
		if (url.scheme() == QLatin1String("file")) {
			qDebug() << "QNetworkReply::ProtocolUnknownError -- openwindow" << url;
			emit linkClicked(url);
			return;
		}
		if (url.scheme() == QLatin1String("ftp")) {
			qDebug() << "QNetworkReply::ProtocolUnknownError -- downlaod" << url;
			QNetworkRequest request(url);
			emit downloadRequested(request);
			return;
		}
		qDebug() << "WebPage::UnsupportedContent" << url << "ProtocolUnknowError";
			//desktopServicesOpen(url);
			return;
		}
		default:
			break;
	}

	qDebug() << "WebPage::UnsupportedContent error" << url << reply->errorString();
}

bool LxWebPage::acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest&request, NavigationType type)
{
	//networkAccessManager()->setProperty("User-Agent", "Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1)");
	//QNetworkReply *reply = networkAccessManager()->get(request);
	if (type == QWebPage::NavigationTypeLinkClicked){//如果是用户点击
		QString strUrl = request.url().toString();
		qDebug() << "LinkClicked:" << strUrl;
// 		if (frame != this->currentFrame() && (0 == reply->header(QNetworkRequest::ContentTypeHeader).toString().toLower().indexOf("text")
// 			|| reply->header(QNetworkRequest::ContentTypeHeader).toString() == ""))
		if (frame != this->currentFrame())
		{
			qDebug() << "open new window:" << strUrl;
			emit linkClicked(strUrl);
			return false;
		}
// 		if (0 == strUrl.indexOf(QString("file:///")) || 0 == reply->header(QNetworkRequest::ContentTypeHeader).toString().toLower().indexOf("text"))
// 		{
// 			emit linkClicked(strUrl);//发送打开新连接信号(发给webpage==>webview)
// 			return false;
// 		}
	}
	return QWebPage::acceptNavigationRequest(frame, request, type);
}
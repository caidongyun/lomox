/*******************************************************************************
* 版权所有(C) 2011-2012www.LomoX.hk All Rights Follow Lomox licence.
*
* 文件名称	: lxdialogoperate.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011/12/4
* 功能描述	:
* 备    注	:
********************************************************************************/
#ifndef __DIALOGBASE_H__
#define __DIALOGBASE_H__

#include "lomox_global.h"
#include "stdafx.h"


class LOMOX_EXPORT LxDialogBase : public LxOperate
{
    Q_OBJECT
public:
    explicit LxDialogBase(QObject* object, QWebView* pWebView, QString strApiName,bool bshowloading = false,
		int gifW = 0,int gifH = 0);
    virtual ~LxDialogBase();

public slots:
    virtual void move();
    virtual void move(int x, int y);
    virtual void showMinimized();
    virtual void showMaximized();
    virtual void close();
    virtual void showNormal();

    virtual bool isMinimized();
    virtual bool isMaximized();
    virtual bool isFullScreen();

    virtual int minimumWidth();
    virtual int minimumHeight();
    virtual int maximumWidth();
    virtual int maximumHeight();
    virtual void setMinimumSize(int minw, int minh);
    virtual void setMaximumSize(int maxw, int maxh);
    virtual void setMinimumWidth(int minw);
    virtual void setMinimumHeight(int minh);
    virtual void setMaximumWidth(int maxw);
    virtual void setMaximumHeight(int maxh);

    virtual void show();
    virtual void setDialogWH(QVariant Weight, QVariant Hight);
    virtual void reload();
    virtual void openUrl(QVariant url);
    virtual int getTopLeftX();
    virtual int getTopLeftY();

    virtual void setUrl(QString strUrl);
    virtual void setVisible(bool visible);
    virtual void setHidden(bool hidden);

	virtual void printPreview();

    virtual QVariant eval( QVariant code);
    virtual QVariant toHTML();
    virtual void setHTML( QVariant code);
    virtual QObject* getCoreDialog();
private slots:
	void downloadRequested(const QNetworkRequest &request);
	void loadStarted(){};
	void loadProgress(int progress){};
	void loadFinished(bool);
private:
	QUrl m_url;
    QWebFrame* m_mainFrame;
	QLabel* m_label;
	bool m_showloading;
	int m_lablW;
	int m_lablH;
	double m_nWidth;
	double m_nHeight;
	QMovie* m_movie;
	QBoxLayout *m_layout;
};


#endif // end of __DIALOGBASE_H__



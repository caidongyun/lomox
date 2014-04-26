/*******************************************************************************
* 版权所有(C) 2010-2013 lomox caidongyun. All Rights Reserved.
* 
* 文件名称	: lxoption.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2013/3/9
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __LXOPTION_H__
#define __LXOPTION_H__

#include <QObject>

class LxOption : public QObject
{
	Q_OBJECT
public:
	LxOption(QObject* parent);
	virtual ~LxOption();

public slots:
	QString getStartResourceFileName();
	QString getStartUrl();
	QString getAppPath();
	QObject* getCoreAppOption();

// 	int getMainWithFromCfg();
// 	int getMainHigthFromCfg();
	QString getConfgPath();

	QString getMainTitle();

	bool getNeedShowMainNcFrame();
	bool getNeedShowChildNcFrame();

	bool getMainWindowStaysOnTopHint();
	QString getCookieFilePath();

	//href是否从本页加载刷新还是弹出新窗口
	bool getLoadHrefInCurrentMainDialog();
	bool getLoadHrefInCurrentChildDialog();

private:
	bool getValueFromIni(QString strKey, bool &bValue);
};




#endif // end of __LXOPTION_H__

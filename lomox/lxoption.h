/*******************************************************************************
* ��Ȩ����(C) 2010-2013 lomox caidongyun. All Rights Reserved.
* 
* �ļ�����	: lxoption.h
* ��    ��	: �̶��S (mailto:caidongyun19@qq.com)
* ��������	: 2013/3/9
* ��������	: 
* ��    ע	: 
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
};




#endif // end of __LXOPTION_H__

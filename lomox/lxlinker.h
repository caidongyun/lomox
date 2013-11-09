/*******************************************************************************
* 版权所有(C) 2011-2012www.LomoX.hk All Rights Follow Lomox licence.
*
* 文件名称	: lxlinker.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/2/19
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __LXLINKER_H__
#define __LXLINKER_H__

class LxBaseWin;

class LOMOX_EXPORT LxLinker : public QObject
{
public: 
	LxLinker(QObject* parent = 0);
	virtual ~LxLinker();

public slots:
	virtual bool setupJsApiObject();
	virtual bool linkObject(LxBaseWin* pView = 0, QString strApiName = QString(""), QObject* pObj = 0);

private:
	QPointer<LxBaseWin> m_ptrWebview;
	QPointer<QWebPage> m_ptrPage;
	QPointer<QObject> m_ptrObj;
	QString m_strApiName;
};


#endif // end of __LXLINKER_H__

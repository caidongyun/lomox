/*******************************************************************************
* ��Ȩ����(C) 2011-2012 LomoX. All Rights Follow Lomox1 licence.
*
* �ļ�����	: lxwindows.h
* ��    ��	: �̶��S (mailto:caidongyun19@qq.com)
* ��������	: 2012/2/6
* ��������	: 
* ��    ע	: 
********************************************************************************/
#ifndef __LXWINDOWS_H__
#define __LXWINDOWS_H__

class LOMOX_EXPORT LxWindows : public QObject
{
	Q_OBJECT
public:
	LxWindows(LxCoreApplication* lxApp, );
	virtual ~LxWindows();

public slots:
	virtual QObject* item(QVariant varIndex);
	virtual QVariant count();

private:
	QPointer<LxCoreApplication> m_ptrLxApp;
};
#endif // end of __LXWINDOWS_H__

/*******************************************************************************
* 版权所有(C) 2011-2012 LomoX. All Rights Follow Lomox1 licence.
*
* 文件名称	: lxwindows.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/2/6
* 功能描述	: 
* 备    注	: 
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

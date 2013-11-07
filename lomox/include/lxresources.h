/*******************************************************************************
* 版权所有(C) 2010-2013 LomoX caidongyun. All Rights Reserved.
*
* 文件名称	: lxresources.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2013/3/9
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __LXRESOURCES_H__
#define __LXRESOURCES_H__

#include <QObject>

class  LxResources : public QObject
{
	Q_OBJECT
public:
	LxResources(QObject* parent);
	virtual ~LxResources();

public slots:
	bool registerResource(QString rccFilename);

	bool unregisterResource(QString rccFilename);

	bool registerResourceFromRoot(QString rccFilename, QString resourceRoot);
	bool unregisterResourceFromRoot(QString rccFilename, QString resourceRoot);

};
#endif // end of __LXRESOURCES_H__

/*******************************************************************************
* ��Ȩ����(C) 2010-2013 LomoX caidongyun. All Rights Reserved.
*
* �ļ�����	: lxresources.h
* ��    ��	: �̶��S (mailto:caidongyun19@qq.com)
* ��������	: 2013/3/9
* ��������	: 
* ��    ע	: 
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

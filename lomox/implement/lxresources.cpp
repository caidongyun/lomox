/*******************************************************************************
* ��Ȩ����(C) 2010-2013 caidongyun. All Rights Reserved.
*
* �ļ�����	: lxresources.cpp
* ��    ��	: ����Ծ (mailto:291307963@qq.com)
* ��������	: 2013/3/9
* ��������	: 
* ��    ע	: 
********************************************************************************/
#include "lomox_global.h"
#include "lxresources.h"


LxResources::LxResources( QObject* parent )
:QObject(parent)
{

}

LxResources::~LxResources()
{

}

bool LxResources::registerResource( QString rccFilename )
{
		//Q_ASSERT(0);
	//��ʵ��
	return QResource::registerResource(rccFilename);
}

bool LxResources::unregisterResource( QString rccFilename )
{
	//Q_ASSERT(0);
	return QResource::unregisterResource(rccFilename);
}

bool LxResources::registerResourceFromRoot( QString rccFilename, QString resourceRoot )
{
	//��ʵ��
	return QResource::registerResource(rccFilename,resourceRoot);
}

bool LxResources::unregisterResourceFromRoot( QString rccFilename, QString resourceRoot )
{
	//����Ҫ�ж��ļ��Ƿ����

	return unregisterResourceFromRoot(rccFilename, resourceRoot);
}


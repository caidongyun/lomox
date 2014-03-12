/*******************************************************************************
* 版权所有(C) 2010-2013 caidongyun. All Rights Reserved.
*
* 文件名称	: lxresources.cpp
* 作    者	: 陈湘跃 (mailto:291307963@qq.com)
* 创建日期	: 2013/3/9
* 功能描述	: 
* 备    注	: 
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
	//待实现
	return QResource::registerResource(rccFilename);
}

bool LxResources::unregisterResource( QString rccFilename )
{
	//Q_ASSERT(0);
	return QResource::unregisterResource(rccFilename);
}

bool LxResources::registerResourceFromRoot( QString rccFilename, QString resourceRoot )
{
	//待实现
	return QResource::registerResource(rccFilename,resourceRoot);
}

bool LxResources::unregisterResourceFromRoot( QString rccFilename, QString resourceRoot )
{
	//还需要判断文件是否存在

	return unregisterResourceFromRoot(rccFilename, resourceRoot);
}


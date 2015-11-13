/*******************************************************************************
* 版权所(C) 2011-2012  caidongyun All Rights Reserved.
*
* 文件名称	: lxcoreapplication.cpp
* 作    者  : 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/2/6
* 功能描述	: 
* 备    注	: 
********************************************************************************/

#include "lomox_global.h"
#include "lxcoreapplication.h"
//#include <QtScript>
#include "lxHttp.h"
#include "lxresources.h"

LxCoreApplication::LxCoreApplication( QObject* object, QWebView* pWebView, QString strApiName /*= QString(LOMOX_API_COREAPP)*/ )
:LxOperate(object, pWebView, strApiName)
{
    m_pLibMgr = new LxLibManager(this);
    m_pLibMgr->initialize(m_ptrWebView);
   
	m_pFile = new LxFile(this);

    m_pDir = new LxDir(this);


}

LxCoreApplication::~LxCoreApplication()
{

}

QObject* LxCoreApplication::getDialogs() const
{
	return lxCoreApp->getDialogs();
}

QObject* LxCoreApplication::getFile() const
{
    if(m_pFile)
		return m_pFile;
    else 
		return nullptr;
}

QObject *LxCoreApplication::getDir() const
{
    if(m_pDir)
		return m_pDir;
    else 
		return nullptr;
}

QObject* LxCoreApplication::getLib()const
{
    if(m_pLibMgr)
		return m_pLibMgr;
    else
		return nullptr;
}

QVariant LxCoreApplication::getVersion() const
{
    return QString(LOMOX_VERSION);
}

QVariant LxCoreApplication::getAppPath() const
{
    return QCoreApplication::applicationDirPath();
}

QVariant LxCoreApplication::getArguments() const
{
	return QVariant(qApp->arguments());
}

/*******************************************************************************
* 函数名称	: LxCoreApplication::clearMemoryCaches
* 功能描述	: 清理内存
* 返 回 值	: bool
* 备　　注	: 蔡东赟[2012/6/12]
*******************************************************************************/
void LxCoreApplication::clearMemoryCaches()
{
	QWebSettings::clearMemoryCaches();
}

QObject* LxCoreApplication::getHttpTool()
{
	 m_pHttp = new LxHttp(this);
	return m_pHttp;
}

QObject* LxCoreApplication::getResources()
{
	m_pResource = new LxResources(this);
	return m_pResource;
}

int LxCoreApplication::execute( QVariant varProgram, QVariant varArguments )
{
	if (varProgram.isNull() || !varProgram.isValid())
		return 0;

	if (varArguments.isNull())
	{
		return QProcess::execute(varProgram.toString());
	}
	
	if (varArguments.type() == QVariant::String)
	{
		QStringList arg;
		arg.append(varArguments.toString());
		return QProcess::execute(varProgram.toString());
	}
	if (varArguments == QVariant::StringList)
	{
		return QProcess::execute(varProgram.toString(), varArguments.toStringList());
	}
	return 0;
}

// QVariant LxCoreApplication::exec( QString strProgram, QString strArguments )
// {
// 	QProcess* proc = new QProcess(this);
// 	proc->start(strProgram, strArguments);
// 
// 
// 	return 1;
// }

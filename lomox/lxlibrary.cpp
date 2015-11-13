/*******************************************************************************
* 版权所有(C) 2010-20122012 lomox.hk All Rights Reserved.
*
* 文件名称	: lxlibrary.cpp
* 作    者	: colin3dmax
* 创建日期	: before 2012/4/10
* 更新		：蔡东赟对编码格式进行整理 2012/4/10
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#include "lomox_global.h"
#include "lxlibrary.h"

LxLibrary::LxLibrary(QObject *parent)
:QObject(parent)
{

}

LxLibrary::~LxLibrary()
{
}

QVariant LxLibrary::load(QString dllPath )
{
    qDebug(dllPath.toLatin1().data());
    if(m_pLib.isNull())
    {
        m_pLib = new QLibrary(dllPath);
        if(m_pLib->load())
        {
            qDebug("dll success");
            return QVariant(true);
        }else
        {
             qDebug("dll erro 1");
            return QVariant(false);
        }
    }
    else 
    {
         qDebug("dll error 2");
        return QVariant(false);
    }
}

QVariant LxLibrary::exec(QString functionName, QVariant param,QString encode)
{
    qDebug("in exec now!");
    if (m_webView.isNull())return nullptr;

	QTextCodec::codecForName(encode.toLocal8Bit().data());
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName(encode.toLocal8Bit().data()));
    if((!m_pLib.isNull()) && m_pLib->isLoaded())
	{
        qDebug("exec now!");
        void * fun = (void *)m_pLib->resolve(functionName.toLocal8Bit().data());
        if(!fun)
            return nullptr;

        char * result = ((char *(*)(char *))fun)(param.toString().toLocal8Bit().data());
        qDebug(result);
        QString str(result);
        //借用Webkit 转换JSON格式
        QVariant myVal( m_webView->page()->mainFrame()->evaluateJavaScript( "("+str+")" ));
        if(myVal.isValid())
			return myVal;
        return QVariant(str);
    }
	else
	{
        return nullptr;
    }
}

QVariant LxLibrary::unload()
{
	//dll 必须做一次检查,否则会崩溃，建议做成成员变量，而不是 传出去的指针传回来
    if(!m_pLib.isNull())return QVariant(m_pLib->unload());
    else return QVariant(false);
}

void LxLibrary::initialize( QWebView* pWebView /*= 0*/ )
{
	m_webView = pWebView;
    if(pWebView)qDebug("m_webView initialized! not null");
}


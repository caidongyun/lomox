/*******************************************************************************
* 版权所有(C) 2010-20122012 lomox.hk All Rights Reserved.
*
* 文件名称	: lxlibrary.cpp
* 作    者	: colin3dmax
* 创建日期	: before 2012/4/10
* 功能描述	:
* 备    注	:
********************************************************************************/
#include "lxlibmanager.h"

LxLibManager::LxLibManager(QObject *parent) 
:QObject(parent)
{

}

LxLibManager::~LxLibManager()
{

}

void LxLibManager::initialize(QWebView *pWebView)
{
    if(!m_pWebView){
        m_pWebView = pWebView;
        qDebug("LxLibManager::initialize m_pWebView");
    }
}

QVariant LxLibManager::count()
{
    return m_mapLib.count();
}

QObject *LxLibManager::add(QString dllKey, QString dllPath)
{
    LxLibrary* lib=new LxLibrary();
    lib->initialize(m_pWebView.data());
    lib->load(dllPath);
    m_mapLib.insert(dllKey,lib);
    return lib;
}

QVariant LxLibManager::remove(QString dllKey)
{
    if(m_mapLib.contains(dllKey))
    {
        LxLibrary * lib = m_mapLib[dllKey];
        lib->unload();
        lib->deleteLater();
        return  QVariant(m_mapLib.remove(dllKey)>=1?true:false);
    }
    else
    {
        return QVariant(false);
    }
}

QObject *LxLibManager::get(QString dllKey)
{
    return m_mapLib[dllKey];
}



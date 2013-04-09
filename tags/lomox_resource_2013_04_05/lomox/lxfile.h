/*******************************************************************************
* 版权所有(C) 2011-2012www.LomoX.hk All Rights Follow Lomox licence.
*
* 文件名称	: lxfile.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/1/31
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef __LXFILE_H__
#define __LXFILE_H__

#include "lomox_global.h"

#include "lxoperate.h"
#include <QFile>

class LOMOX_EXPORT LxFile : public LxOperate
{
	Q_OBJECT
public:
	LxFile(QObject* parent = nullptr);
	explicit LxFile(QObject* object, QWebView* pWebView, QString strApiName);
	virtual ~LxFile();

public slots:
    virtual QVariant readFileData(QVariant varFilename,QString encode);//base64 MIMERYPE
    virtual QVariant isExits(QVariant varFilename);//
    virtual QVariant remove(QVariant varFilename);
    virtual QVariant rename(QVariant varOldName, QVariant varNewName);
    virtual QVariant link(QVariant oldname, QVariant newName);
    virtual QVariant copy(QVariant varFileName, QVariant varNewName);
    virtual QVariant size(QVariant varFilename);
	virtual QVariant permissions(QVariant varFilename);//
    virtual QVariant write(QVariant varFilename,QVariant text,QString encode="UTF-8");




};

#endif // end of __LXFILE_H__

/*******************************************************************************
* 版权所有(C) 2011-2012www.LomoX.hk All Rights Follow Lomox licence.
*
* 文件名称	: lxfile.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/1/31
* 功能描述	:
* 备    注	:
********************************************************************************/

#include "lomox_global.h"
#include "lxfile.h"


LxFile::LxFile( QObject* parent /*= nullptr*/ )
:LxOperate(parent)
{

}
LxFile::LxFile( QObject* object, QWebView* pWebView, QString strApiName )
:LxOperate(object, pWebView, strApiName)
{

}

LxFile::~LxFile()
{

}

QVariant LxFile::readFileData( QVariant varFilename,QString encode )
{
    if (!varFilename.isNull() && QVariant::String == varFilename.type())
    {
		QTextCodec::codecForName(encode.toLocal8Bit().data());
        //QTextCodec::setCodecForCStrings(QTextCodec::codecForName(encode.toLocal8Bit().data()));
        QFile file(varFilename.toString());
        if(!file.open(QIODevice::ReadOnly))
		{
            return QVariant(false);
        }
        return QVariant(file.readAll());
    }
    return QVariant(false);
}

QVariant LxFile::isExits( QVariant varFilename )
{
    if (!varFilename.isNull() && QVariant::String == varFilename.type())
	{
        QFile file(varFilename.toString());
        return QVariant(file.exists());
    }
	else
	{
        return QVariant(false);
    }
}

QVariant LxFile::remove( QVariant varFilename )
{
    if (!varFilename.isNull() && QVariant::String == varFilename.type())
	{
		return QFile::remove(varFilename.toString());
    }
	else
	{
        return QVariant(false);
    }
}

QVariant LxFile::rename( QVariant varOldName, QVariant varNewName )
{
    if (!varOldName.isNull() && QVariant::String == varOldName.type())
	{
		return QFile::rename(varOldName.toString(), varNewName.toString());
    }
	else
	{
        return QVariant(false);
    }
}

QVariant LxFile::link( QVariant oldname, QVariant newName )
{
    if (!oldname.isNull() && QVariant::String == oldname.type())
	{
        return QVariant(false);
    }else
	{
        return QVariant(false);
    }
}

QVariant LxFile::copy( QVariant varFileName, QVariant varNewName )
{

    if (!varFileName.isNull() && QVariant::String == varFileName.type()
        && !varNewName.isNull() && QVariant::String == varNewName.type() )
	{
        qDebug(varFileName.toByteArray());
        return QVariant(QFile::copy ( varFileName.toString(),varNewName.toString()));
    }
	else
	{
        return QVariant(false);
    }
}

QVariant LxFile::size( QVariant varFilename )
{
    if (!varFilename.isNull() && QVariant::String == varFilename.type())
	{
        return QVariant(false);
    }
	else
	{
        return QVariant(false);
    }
}

QVariant LxFile::permissions( QVariant varFilename )
{
    if (!varFilename.isNull() && QVariant::String == varFilename.type())
	{
        return QVariant(false);
    }
	else
	{
        return QVariant(false);
    }
}

QVariant LxFile::write(QVariant varFilename, QVariant text,QString encode)
{
     if (!varFilename.isNull() && QVariant::String == varFilename.type())
	 {
		 QTextCodec::codecForName(encode.toLocal8Bit().data());
        //QTextCodec::setCodecForCStrings(QTextCodec::codecForName(encode.toLocal8Bit().data()));
        QFile file(varFilename.toString());
        if(!file.open(QIODevice::WriteOnly))
		{
            return QVariant(-1);
        }
        return QVariant(file.write(text.toByteArray()));
    }
	else
	{
        return QVariant(-1);
    }
}



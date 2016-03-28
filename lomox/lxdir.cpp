#include "lxdir.h"

LxDir::LxDir(QObject *parent) :
    LxOperate(parent)
{
}

QVariant LxDir::exists(QVariant name,QString encode)
{
	QTextCodec::codecForName(encode.toLocal8Bit().data());
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName(encode.toLocal8Bit().data()));
    QDir dir(name.toString());
    return dir.exists();
}

QVariant LxDir::mkdir(QVariant dirName,QString encode)
{
	QTextCodec::codecForName(encode.toLocal8Bit().data());
   // QTextCodec::setCodecForCStrings(QTextCodec::codecForName(encode.toLocal8Bit().data()));
    QDir dir(dirName.toString());
    return dir.mkdir(dirName.toString());
}

QVariant LxDir::mkpath(QVariant dirPath,QString encode)
{
	QTextCodec::codecForName(encode.toLocal8Bit().data());
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName(encode.toLocal8Bit().data()));
    QDir dir(dirPath.toString());
    return dir.mkpath(dirPath.toString());
}

QVariant LxDir::entryList(QVariant dirPath, QVariant nameFilters, QVariant filters, QVariant sort, QString encode)
{
	QTextCodec::codecForName(encode.toLocal8Bit().data());
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName(encode.toLocal8Bit().data()));
    QDir dir(dirPath.toString());
    //return dir.entryList(nameFilters.toStringList(),(QDir::Filters)filters.toInt(),(QDir::SortFlags)sort.toInt());
	//修改加入文件类型判断并组装返回信息为[{name:"cm12.zip",type:"file"},{name:"cm12",type:"dir"}]
	QVariantList fileList;
	foreach(QFileInfo mfi, dir.entryInfoList())
	{
		qDebug() <<"File :" << mfi.fileName();
		QVariantMap tmpInfo;
		tmpInfo.insert(QString("name"), mfi.fileName());
		if (mfi.isFile())
		{
			tmpInfo.insert(QString("type"), QString("file"));
		}
		else
		{
			tmpInfo.insert(QString("type"), QString("dir"));
		}
		fileList.append(tmpInfo);
	}
	return fileList;
}

QVariant LxDir::getType(QVariant varPath, QString encode)
{
	QTextCodec::codecForName(encode.toLocal8Bit().data());
	QFileInfo finfo(varPath.toString());
	if (finfo.isDir())
	{
		return QString("dir");
	}
	else if (finfo.isFile())
	{
		return QString("file");
	}
	else
	{
		return QString("unknow");
	}
}

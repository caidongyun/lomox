#include "lxdir.h"

LxDir::LxDir(QObject *parent) :
    LxOperate(parent)
{
}

QVariant LxDir::exists(QVariant name,QString encode)
{
    //setCodecForCStrings  removed by QT5 removed by Colin3dmax
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName(encode.toLocal8Bit().data()));
    QDir dir(name.toString());
    return dir.exists();
}

QVariant LxDir::mkdir(QVariant dirName,QString encode)
{
    //setCodecForCStrings  removed by QT5 removed by Colin3dmax
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName(encode.toLocal8Bit().data()));
    QDir dir(dirName.toString());
    return dir.mkdir(dirName.toString());
}

QVariant LxDir::mkpath(QVariant dirPath,QString encode)
{
    //setCodecForCStrings  removed by QT5 removed by Colin3dmax
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName(encode.toLocal8Bit().data()));
    QDir dir(dirPath.toString());
    return dir.mkpath(dirPath.toString());
}

QVariant LxDir::entryList(QVariant dirPath, QVariant nameFilters, QVariant filters, QVariant sort, QString encode)
{
    //setCodecForCStrings  removed by QT5 removed by Colin3dmax
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName(encode.toLocal8Bit().data()));
    QDir dir(dirPath.toString());
    return dir.entryList(nameFilters.toStringList(),(QDir::Filters)filters.toInt(),(QDir::SortFlags)sort.toInt());
}


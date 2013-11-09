#ifndef LXDIR_H
#define LXDIR_H

#include "lomox_global.h"
#include "lxoperate.h"
#include <QDir>


class LxDir : public LxOperate
{
    Q_OBJECT
public:
    explicit LxDir(QObject *parent = 0);
    
signals:
    
public slots:

    virtual QVariant exists(QVariant name,QString encode="UTF-8");
    virtual QVariant mkdir(QVariant dirName,QString encode="UTF-8");
    virtual QVariant mkpath(QVariant dirPath,QString encode="UTF-8");
    virtual QVariant entryList(QVariant dirPath,QVariant nameFilters,QVariant filters=QDir::NoFilter,QVariant sort =QDir::NoSort,QString encode="UTF-8");

};

#endif // LXDIR_H

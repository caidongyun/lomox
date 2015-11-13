#ifndef LXLIBMANAGER_H
#define LXLIBMANAGER_H

#include <QObject>
#include <QMap>
#include "lxlibrary.h"

class LxLibManager : public QObject
{
    Q_OBJECT
public:
    explicit LxLibManager(QObject *parent = 0);
    virtual ~LxLibManager();
    virtual void initialize(QWebView *pWebView);
signals:
    
public slots:
    virtual QVariant count();
    virtual QObject* add( QString dllKey,QString dllPath );
    virtual QVariant remove( QString dllKey );
    virtual QObject* get(QString dllKey);
private:
    QMap<QString,LxLibrary*> m_mapLib;
    QPointer<QWebView> m_pWebView;
};

#endif // LXLIBMANAGER_H

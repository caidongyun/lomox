

#ifndef __LXLIBRARY_H__
#define __LXLIBRARY_H__

#include <QObject>
#include "lxbasewin.h"

class LOMOX_EXPORT LxLibrary : public QObject
{
	Q_OBJECT
public:
    explicit LxLibrary(QObject *parent = 0);
    virtual ~LxLibrary();

	void initialize(QWebView* pWebView = 0);

public slots:
    virtual QVariant load(QString dllPath );
    virtual QVariant exec(QString functionName,QVariant param,QString encode="UTF-8");
    virtual QVariant unload();

private:
    QPointer<QWebView> m_webView;
    QPointer<QLibrary> m_pLib;
};

#endif //__LXLIBRARY_H__

/*******************************************************************************
* 版权所有(C) 2011-2012www.LomoX.hk All Rights Follow Lomox licence.
*
* 文件名称	: lxcoreprivate.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/2/20
* 功能描述	:
* 备    注	:
********************************************************************************/
#ifndef __LXCOREPRIVATE_H__
#define __LXCOREPRIVATE_H__

#include <qpointer.h>

#include "lxbasewin.h"
#include "lxoperate.h"
#include "lxdialogs.h"
#include "lxcoreapplication.h"
#include "lxlibmanager.h"
#include "lxoption.h"

class LxCoreApplication;
class LxDialogs;

class LxCoreApplicationPrivate;

static LxCoreApplicationPrivate* g_AppSelft = nullptr;

class LOMOX_EXPORT LxCoreApplicationPrivate : public QObject
{
    Q_OBJECT
private:
    LxCoreApplicationPrivate()
        :m_pMainWin(nullptr),
        m_pDialogs(nullptr),
		m_pOption(nullptr)
    {
    }

public:
    virtual ~LxCoreApplicationPrivate();

    void runLomoxApp(int argc, char *argv[]);

    void quit();

    LxBaseWin* getMainWin();
	
	LxDialogs* getDialogs();

    void showMainDialog( QUrl URL /*= ""*/ );

	LxOption* getOption();

public:
    static LxCoreApplicationPrivate* instance()
    {
        if (!g_AppSelft)
        {
            g_AppSelft = new LxCoreApplicationPrivate();
        }
        return g_AppSelft;
    }

// private:
// 	QString 
protected:
    LxBaseWin* m_pMainWin;
    LxDialogs* m_pDialogs;
    LxDialogBase* m_pDialog;
	LxOption* m_pOption;
};





/*#ifndef lxCoreApp*/

/*#endif*/

#endif // end of __LXCOREPRIVATE_H__

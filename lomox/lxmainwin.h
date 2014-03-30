

/*******************************************************************************
* 版权所有(C) 1988-2014 All Rights Reserved.
*
* 文件名称	: basewin.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2014/3/9
* 功能描述	: 
* 备    注	: 
********************************************************************************/

#ifndef __LXMAINWIN_H__
#define __LXMAINWIN_H__

#include "lomox_global.h"

#include "lxoption.h"

#include "lxbasewin.h"
#include "lxcoreapplication.h"
#include "lxcoreprivate.h"
#include <QtGui/QWidget>
class LxBaseWin;

class LOMOX_EXPORT LxMainWindow : public LxBaseWin
{
	Q_OBJECT
public:
	explicit LxMainWindow(QWidget* prarent = 0);

	virtual ~LxMainWindow();

	bool _initWidget();

// public slots:
// 	void linkClickedAction( const QUrl& url );

};


#endif
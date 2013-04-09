/*******************************************************************************
* 版权所有(C) 1988-2011 All Rights Reserved.
*
* 文件名称	: basewin.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011/11/3
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#ifndef LOMOX_GLOBAL_H
#define LOMOX_GLOBAL_H

#include <QtCore/qglobal.h>

#ifndef LOMOX_EXPORT
#ifdef LOMOX_LIB
# define LOMOX_EXPORT Q_DECL_EXPORT
#else
# define LOMOX_EXPORT Q_DECL_IMPORT
#endif
#endif

#include "stdafx.h"

#include <QtGui>
#include <QtCore>
#include <QtWebKit>
#include <QDir>
#include <QVector>
#include <iostream>
#include <QString>
#include <QVariant>
#include <QDebug>

#include "tool/check.h"
#include "tool/utillites.h"
#include "lxlocaltool.h"
#include "lxdefinename.h"



#define nullptr 0
#define LOMOX_VERSION "0.1.0"

#include "lxoperate.h"

/*#include "lxdialogoperate.h"*/
#ifndef lxCoreApp
#define lxCoreApp  static_cast<LxCoreApplicationPrivate*>(LxCoreApplicationPrivate::instance())
#endif

#endif // LOMOX_GLOBAL_H




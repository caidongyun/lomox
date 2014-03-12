/*******************************************************************************
* 版权所有(C) 2011-2012  caidongyun All Rights Reserved.
*
* 文件名称	: lxwindows.cpp
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2012/2/6
* 功能描述	: 
* 备    注	: 
********************************************************************************/
#include "lomox_global.h"
#include "lxcoreapplication.h"
#include "lxdialogs.h"


LxDialogs::LxDialogs( QObject* parent )
:QObject(parent)
{
    m_ptrMainWin = lxCoreApp->getMainWin();
}

LxDialogs::~LxDialogs()
{

}

/*******************************************************************************
* 函数名称	: LxDialogs::item
* 功能描述	: 
* 参　　数	: QVariant varIndex
* 返 回 值	: QObject*
* 备　　注	: colin3dmax[2012/4/9]
			 修改格式，增加检查 --蔡东赟 [2012/4/9]
*******************************************************************************/


QObject *LxDialogs::get(QString varKey)
{
    if(m_mapDialogs.contains(varKey))
    {
        return m_mapDialogs[varKey];
    }
    else
    {
        return nullptr;
    }

}

QVariant LxDialogs::count()
{
    int nCount = m_mapDialogs.count();
	return QVariant(nCount);
}

void LxDialogs::append(QString key,LxDialogBase* pLxDialog )
{
    m_mapDialogs.insert(key,pLxDialog);
    qDebug("LxDialogs::append(\"%s\");",key.toLocal8Bit().constData());
}


inline bool isNetWorkPath(QString strUrl)
{
	QUrl qUrl(strUrl);
	if (qUrl.isValid())
	{
		if (1 != strUrl.indexOf(':'))
			if (0 == strUrl.indexOf(QString("http://")) || 0 == strUrl.indexOf(QString("https://")))
				return true;
	}
	return false;
}

QObject* LxDialogs::add( QString key,QString url )
{
	LxMainWindow* lxMain= lxCoreApp->getMainWin();
	LxBaseWin* lxDialog = new LxBaseWin(lxMain);
	lxDialog->initWidget();

	QString strFullUrl;
	QFileInfo qFileInfo(url);
	if (isNetWorkPath(url) || qFileInfo.isAbsolute())
	{
		strFullUrl = url;
	}
	else
	{
		strFullUrl = QCoreApplication::applicationDirPath() +  QDir::separator() + url;
	}

    qDebug("LxDialogs::add(%s,%s);",key.toLocal8Bit().constData(), strFullUrl.toLocal8Bit().constData());
	lxDialog->setUrl(QUrl(strFullUrl));
	lxDialog->setWindowFlags(Qt::WindowMinMaxButtonsHint| Qt::Dialog);

	new LxCoreApplication(this,lxDialog,QString(LOMOX_API_COREAPP));
	LxDialogBase* pDialogOp = new LxDialogBase(lxDialog, lxDialog, "LxDialog");
    this->append(key,pDialogOp);
    return pDialogOp;
}

QVariant LxDialogs::remove(QString key)
{
    if(m_mapDialogs.contains(key))
    {
        LxDialogBase* pDialogOp=m_mapDialogs[key];
        pDialogOp->deleteLater();
        m_mapDialogs.remove(key);
        return QVariant(true);
    }
    else
    {
        return QVariant(false);
    }
}



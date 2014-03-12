/*******************************************************************************
* 版权所有(C) 2011-2012www.LomoX.hk All Rights Follow Lomox licence.
*
* 文件名称	: basewin.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011/11/3
* 功能描述	:
* 备    注	:
********************************************************************************/
#include "lomox_global.h"
#include "lxoperate.h"
#include "lxdialogoperate.h"
#include "lxbasewin.h"

LxDialogBase::LxDialogBase( QObject* object /*= NULL*/, QWebView* pWebView /*= NULL*/, QString strApiName /*= NULL*/ )
:LxOperate(object, pWebView, strApiName)
{
    m_mainFrame = ((QWebView *)m_ptrWebView)->page()->mainFrame();
}

LxDialogBase::~LxDialogBase()
{
    LogEx("LomoX::~LMDialogBase()");
}

void LxDialogBase::move()
{
    LogEx("void LomoX::move()");
    VERIFY_IN_POINTER(m_ptrWebView);
# ifdef  Q_OS_WIN32
	WId id = m_ptrWebView->winId();
	ReleaseCapture();
	SendMessage(HWND(id), WM_SYSCOMMAND, SC_MOVE|HTCAPTION, 0);
#endif
}

void LxDialogBase::move( int x, int y )
{
    Q_CHECK_PTR(m_ptrWebView);
    m_ptrWebView->move(x,y);
}

void LxDialogBase::showMinimized()
{
    LogEx("void LomoX::showMinimized()");
    VERIFY_IN_POINTER(m_ptrWebView);
    m_ptrWebView->showMinimized();
}

void LxDialogBase::showMaximized()
{
    LogEx("void LomoX::showMaximized()");
    VERIFY_IN_POINTER(m_ptrWebView);
    if (m_ptrWebView->isMaximized())
        return;
    else
        m_ptrWebView->showMaximized();
}

void LxDialogBase::close()
{
    LogEx("void LomoX::close()");
    VERIFY_IN_POINTER(this->m_ptrWebView)
    m_ptrWebView->close();
}

void LxDialogBase::showNormal()
{
    LogEx("void LomoX::normal()");
    VERIFY_IN_POINTER(m_ptrWebView);
    m_ptrWebView->showNormal();
}

void LxDialogBase::show()
{
    LogEx("void LomoX::show()");
    VERIFY_IN_POINTER(m_ptrWebView);
    m_ptrWebView->show();
}

void LxDialogBase::setDialogWH( QVariant Width, QVariant Hight)
{
    LogEx("voikd LomoX::setDialogWH()");
    VERIFY_IN_POINTER(m_ptrWebView);
    if (Width.isNull()|| Hight.isNull())
        return;

    int nWidth = 0, nHeight = 0;

    if (QVariant::Double == Width.type() && QVariant::Double == Hight.type())
    {
        nWidth = (int) Width.toDouble()  + 1;
        nHeight = (int) Hight.toDouble() + 1;
        QSize size(nWidth, nHeight);
        m_ptrWebView->resize(size);
    }
    else
    {
        //榛樿
    }
}

void LxDialogBase::reload()
{
    LogEx("void LomoX::reload()");
    VERIFY_IN_POINTER(m_ptrWebView);
    AppIsRunning(1000);
    m_ptrWebView->stop();
    m_ptrWebView->reload();
}

void LxDialogBase::openUrl(QVariant url)
{
    LogEx("void LomoX::openUrl()");
    QString strUrl = url.toString();
    QDesktopServices::openUrl(QUrl(strUrl));
}


bool LxDialogBase::isFullScreen()
{
    LogEx("isFullScreen()");
    Q_CHECK_PTR(m_ptrWebView);
    return m_ptrWebView->isFullScreen();
}

bool LxDialogBase::isMaximized()
{
    LogEx("isMaximized()");
    Q_CHECK_PTR(m_ptrWebView);
    return m_ptrWebView->isMaximized();
}

bool LxDialogBase::isMinimized()
{
    LogEx("isMinimized");
    Q_CHECK_PTR(m_ptrWebView);
    return m_ptrWebView->isMinimized();
}


int LxDialogBase::minimumWidth()
{
    LogEx("LMDialogBase::minimumWidth()");
    Q_CHECK_PTR(m_ptrWebView);
    return m_ptrWebView->minimumHeight();
}

int LxDialogBase::minimumHeight()
{
    LogEx("LMDialogBase::minimumHeight()");
    Q_CHECK_PTR(m_ptrWebView);
    return m_ptrWebView->minimumHeight();
}

int LxDialogBase::maximumWidth()
{
    LogEx("LMDialogBase::maximumWidth()");
    Q_CHECK_PTR(m_ptrWebView);
    return m_ptrWebView->maximumWidth();
}

int LxDialogBase::maximumHeight()
{
    LogEx("LMDialogBase::maximumHeight()");
    Q_CHECK_PTR(m_ptrWebView);
    return m_ptrWebView->maximumHeight();
}

void LxDialogBase::setMinimumSize( int minw, int minh )
{
    LogEx("LMDialogBase::setMinimumSize( int minw, int minh )");
    Q_CHECK_PTR(m_ptrWebView);
    m_ptrWebView->setMinimumSize(minw, minh);
}

void LxDialogBase::setMaximumSize( int maxw, int maxh )
{
    LogEx("LMDialogBase::setMaximumSize( int minw, int minh )");
    Q_CHECK_PTR(m_ptrWebView);
    m_ptrWebView->setMaximumSize(maxw, maxh);
}

void LxDialogBase::setMinimumWidth( int minw )
{
    LogEx("LMDialogBase::setMinimumWidth( int minw )");
    Q_CHECK_PTR(m_ptrWebView);
    m_ptrWebView->setMinimumWidth(minw);
}

void LxDialogBase::setMinimumHeight( int minh )
{
    LogEx("LMDialogBase::setMinimumHeight( int minh )");
    Q_CHECK_PTR(m_ptrWebView);
    m_ptrWebView->setMinimumHeight(minh);
}

void LxDialogBase::setMaximumWidth( int maxw )
{
    LogEx("LMDialogBase::setMaximumWidth( int maxw )");
    Q_CHECK_PTR(m_ptrWebView);
    m_ptrWebView->setMaximumWidth(maxw);
}

void LxDialogBase::setMaximumHeight( int maxh )
{
    LogEx("LMDialogBase::setMaximumHeight( )");
    Q_CHECK_PTR(m_ptrWebView);
    m_ptrWebView->setMaximumHeight(maxh);
}

void LxDialogBase::setUrl( QString strUrl )
{
    LogEx("setUrl");
    Q_CHECK_PTR(m_ptrWebView);
    m_ptrWebView->setUrl(QUrl(strUrl));
}

int LxDialogBase::getTopLeftX()
{
    //LogEx("getTopLeftX()");
    Q_CHECK_PTR(m_ptrWebView);
    QPoint pTopLef = m_ptrWebView->mapToGlobal(QPoint(0,0));
    return pTopLef.x();
}

int LxDialogBase::getTopLeftY()
{
    //LogEx("getTopLeftY()");
    Q_CHECK_PTR(m_ptrWebView);
    QPoint pTopLef = m_ptrWebView->mapToGlobal(QPoint(0,0));
    return pTopLef.y();
}

// QObject* LxDialogBase::getOtherWin()
// {
// 	LxBaseWin* lxWidget = new LxBaseWin(m_ptrWebView);
// 	QString strFile2 = QCoreApplication::applicationDirPath() + "/Resources/lomoxdemo2.html";
// 	lxWidget->setUrl(QUrl(strFile2));
// 	lxWidget->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
// 	lxWidget->show();
//
// 	return (QObject*)lxWidget;
// }

QObject* LxDialogBase::getCoreDialog()
{
    LogEx("LxDialogBase::getCoreDialog()");
    Q_CHECK_PTR(m_ptrWebView);
    return m_ptrWebView;
}

void LxDialogBase::setHidden( bool hidden )
{
    LogEx("LxDialogBase::setHidden( bool hidden )");
    Q_CHECK_PTR(m_ptrWebView);
    m_ptrWebView->setHidden(hidden);
}

void LxDialogBase::setVisible( bool visible )
{
    LogEx("LxDialogBase::setVisible( bool visible )");
    Q_CHECK_PTR(m_ptrWebView);
    m_ptrWebView->setVisible(visible);
}

QVariant LxDialogBase::eval( QVariant code)
{
    if( m_mainFrame ){
        return m_mainFrame->evaluateJavaScript( code.toString() );
    }else{
        return nullptr;
    }
}
void LxDialogBase::setHTML( QVariant code){
    Q_CHECK_PTR(m_ptrWebView);


    m_ptrWebView->setHtml( code.toString());
}
QVariant LxDialogBase::toHTML()
{
    if( m_mainFrame ){
        return m_mainFrame->toHtml();
    }else{
        return nullptr;
    }
}

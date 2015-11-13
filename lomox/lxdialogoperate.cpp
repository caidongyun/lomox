/*******************************************************************************
* 版权所有(C) 2011-2012www.LomoX.hk All Rights Follow Lomox licence.
*
* 文件名称	: basewin.h
* 作    者	: 蔡东赟 (mailto:caidongyun19@qq.com)
* 创建日期	: 2011/11/3
* 功能描述	:
* 备    注	:
* 修    改  ：詹晨辉(KeoJam)(mailto:zch.fly@gmail.com)
********************************************************************************/
#include "lomox_global.h"
#include "lxoperate.h"
#include "lxdialogoperate.h"
#include "lxmainwin.h"
#include "lxbasewin.h"
#include "lxdownloadmanager.h"
#include <QtPrintSupport/QPrintPreviewDialog>

LxDialogBase::LxDialogBase(QObject* object, QWebView* pWebView, QString strApiName, bool bshowloading, int gifW, int gifH)
:LxOperate(object, pWebView, strApiName)
{
	m_layout = NULL;
	m_movie = NULL;
	m_label = NULL;
	m_nWidth = 0;
	m_nHeight = 0;
	m_url = m_ptrWebView->url();
    m_mainFrame = ((QWebView *)m_ptrWebView)->page()->mainFrame();
	QObject::connect(m_ptrWebView->page(), SIGNAL(downloadRequested(QNetworkRequest)), this, SLOT(downloadRequested(QNetworkRequest)));
	QObject::connect(m_ptrWebView, SIGNAL(loadFinished(bool)), this, SLOT(loadFinished(bool)));
	m_showloading = bshowloading;
	if (m_showloading)
	{
		m_label = new QLabel(m_ptrWebView);
		m_layout = new QBoxLayout(QBoxLayout::LeftToRight, m_ptrWebView);
		m_lablW = gifW;
		m_lablH = gifH;
		qDebug() << QCoreApplication::applicationDirPath() + "/Resources/loading.gif";
		m_movie = new QMovie(QCoreApplication::applicationDirPath() + "/Resources/loading.gif");
		m_label->setStyleSheet("background-color: transparent;");
		m_label->setScaledContents(true);
		m_label->setContentsMargins(0, 0, 0, 0);
		m_label->setAlignment(Qt::AlignCenter);
		m_label->resize(QSize(m_lablW, m_lablH));
		m_label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		m_layout->addWidget(m_label, 0, Qt::AlignHCenter);
// 		QSize size = m_ptrWebView->size();
// 		int nposx = (m_ptrWebView->width() - gifW) / 2;
// 		int nposy = (m_ptrWebView->height() - gifH) / 2;
// 		QPoint npoint = m_label->mapToParent(QPoint(nposx, nposy));
// 		m_label->setGeometry(npoint.x(), npoint.y(), gifW, gifH);
		m_label->setMovie(m_movie);
		m_movie->start();

	}
}

LxDialogBase::~LxDialogBase()
{
    LogEx("LomoX::~LMDialogBase()");
	LxDialogs *plxDialogs = lxCoreApp->getDialogs();
	plxDialogs->remove(m_url.toString());
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
	{
		m_ptrWebView->showMaximized();
	}
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
//    m_ptrWebView->showNormal();
 	WId id = m_ptrWebView->winId();
#ifdef Q_OS_WIN
 	ShowWindow((HWND)id, SW_RESTORE);
#endif
    if (m_nWidth == 0 && m_nHeight == 0)
	{
		qDebug() << m_ptrWebView->minimumWidth();
#ifdef Q_OS_WIN
		SetWindowPos((HWND)id, HWND_TOP, 0, 0, m_ptrWebView->minimumWidth(), m_ptrWebView->minimumHeight(), SWP_NOMOVE);
#endif
	}
    else{
#ifdef Q_OS_WIN

        SetWindowPos((HWND)id, HWND_TOP, 0, 0, m_nWidth, m_nHeight, SWP_NOMOVE);
#endif
    }

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
		m_nWidth = nWidth;
		m_nHeight = nHeight;
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
	return m_ptrWebView->minimumWidth();
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
//add by KeoJam 增加打印接口
void LxDialogBase::printPreview()
{
	LogEx("void LomoX::printPreview()");
	if (!m_ptrWebView)
		return;
	QPrintPreviewDialog *dialog = new QPrintPreviewDialog(m_ptrWebView);
	dialog->setAttribute(Qt::WA_DeleteOnClose);
	connect(dialog, SIGNAL(paintRequested(QPrinter*)),
		m_ptrWebView, SLOT(print(QPrinter*)));
	dialog->exec();
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
//add by KeoJam 增加下载功能 
void LxDialogBase::downloadRequested(const QNetworkRequest &request)
{
	LogEx("downloadRequested()");
	lxCoreApp->getDownloadManager()->download(request,this);
	//BrowserApplication::downloadManager()->download(request);
}

void LxDialogBase::loadFinished(bool bFinished)
{
	if (m_showloading)
	{
		m_movie->stop();
		m_label->hide();
	}
}

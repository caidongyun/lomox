/*******************************************************************************
* 版权所有(C) 2011-2015www.LomoX.hk All Rights Follow Lomox licence.
*
* 文件名称	: lxsystemtray.cpp
* 作    者	: 詹晨辉 (mailto:zch.fly@gmail.com)
* 创建日期	: 2015/04/20
* 功能描述	:
* 备    注	:
********************************************************************************/
#include "lxsystemtray.h"

LxSystemTray::LxSystemTray(QIcon icon, QString toolTipName, LxDialogBase* pLxDialogBase)
{
	m_icon = icon;
	m_ptrLxDialogBase = pLxDialogBase;
	m_toolTipName = toolTipName;
	this->setParent((QWidget*)(pLxDialogBase->getCoreDialog()));
	__initSystemTray();
}

LxSystemTray::~LxSystemTray()
{

}
bool LxSystemTray::__initSystemTray()
{
	setObjectName("LxSystemTray");
	m_ptrTrayIcon = new QSystemTrayIcon(this);
	m_ptrTrayIcon->setIcon(m_icon);
	m_ptrTrayIcon->setToolTip(m_toolTipName);
	m_ptrTrayMenu = new QMenu(this);

	QAction *action = new QAction(QString::fromLocal8Bit("隐藏"), this);
	action->setIcon(QIcon(QCoreApplication::applicationDirPath()+"/Resources/hide.ico"));
	m_ptrTrayMenu->addAction(action);
	connect(action, SIGNAL(triggered()), m_ptrLxDialogBase, SLOT(showMinimized()));
	m_trayActions.insert(QString::fromLocal8Bit("隐藏"), action);

	action = new QAction(QString::fromLocal8Bit("最小化"), this);
	action->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/Resources/mini.ico"));
	m_ptrTrayMenu->addAction(action);
	connect(action, SIGNAL(triggered()), m_ptrLxDialogBase, SLOT(showMinimized()));
	m_trayActions.insert(QString::fromLocal8Bit("最小化"), action);

	action = new QAction(QString::fromLocal8Bit("最大化"), this);
	action->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/Resources/max.ico"));
	m_ptrTrayMenu->addAction(action);
	connect(action, SIGNAL(triggered()), m_ptrLxDialogBase, SLOT(showMaximized()));
	m_trayActions.insert(QString::fromLocal8Bit("最大化"), action);

	action = new QAction(QString::fromLocal8Bit("还原"), this);
	action->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/Resources/normal.ico"));
	m_ptrTrayMenu->addAction(action);
	connect(action, SIGNAL(triggered()), m_ptrLxDialogBase, SLOT(showNormal()));
	m_trayActions.insert(QString::fromLocal8Bit("还原"), action);

	m_ptrTrayMenu->addSeparator();
	action = new QAction(QString::fromLocal8Bit("退出"), this);
	action->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/Resources/close.ico"));
	m_ptrTrayMenu->addAction(action);
	connect(action, SIGNAL(triggered()), m_ptrLxDialogBase, SLOT(close()));
	m_trayActions.insert(QString::fromLocal8Bit("退出"), action);

	m_ptrTrayIcon->setContextMenu(m_ptrTrayMenu);

	//图标点击事件
	connect(m_ptrTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

	m_ptrTrayIcon->show();
	return true;
}

void LxSystemTray::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
	//触发后台图标执行相应事件  
	switch (reason)
	{
	case QSystemTrayIcon::Trigger:
		m_ptrLxDialogBase->showNormal();
		break;
	case QSystemTrayIcon::DoubleClick:
		m_ptrLxDialogBase->showNormal();
		break;
// 	case QSystemTrayIcon::MiddleClick:
// 		showMessage("鼠标中键！");
// 		break;
	default:
		break;
	}
}
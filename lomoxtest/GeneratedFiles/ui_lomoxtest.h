/********************************************************************************
** Form generated from reading UI file 'lomoxtest.ui'
**
** Created: Wed Dec 19 17:02:21 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOMOXTEST_H
#define UI_LOMOXTEST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lomoxtestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *lomoxtestClass)
    {
        if (lomoxtestClass->objectName().isEmpty())
            lomoxtestClass->setObjectName(QString::fromUtf8("lomoxtestClass"));
        lomoxtestClass->resize(600, 400);
        menuBar = new QMenuBar(lomoxtestClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        lomoxtestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lomoxtestClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        lomoxtestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(lomoxtestClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lomoxtestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(lomoxtestClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        lomoxtestClass->setStatusBar(statusBar);

        retranslateUi(lomoxtestClass);

        QMetaObject::connectSlotsByName(lomoxtestClass);
    } // setupUi

    void retranslateUi(QMainWindow *lomoxtestClass)
    {
        lomoxtestClass->setWindowTitle(QApplication::translate("lomoxtestClass", "lomoxtest", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class lomoxtestClass: public Ui_lomoxtestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOMOXTEST_H

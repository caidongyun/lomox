/********************************************************************************
** Form generated from reading UI file 'lomoxtest.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOMOXTEST_H
#define UI_LOMOXTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

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
            lomoxtestClass->setObjectName(QStringLiteral("lomoxtestClass"));
        lomoxtestClass->resize(600, 400);
        menuBar = new QMenuBar(lomoxtestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        lomoxtestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(lomoxtestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        lomoxtestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(lomoxtestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lomoxtestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(lomoxtestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        lomoxtestClass->setStatusBar(statusBar);

        retranslateUi(lomoxtestClass);

        QMetaObject::connectSlotsByName(lomoxtestClass);
    } // setupUi

    void retranslateUi(QMainWindow *lomoxtestClass)
    {
        lomoxtestClass->setWindowTitle(QApplication::translate("lomoxtestClass", "lomoxtest", 0));
    } // retranslateUi

};

namespace Ui {
    class lomoxtestClass: public Ui_lomoxtestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOMOXTEST_H

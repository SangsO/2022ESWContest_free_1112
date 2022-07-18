/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QTabWidget *tabWidget;
    QWidget *pTab3;
    QWidget *pTab1;
    QWidget *pTab2;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(800, 480);
        tabWidget = new QTabWidget(MainWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 800, 480));
        pTab3 = new QWidget();
        pTab3->setObjectName(QStringLiteral("pTab3"));
        tabWidget->addTab(pTab3, QString());
        pTab1 = new QWidget();
        pTab1->setObjectName(QStringLiteral("pTab1"));
        tabWidget->addTab(pTab1, QString());
        pTab2 = new QWidget();
        pTab2->setObjectName(QStringLiteral("pTab2"));
        tabWidget->addTab(pTab2, QString());

        retranslateUi(MainWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0));
        tabWidget->setTabText(tabWidget->indexOf(pTab3), QApplication::translate("MainWidget", "Tab 3", 0));
        tabWidget->setTabText(tabWidget->indexOf(pTab1), QApplication::translate("MainWidget", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(pTab2), QApplication::translate("MainWidget", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H

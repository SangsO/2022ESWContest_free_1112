/********************************************************************************
** Form generated from reading UI file 'tab2database.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB2DATABASE_H
#define UI_TAB2DATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab2DataBase
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QDateTimeEdit *pDteFrom;
    QDateTimeEdit *pDteTo;
    QSpacerItem *horizontalSpacer;
    QPushButton *pPbSearchButton;
    QPushButton *pPbDeleteButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *pTableWidget;

    void setupUi(QWidget *Tab2DataBase)
    {
        if (Tab2DataBase->objectName().isEmpty())
            Tab2DataBase->setObjectName(QStringLiteral("Tab2DataBase"));
        Tab2DataBase->resize(790, 410);
        horizontalLayoutWidget = new QWidget(Tab2DataBase);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 771, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pDteFrom = new QDateTimeEdit(horizontalLayoutWidget);
        pDteFrom->setObjectName(QStringLiteral("pDteFrom"));
        pDteFrom->setDateTime(QDateTime(QDate(2022, 6, 21), QTime(0, 0, 0)));

        horizontalLayout->addWidget(pDteFrom);

        pDteTo = new QDateTimeEdit(horizontalLayoutWidget);
        pDteTo->setObjectName(QStringLiteral("pDteTo"));
        pDteTo->setDateTime(QDateTime(QDate(2022, 7, 30), QTime(12, 0, 0)));

        horizontalLayout->addWidget(pDteTo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pPbSearchButton = new QPushButton(horizontalLayoutWidget);
        pPbSearchButton->setObjectName(QStringLiteral("pPbSearchButton"));

        horizontalLayout->addWidget(pPbSearchButton);

        pPbDeleteButton = new QPushButton(horizontalLayoutWidget);
        pPbDeleteButton->setObjectName(QStringLiteral("pPbDeleteButton"));

        horizontalLayout->addWidget(pPbDeleteButton);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayoutWidget_2 = new QWidget(Tab2DataBase);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 70, 771, 331));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pTableWidget = new QTableWidget(horizontalLayoutWidget_2);
        if (pTableWidget->columnCount() < 4)
            pTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        pTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        pTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        pTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        pTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        pTableWidget->setObjectName(QStringLiteral("pTableWidget"));
        pTableWidget->setSortingEnabled(true);
        pTableWidget->setColumnCount(4);
        pTableWidget->horizontalHeader()->setVisible(true);
        pTableWidget->horizontalHeader()->setDefaultSectionSize(160);
        pTableWidget->horizontalHeader()->setMinimumSectionSize(40);
        pTableWidget->verticalHeader()->setCascadingSectionResizes(true);
        pTableWidget->verticalHeader()->setDefaultSectionSize(32);
        pTableWidget->verticalHeader()->setMinimumSectionSize(32);

        horizontalLayout_2->addWidget(pTableWidget);


        retranslateUi(Tab2DataBase);

        QMetaObject::connectSlotsByName(Tab2DataBase);
    } // setupUi

    void retranslateUi(QWidget *Tab2DataBase)
    {
        Tab2DataBase->setWindowTitle(QApplication::translate("Tab2DataBase", "Form", 0));
        pPbSearchButton->setText(QApplication::translate("Tab2DataBase", "Search", 0));
        pPbDeleteButton->setText(QApplication::translate("Tab2DataBase", "Delete", 0));
        QTableWidgetItem *___qtablewidgetitem = pTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Tab2DataBase", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = pTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Tab2DataBase", "data", 0));
        QTableWidgetItem *___qtablewidgetitem2 = pTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Tab2DataBase", "area", 0));
        QTableWidgetItem *___qtablewidgetitem3 = pTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Tab2DataBase", "status", 0));
    } // retranslateUi

};

namespace Ui {
    class Tab2DataBase: public Ui_Tab2DataBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB2DATABASE_H
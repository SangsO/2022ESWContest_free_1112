/********************************************************************************
** Form generated from reading UI file 'tab1socketclient.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB1SOCKETCLIENT_H
#define UI_TAB1SOCKETCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab1SocketClient
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *pLabel;
    QPushButton *pPbRecvDataClear;
    QPushButton *pPbServerConnect;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *pTeRecvData;

    void setupUi(QWidget *Tab1SocketClient)
    {
        if (Tab1SocketClient->objectName().isEmpty())
            Tab1SocketClient->setObjectName(QStringLiteral("Tab1SocketClient"));
        Tab1SocketClient->resize(770, 400);
        horizontalLayoutWidget = new QWidget(Tab1SocketClient);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 741, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pLabel = new QLabel(horizontalLayoutWidget);
        pLabel->setObjectName(QStringLiteral("pLabel"));

        horizontalLayout->addWidget(pLabel);

        pPbRecvDataClear = new QPushButton(horizontalLayoutWidget);
        pPbRecvDataClear->setObjectName(QStringLiteral("pPbRecvDataClear"));

        horizontalLayout->addWidget(pPbRecvDataClear);

        pPbServerConnect = new QPushButton(horizontalLayoutWidget);
        pPbServerConnect->setObjectName(QStringLiteral("pPbServerConnect"));
        pPbServerConnect->setCheckable(true);

        horizontalLayout->addWidget(pPbServerConnect);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayoutWidget_2 = new QWidget(Tab1SocketClient);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 50, 741, 321));
        horizontalLayoutWidget_2->setFocusPolicy(Qt::StrongFocus);
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 5, 5);
        pTeRecvData = new QTextEdit(horizontalLayoutWidget_2);
        pTeRecvData->setObjectName(QStringLiteral("pTeRecvData"));
        pTeRecvData->setFocusPolicy(Qt::StrongFocus);
        pTeRecvData->setTabStopWidth(80);

        horizontalLayout_2->addWidget(pTeRecvData);


        retranslateUi(Tab1SocketClient);

        QMetaObject::connectSlotsByName(Tab1SocketClient);
    } // setupUi

    void retranslateUi(QWidget *Tab1SocketClient)
    {
        Tab1SocketClient->setWindowTitle(QApplication::translate("Tab1SocketClient", "Form", 0));
        pLabel->setText(QApplication::translate("Tab1SocketClient", "Data", 0));
        pPbRecvDataClear->setText(QApplication::translate("Tab1SocketClient", "Clear", 0));
        pPbServerConnect->setText(QApplication::translate("Tab1SocketClient", "Connent", 0));
    } // retranslateUi

};

namespace Ui {
    class Tab1SocketClient: public Ui_Tab1SocketClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB1SOCKETCLIENT_H

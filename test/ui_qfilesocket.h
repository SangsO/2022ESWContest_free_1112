/********************************************************************************
** Form generated from reading UI file 'qfilesocket.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFILESOCKET_H
#define UI_QFILESOCKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QfileSocket
{
public:
    QWidget *widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextEdit *pTeLogData;
    QLabel *label;
    QPushButton *pPbQfileRead;

    void setupUi(QWidget *QfileSocket)
    {
        if (QfileSocket->objectName().isEmpty())
            QfileSocket->setObjectName(QStringLiteral("QfileSocket"));
        QfileSocket->resize(790, 440);
        widget = new QWidget(QfileSocket);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 790, 440));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 40, 771, 311));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pTeLogData = new QTextEdit(verticalLayoutWidget);
        pTeLogData->setObjectName(QStringLiteral("pTeLogData"));

        horizontalLayout->addWidget(pTeLogData);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 191, 31));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        pPbQfileRead = new QPushButton(widget);
        pPbQfileRead->setObjectName(QStringLiteral("pPbQfileRead"));
        pPbQfileRead->setGeometry(QRect(350, 360, 85, 27));

        retranslateUi(QfileSocket);

        QMetaObject::connectSlotsByName(QfileSocket);
    } // setupUi

    void retranslateUi(QWidget *QfileSocket)
    {
        QfileSocket->setWindowTitle(QApplication::translate("QfileSocket", "Form", 0));
        label->setText(QApplication::translate("QfileSocket", "Total Log", 0));
        pPbQfileRead->setText(QApplication::translate("QfileSocket", "Read", 0));
    } // retranslateUi

};

namespace Ui {
    class QfileSocket: public Ui_QfileSocket {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFILESOCKET_H

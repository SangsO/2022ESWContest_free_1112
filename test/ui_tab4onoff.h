/********************************************************************************
** Form generated from reading UI file 'tab4onoff.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB4ONOFF_H
#define UI_TAB4ONOFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab4OnOff
{
public:
    QPushButton *pPBLamp1;
    QProgressBar *progressBar_2;
    QProgressBar *progressBar;
    QPushButton *pPBSpot2;
    QPushButton *pPBOne;
    QPushButton *pPBSpot1;
    QPushButton *pPBLamp2;
    QPushButton *pPBTwo;

    void setupUi(QWidget *Tab4OnOff)
    {
        if (Tab4OnOff->objectName().isEmpty())
            Tab4OnOff->setObjectName(QStringLiteral("Tab4OnOff"));
        Tab4OnOff->resize(790, 410);
        pPBLamp1 = new QPushButton(Tab4OnOff);
        pPBLamp1->setObjectName(QStringLiteral("pPBLamp1"));
        pPBLamp1->setEnabled(true);
        pPBLamp1->setGeometry(QRect(40, 230, 71, 61));
        QIcon icon;
        icon.addFile(QStringLiteral(":/IotQtClient/img/light_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/IotQtClient/img/light_on.png"), QSize(), QIcon::Normal, QIcon::On);
        pPBLamp1->setIcon(icon);
        pPBLamp1->setIconSize(QSize(60, 60));
        pPBLamp1->setCheckable(true);
        progressBar_2 = new QProgressBar(Tab4OnOff);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setGeometry(QRect(450, 130, 118, 23));
        progressBar_2->setValue(24);
        progressBar = new QProgressBar(Tab4OnOff);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(140, 130, 118, 23));
        progressBar->setValue(24);
        pPBSpot2 = new QPushButton(Tab4OnOff);
        pPBSpot2->setObjectName(QStringLiteral("pPBSpot2"));
        pPBSpot2->setGeometry(QRect(350, 80, 75, 131));
        pPBOne = new QPushButton(Tab4OnOff);
        pPBOne->setObjectName(QStringLiteral("pPBOne"));
        pPBOne->setGeometry(QRect(40, 40, 75, 23));
        pPBOne->setCheckable(true);
        pPBSpot1 = new QPushButton(Tab4OnOff);
        pPBSpot1->setObjectName(QStringLiteral("pPBSpot1"));
        pPBSpot1->setGeometry(QRect(40, 80, 75, 131));
        pPBLamp2 = new QPushButton(Tab4OnOff);
        pPBLamp2->setObjectName(QStringLiteral("pPBLamp2"));
        pPBLamp2->setGeometry(QRect(350, 230, 75, 61));
        pPBLamp2->setIcon(icon);
        pPBLamp2->setIconSize(QSize(60, 60));
        pPBLamp2->setCheckable(true);
        pPBTwo = new QPushButton(Tab4OnOff);
        pPBTwo->setObjectName(QStringLiteral("pPBTwo"));
        pPBTwo->setGeometry(QRect(350, 40, 75, 23));
        pPBTwo->setCheckable(true);

        retranslateUi(Tab4OnOff);

        QMetaObject::connectSlotsByName(Tab4OnOff);
    } // setupUi

    void retranslateUi(QWidget *Tab4OnOff)
    {
        Tab4OnOff->setWindowTitle(QApplication::translate("Tab4OnOff", "Form", 0));
        pPBLamp1->setText(QString());
        pPBSpot2->setText(QApplication::translate("Tab4OnOff", "pPBSpot2", 0));
        pPBOne->setText(QApplication::translate("Tab4OnOff", "pPBOne", 0));
        pPBSpot1->setText(QApplication::translate("Tab4OnOff", "pPBSpot1", 0));
        pPBLamp2->setText(QString());
        pPBTwo->setText(QApplication::translate("Tab4OnOff", "pPBTwo", 0));
    } // retranslateUi

};

namespace Ui {
    class Tab4OnOff: public Ui_Tab4OnOff {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB4ONOFF_H

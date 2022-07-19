#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(1);
    pTab2OnOff = new Tab2OnOff(ui->pTab2_2);
    ui->pTab2_2->setLayout(pTab2OnOff->layout());


    connect(pTab2OnOff,SIGNAL(sigSocketSendData(QString)), pTab2OnOff, SLOT(slotSocketSendData(QString)));
}

Widget::~Widget()
{
    delete ui;
}

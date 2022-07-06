#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);

    pTab1SocketClient = new Tab1SocketClient(ui->pTab1);
    ui->pTab1->setLayout(pTab1SocketClient->layout());

    ptab2database = new Tab2DataBase(ui->pTab2);
    ui->pTab2->setLayout(ptab2database->layout());

    connect(pTab1SocketClient, SIGNAL(sigTab2RecvData(QString)), ptab2database, SLOT(slotTab2RecvData(QString)));


}

MainWidget::~MainWidget()
{
    delete ui;
}


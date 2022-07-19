#include "tab4onoff.h"
#include "ui_tab4onoff.h"

Tab4OnOff::Tab4OnOff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab4OnOff)
{
    ui->setupUi(this);
    pSocketClient = new SocketClient(this);

    connect(ui->pPBLamp1,SIGNAL(clicked(bool)),this,SLOT(slotOneOnOff(bool)));
    connect(ui->pPBLamp2,SIGNAL(clicked(bool)),this,SLOT(slotTwoOnOff(bool)));

}

Tab4OnOff::~Tab4OnOff()
{
    delete ui;
}
void Tab4OnOff::slotOneOnOff(bool check)
{
    if(check)
    {
        ui->pPBLamp1->setChecked(true);
        /*
        QString strSendData;
        strSendData = "[SPOT1]ONL";
        qDebug() << strSendData;
        pSocketClient->slotSocketSendData(strSendData);
        */
        emit sigSocketSendData("[SPOT1]ONL");
    }
    else
    {
        /*
        ui->pPBLamp1->setChecked(false);
        QString strSendData;
        strSendData = "[SPOT1]OFFL";
        qDebug() << strSendData;
        pSocketClient->slotSocketSendData(strSendData);
        */
        emit sigSocketSendData("[SPOT1]OFFL");
    }
}
void Tab4OnOff::slotTwoOnOff(bool check)
{
    if(check)
    {
        ui->pPBLamp2->setChecked(true);
        QString strSendData;
        strSendData = "[SPOT2]ON";
        pSocketClient->slotSocketSendData(strSendData);
    }
    else
    {
        ui->pPBLamp2->setChecked(false);
        QString strSendData;
        strSendData = "[SPOT2]OFF";
        pSocketClient->slotSocketSendData(strSendData);
    }
}
void Tab4OnOff::slotTab4RecvData(QString strRecvData)
{
    qDebug() << strRecvData;
    strRecvData.replace("[","@");
    strRecvData.replace("]","@");
    QStringList qlist = strRecvData.split("@");
    QString batt = qlist[2];
    int bat = batt.toInt();
    ui->progressBar->setValue(bat);

}

#include "tab2onoff.h"
#include "ui_tab2onoff.h"

Tab2OnOff::Tab2OnOff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab2OnOff)
{
    ui->setupUi(this);
    pSocketClient = new SocketClient(this);

    connect(ui->pPBOne,SIGNAL(clicked(bool)),this,SLOT(slotOneOnOff(bool)));
    connect(ui->pPBTwo,SIGNAL(clicked(bool)),this,SLOT(slotTwoOnOff(bool)));
}

Tab2OnOff::~Tab2OnOff()
{
    delete ui;
}


void Tab2OnOff::slotOneOnOff(bool check)
{
    if(check)
    {
        ui->pPBOne->setChecked(false);
        emit sigSocketSendData("[19]LAMPON");
    }
    else {
        ui->pPBOne->setChecked(true);
        emit sigSocketSendData("[19]LAMPOFF");
    }
}
void Tab2OnOff::slotTwoOnOff(bool check)
{
    if(check)
    {
        ui->pPBTwo->setChecked(false);
        emit sigSocketSendData("[19]GASON");
    }
    else {
        ui->pPBTwo->setChecked(true);
        emit sigSocketSendData("[19]GASOFF");
    }
}



//pSocketClient->slotSocketSendData(strSendData);

/*
void Tab2OnOff::slotTab3RecvData(QString recvData)  // 데이터베이스에 문자열을 받는 과정
{
   // QMessageBox::information(this,"socket",recvData); // [19]LAMPON => @19@LAMPON
    recvData.replace("[","@");
    recvData.replace("]","@");
    QStringList qlist = recvData.split("@");
    if(qlist[2]=="LAMPON") {
        ui->pPBOne->setChecked(true);
    }
    else if(qlist[2]=="LAMPOFF") {
        ui->pPBOne->setChecked(false);
    }
    else if(qlist[2]=="GASON") {
        ui->pPBTwo->setChecked(true);
    }
    else if(qlist[2]=="GASOFF") {
        ui->pPBTwo->setChecked(false);
    }
}
*/

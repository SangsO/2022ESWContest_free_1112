#include "tab1socketclient.h"
#include "ui_tab1socketclient.h"

Tab1SocketClient::Tab1SocketClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab1SocketClient)
{
    ui->setupUi(this);
    pSocketClient = new SocketClient(this);
    connect(ui->pPbServerConnect,SIGNAL(clicked(bool)), this, SLOT(slotConnectToServer(bool)));
    connect(pSocketClient, SIGNAL(sigSocketRecv(QString)), this, SLOT(slotSocketRecvUpdate(QString)));
    connect(ui->pPbRecvDataClear, SIGNAL(clicked()), ui->pTeRecvData, SLOT(clear()));

}

Tab1SocketClient::~Tab1SocketClient()
{
    delete ui;
}
void Tab1SocketClient :: slotConnectToServer(bool check)
{
    bool bOK;
    if(check){
        pSocketClient->slotConnectToServer(bOK);

        if(bOK)
        {
            ui->pPbServerConnect->setText("disconnect");
        }
    }
    else
    {
        pSocketClient->slotClosedByServer();
        ui->pPbServerConnect->setText("connect");
    }
}
void Tab1SocketClient :: slotSocketRecvUpdate(QString strRecvData)
{
    //qDebug() << strRecvData;

    QTime time = QTime::currentTime();
    QString strtime = time.toString();
    //qDebug() << strtime;
    //strRecvData.chop(1);
    //qDebug() << strRecvData.indexOf("0") << strRecvData.indexOf("1") ;


    if((strRecvData.indexOf("[SPOT1->admin]") != -1))
    {

        //qDebug() << strRecvData;

        emit sigQfileRecvData(strRecvData);
    }
    else if((strRecvData.indexOf("@") != -1))
    {
        strRecvData.chop(1);
        emit sigTab4RecvData(strRecvData);
        ui->pTeRecvData->append(strRecvData);
        ui->pTeRecvData->moveCursor(QTextCursor::End);
        //qDebug() << strRecvData;
    }
    else if((strRecvData.indexOf("1") != -1)||(strRecvData.indexOf("0") != -1))
    {
        strRecvData.chop(1);
        emit sigTab2RecvData(strRecvData);
        ui->pTeRecvData->append(strRecvData);
        ui->pTeRecvData->moveCursor(QTextCursor::End);
        qDebug() << strRecvData;
    }

    //strRecvData = strtime + " " + strRecvData;

}

void Tab1SocketClient :: slotSocketSendData(QString strData)
{
    if(ui->pPbServerConnect->isChecked())
    {
        pSocketClient->slotSocketSendData(strData);
    }
    else
        QMessageBox::information(this,"socket", "서버 연결 확인");

}

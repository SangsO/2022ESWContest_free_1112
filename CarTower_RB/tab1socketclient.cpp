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
            ui->pPbServerConnect->setText("Disconnent");
        }
    }
    else
    {
        pSocketClient->slotClosedByServer();
        ui->pPbServerConnect->setText("Connent");
    }
}
void Tab1SocketClient :: slotSocketRecvUpdate(QString strRecvData)
{
    //qDebug() << strRecvData;

    QTime time = QTime::currentTime();
    QString strtime = time.toString();
    //qDebug() << strtime;
    strRecvData.chop(1);
    //qDebug() << strRecvData.indexOf("0") << strRecvData.indexOf("1") ;


    if((strRecvData.indexOf("In1") != -1) || (strRecvData.indexOf("Out1") != -1))
    {
        emit sigTab2RecvData(strRecvData);
        //qDebug() << strRecvData;
    }

    strRecvData = strtime + " " + strRecvData;
    ui->pTeRecvData->append(strRecvData);
    ui->pTeRecvData->moveCursor(QTextCursor::End);


}

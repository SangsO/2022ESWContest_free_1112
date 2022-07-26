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

    m_img[0].load(":/IotQtClient/img/areaemp.png");
    m_img[1].load(":/IotQtClient/img/areacar.png");
    m_img[2].load(":/IotQtClient/img/plug.png");
    m_img[3].load(":/IotQtClient/img/plug.png.png");
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
        //ui->pPBLamp1->setIcon(m_img[2].scaled(50,50,Qt::KeepAspectRatio));
        emit sigSocketSendData("[SPOT1]OFFL");

    }
    else
    {

        ui->pPBLamp1->setChecked(false);
        //ui->pPBLamp1->setIcon(m_img[3].scaled(50,50,Qt::KeepAspectRatio));
        emit sigSocketSendData("[SPOT1]ONL");
    }
}
void Tab4OnOff::slotTwoOnOff(bool check)
{
    if(check)
    {
        ui->pPBLamp2->setChecked(true);
        emit sigSocketSendData("[SPOT2]ON");

    }
    else
    {
        ui->pPBLamp2->setChecked(false);
        emit sigSocketSendData("[SPOT2]OFF");

    }
}
void Tab4OnOff::slotTab4RecvData(QString strRecvData)
{
    //qDebug() << strRecvData;
    strRecvData.replace("[","@");
    strRecvData.replace("]","@");
    QStringList qlist = strRecvData.split("@");
    QString batt = qlist[2];
    int bat = batt.toInt();
    ui->progressBar_2->reset();
    ui->progressBar->setValue(bat);

}
void Tab4OnOff::slotTab4InOutData(QString strInOutData)
{
   // int w = ui->pPBLamp1->width();
   // int h = ui->pPBLamp1->height();
    //qDebug() << strInOutData;

    if(strInOutData.indexOf("1") != -1)
    {
        ui->pcar1->setPixmap(m_img[1].scaled(200,268,Qt::KeepAspectRatio));
        //ui->pPBLamp1->setIcon(m_img[2].scaled(w,h,Qt::KeepAspectRatio));
    }
    if(strInOutData.indexOf("0") != -1)
    {
        ui->pcar1->setPixmap(m_img[0].scaled(200,268,Qt::KeepAspectRatio));
        //ui->pPBLamp1->setIcon(m_img[3].scaled(w,h,Qt::KeepAspectRatio));

    }
}

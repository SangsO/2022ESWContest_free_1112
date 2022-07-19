#ifndef TAB2ONOFF_H
#define TAB2ONOFF_H

#include <QWidget>
#include <QDebug>
#include <QTime>
#include <QMessageBox>
#include "socketclient.h"

namespace Ui {
class Tab2OnOff;
}

class Tab2OnOff : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2OnOff(QWidget *parent = nullptr);
    ~Tab2OnOff();

private:
    Ui::Tab2OnOff *ui;
    SocketClient* pSocketClient;

private slots:
    //void slotConnectToServer(bool);
   // void slotSocketRecvUpdate(QString);
    //void slotSocketSendData();
    //void slotSocketSendData(QString);
    void slotOneOnOff(bool);
    void slotTwoOnOff(bool);


signals:
    void sigSocketSendData(QString);
    //void sigSocketRecv(QString);
    //void Tab2RecvData(QString);
};

#endif // TAB2ONOFF_H

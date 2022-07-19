#ifndef TAB1SOCKETCLIENT_H
#define TAB1SOCKETCLIENT_H

#include <QWidget>
#include <QTime>
#include <QDebug>
#include <QMessageBox>
#include "socketclient.h"


namespace Ui {
class Tab1SocketClient;
}

class Tab1SocketClient : public QWidget
{
    Q_OBJECT

public:
    explicit Tab1SocketClient(QWidget *parent = nullptr);
    ~Tab1SocketClient();

private:
    Ui::Tab1SocketClient *ui;
    SocketClient *pSocketClient;
    QString dlgLineStr;

private slots:
    void slotConnectToServer(bool);
    void slotSocketRecvUpdate(QString);

signals:
    void sigTab2RecvData(QString);
    void sigQfileRecvData(QString);

};

#endif // TAB1SOCKETCLIENT_H

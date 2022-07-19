#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QHostAddress>
#include <QInputDialog>
#include <QMessageBox>
#include <QWidget>
#include <QTime>
#include <QDebug>

#define BLOCK_SIZE      1024
class SocketClient : public QWidget
{
    Q_OBJECT

private:
    QTcpSocket *pQTcpSocket;
    QString SERVERIP = "10.10.141.188";
    int SERVERPOT = 5000;
    QString LOGID = "hello2";
    QString LOGPW = "PASSWD";

public:
    SocketClient(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~SocketClient();

signals:
    void sigSocketRecv(QString);
    //sigSocketRecv(QstrRecvData);

private slots:
    void slotSocketReadData();
    void slotSocketError();
    void slotConnectServer();

public slots:
    void slotConnectToServer(bool&);
    void slotClosedByServer();
    void slotSocketSendData(QString);
};

#endif // CLIENT_H

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <tab1socketclient.h>
#include <tab2database.h>
#include <qfilesocket.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    Tab1SocketClient *pTab1SocketClient;
    Tab2DataBase *ptab2database;
    QfileSocket *pqfilesocket;
};
#endif // MAINWIDGET_H

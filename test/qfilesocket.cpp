#include "qfilesocket.h"
#include "ui_qfilesocket.h"

QfileSocket::QfileSocket(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QfileSocket)
{
    ui->setupUi(this);
    connect(ui->pPbQfileRead, SIGNAL(clicked()),this, SLOT(slotReadLog()));

}

QfileSocket::~QfileSocket()
{
    delete ui;
}
void QfileSocket :: slotQfileRecvData(QString strRecvData)
{

    QFile file("/home/udooer/project/test/serverLog.txt");
    if(!file.open(QFile::WriteOnly | QFile::Append| QFile::Text))
    {
        QMessageBox::warning(this, "title","file not open");
    }
    QTextStream outstream(&file);

    outstream << strRecvData;
    qDebug() << strRecvData;
    outstream.flush();
    file.close();

    /*
    QTextStream out(&file);
    QString text = strRecvData;
    out <<text;
    file.flush();
    file.close();
    */

}
void QfileSocket :: slotReadLog()
{

    QFile file("/home/udooer/project/test/serverLog.txt");
    if(!file.open(QFile::ReadOnly))
    {
        QMessageBox::warning(this, "title","file not open");
    }
/*
    QTextStream in(&file);
    QString text = in.readAll();
    ui->pTeLogData->setPlainText(text);
    file.close();
*/
    ui->pTeLogData->append(file.readAll());
    file.remove();

}
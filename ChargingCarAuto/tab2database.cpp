#include "tab2database.h"
#include "ui_tab2database.h"

Tab2DataBase::Tab2DataBase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab2DataBase)
{
    ui->setupUi(this);
    sqlDb.setDatabaseName("InOut.db");
    if(sqlDb.open()) //true이면 db파일 오픈
    {
        qDebug() << "success DB connection";
    }
    else
        qDebug() << "fail DB connection";

    QString query = "CREATE TABLE InOut_db (id integer primary key,date DATETIME, area VARCHAR(10), status VARCHAR(10))";
    QSqlQuery qry;
    if(!qry.exec(query))
    {
        qDebug() << "already maked query";
    }
    else
    {
        qDebug() << "create query success";
    }
    connect(ui->pPbSearchButton, SIGNAL(clicked()),this, SLOT(slotSearchDb()));
    connect(ui->pPbDeleteButton, SIGNAL(clicked()),this, SLOT(slotDeleteDb()));
    ui->pTableWidget->resizeColumnToContents(0);
    ui->pTableWidget->resizeColumnToContents(3);
    ui->pTableWidget->resizeColumnToContents(4);

}

Tab2DataBase::~Tab2DataBase()
{
    delete ui;
}

void Tab2DataBase:: slotTab2RecvData(QString strRecvData)
{
    qDebug() << strRecvData;
    QDateTime dateTime = QDateTime::currentDateTime();

    strRecvData.replace("[","@");
    strRecvData.replace("]","@");
    QStringList qlist = strRecvData.split("@");
    QString area = qlist[1];
    QString status = qlist[2];
    qDebug() << qlist[1];
    qDebug() << qlist[2];


    QString queryData = "insert into InOut_db(date,area,status) values('"+dateTime.toString("yy/MM/dd hh:mm:ss") +"','" +area+ "','"+ status +"')";
    QSqlQuery qryData;
    if(qryData.exec(queryData))
    {
        qDebug() << "Insert Ok";
    }
    else
    {
        qDebug() << qryData.lastError().text();
    }
}
void Tab2DataBase:: slotSearchDb()
{
    QSqlQuery qrySearch;
    QString querySearch;
    QDateTime dateTimeFrom = ui->pDteFrom->dateTime();
    QString strFrom = dateTimeFrom.toString("yy/MM/dd hh:mm:ss");
    QDateTime dateTimeTo = ui->pDteTo->dateTime();
    QString strTo = dateTimeTo.toString("yy/MM/dd hh:mm:ss");

    int rowCount = 0;
    ui->pTableWidget->clearContents();

    querySearch = "select * from InOut_db where date >'" + strFrom +"' AND date <'" +strTo +"'";
    if(qrySearch.exec(querySearch))
    {
        while (qrySearch.next()) {
            rowCount++;
            ui->pTableWidget->setRowCount(rowCount);
            QTableWidgetItem * id = new QTableWidgetItem();
            QTableWidgetItem * date = new QTableWidgetItem();
            QTableWidgetItem * area = new QTableWidgetItem();
            QTableWidgetItem * status = new QTableWidgetItem();
            id->setText(qrySearch.value("id").toString());
            date->setText(qrySearch.value("date").toString());
            area->setText(qrySearch.value("area").toString());
            status->setText(qrySearch.value("status").toString());
            ui->pTableWidget->setItem(rowCount-1, 0, id);
            ui->pTableWidget->setItem(rowCount-1, 1, date);
            ui->pTableWidget->setItem(rowCount-1, 2, area);
            ui->pTableWidget->setItem(rowCount-1, 3, status);

        }
    }
}


void Tab2DataBase:: slotDeleteDb()
{
    QSqlQuery qryDelete;
    QString queryDelete;
    QDateTime dateTimeFrom = ui->pDteFrom->dateTime();
    QString strFrom = dateTimeFrom.toString("yy/MM/dd hh:mm:ss");
    QDateTime dateTimeTo = ui->pDteTo->dateTime();
    QString strTo = dateTimeTo.toString("yy/MM/dd hh:mm:ss");

    queryDelete = "delete from InOut_db where date>'" + strFrom +"' AND date <'" +strTo +"'";
    if(qryDelete.exec(queryDelete))
    {
        ui->pTableWidget->clearContents();
    }

}


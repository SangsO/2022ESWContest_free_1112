#include "tab6parkinglotlog.h"
#include "ui_tab6parkinglotlog.h"

Tab6ParkinglotLog::Tab6ParkinglotLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab6ParkinglotLog)
{
    ui->setupUi(this);
    qDebug() << "devices" <<QSqlDatabase::drivers();
    qDebug() << QCoreApplication::libraryPaths();
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("10.10.141.188");
    db.setUserName("iot");
    db.setPassword("kcci");
    db.setDatabaseName("vehicle_info");
    bool ok =db.open();
    if(ok)
    {
        qDebug() << "Database open\n";
    }
    else
        qDebug() << "Database not open\n" ;

    model1 = new QSqlTableModel(this);
    model1->setTable("parkinglot_log");
    ui->pTvParkingLogDb->setModel(model1);

    connect(ui->pPbReport,SIGNAL(clicked()),this,SLOT(slottab6database()));
}

Tab6ParkinglotLog::~Tab6ParkinglotLog()
{
    delete ui;
}
void Tab6ParkinglotLog::slottab6database()
{
    model1->select();

}

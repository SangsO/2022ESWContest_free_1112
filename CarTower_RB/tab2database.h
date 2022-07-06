#ifndef TAB2DATABASE_H
#define TAB2DATABASE_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>

namespace Ui {
class Tab2DataBase;
}

class Tab2DataBase : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2DataBase(QWidget *parent = nullptr);
    ~Tab2DataBase();

private:
    Ui::Tab2DataBase *ui;
    QSqlDatabase sqlDb;

private slots:
    void slotTab2RecvData(QString);
    void slotSearchDb();
    void slotDeleteDb();
};

#endif // TAB2DATABASE_H

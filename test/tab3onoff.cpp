#include "tab3onoff.h"
#include "ui_tab3onoff.h"

Tab3OnOff::Tab3OnOff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab3OnOff)
{
    ui->setupUi(this);
}

Tab3OnOff::~Tab3OnOff()
{
    delete ui;
}

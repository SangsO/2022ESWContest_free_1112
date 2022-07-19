#ifndef TAB3ONOFF_H
#define TAB3ONOFF_H

#include <QWidget>

namespace Ui {
class Tab3OnOff;
}

class Tab3OnOff : public QWidget
{
    Q_OBJECT

public:
    explicit Tab3OnOff(QWidget *parent = nullptr);
    ~Tab3OnOff();

private:
    Ui::Tab3OnOff *ui;
};

#endif // TAB3ONOFF_H

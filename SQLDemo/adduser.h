#ifndef ADDUSER_H
#define ADDUSER_H

#include <QWidget>
#include "sqldemo.h"

namespace Ui {
class AddUser;
}

class AddUser : public QWidget
{
    Q_OBJECT

public:
    explicit AddUser(QWidget *parent = 0);
    ~AddUser();

private:
    Ui::AddUser *ui;
private slots:
    void addUserSlot();
    void returnSlot();
};

#endif // ADDUSER_H

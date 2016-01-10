#ifndef USERPAY_H
#define USERPAY_H

#include <QWidget>
#include "homepage.h"
#include <QString>
namespace Ui {
class UserPay;
}

class UserPay : public QWidget
{
    Q_OBJECT

signals:
    void update();

public:
    explicit UserPay(QWidget *parent = 0);
    ~UserPay();

private:
    Ui::UserPay *ui;
private slots:
    void returnSlot();
    void searchSlot();
    void chargeSlot();
};

#endif // USERPAY_H

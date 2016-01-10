#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

#include "deleteinfo.h"
#include "adduser.h"
#include "modifyinfo.h"
#include "queryuser.h"
#include "userpay.h"
namespace Ui {
class HomePage;
}

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = 0);
    ~HomePage();

private:
    Ui::HomePage *ui;
private slots:
    void showDelete();
    void showAddUser();
    void showModifyInfo();
    void showquery();
    void showuserpay();
};

#endif // HOMEPAGE_H

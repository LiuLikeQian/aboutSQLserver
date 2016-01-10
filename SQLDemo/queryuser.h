#ifndef QUERYUSER_H
#define QUERYUSER_H

#include <QWidget>
#include "homepage.h"
namespace Ui {
class QueryUser;
}

class QueryUser : public QWidget
{
    Q_OBJECT

public:
    explicit QueryUser(QWidget *parent = 0);
    ~QueryUser();

private:
    Ui::QueryUser *ui;
private slots:
    void returnSlot();
private slots:
    void searchSlot();
};

#endif // QUERYUSER_H

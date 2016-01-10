#ifndef MODIFYINFO_H
#define MODIFYINFO_H

#include <QWidget>
#include "homepage.h"
namespace Ui {
class modifyInfo;
}

class modifyInfo : public QWidget
{
    Q_OBJECT

public:
    explicit modifyInfo(QWidget *parent = 0);
    ~modifyInfo();

private:
    Ui::modifyInfo *ui;
private slots:
    void returnSlot();
    void researchSlot();
    void ModifyUserInfoSlot();
};

#endif // MODIFYINFO_H

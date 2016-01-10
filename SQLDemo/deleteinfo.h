#ifndef DELETEINFO_H
#define DELETEINFO_H

#include <QWidget>
#include "homepage.h"
namespace Ui {
class DeleteInfo;
}

class DeleteInfo : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteInfo(QWidget *parent = 0);
    ~DeleteInfo();

private:
    Ui::DeleteInfo *ui;
private slots:
    void returnSlot();
    void researchSlot();
    void deleteSlot();
};

#endif // DELETEINFO_H

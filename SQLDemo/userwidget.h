#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include "sqldemo.h"
namespace Ui {
class UserWidget;
}

class UserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserWidget(QWidget *parent = 0);
    ~UserWidget();
    QString ID;
   signals:
    void StartSignal(QString);
    void UpdateSignal();
private:
    Ui::UserWidget *ui;
private slots:
    void returnSlot();
public slots:
    void StartSlot(QString);
    void updateSlot();
};

#endif // USERWIDGET_H

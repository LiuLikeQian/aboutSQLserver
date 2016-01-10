#ifndef SQLDEMO_H
#define SQLDEMO_H

#include <QWidget>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSqlError>
#include <QSqlQuery>
#include <QRegExp>
#include <QValidator>
#include <QIcon>

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "homepage.h"
#include "userwidget.h"

namespace Ui {
class SQLDemo;
}

class SQLDemo : public QWidget
{
    Q_OBJECT

public:
    explicit SQLDemo(QWidget *parent = 0);
    ~SQLDemo();

private:
    Ui::SQLDemo *ui;
private slots:
    void loadSlot();

};

#endif // SQLDEMO_H

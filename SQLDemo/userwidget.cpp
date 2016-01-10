#include "userwidget.h"
#include "ui_userwidget.h"

UserWidget::UserWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWidget)
{
    ui->setupUi(this);
    ui->UserInfoTextEdit->setReadOnly(true);
    setMaximumSize(500,400);
    setMinimumSize(500,400);
    this->setWindowTitle("闽江计费系统");

    QIcon icon(":/image/github.png");
    setWindowIcon(icon);

    connect(ui->SafeExitBtn,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->CancellationBtn,SIGNAL(clicked(bool)),this,SLOT(returnSlot()));
    connect(this,SIGNAL(StartSignal(QString)),this,SLOT(StartSlot(QString)));
    connect(this,SIGNAL(UpdateSignal()),this,SLOT(updateSlot()));

    /*
    QSqlQuery query;
    QString Name,Phone,Addr,Blance,CurrentCost,CallTime,callCost;
    QString index;
    qDebug()<<ID<<"haha";
    query.exec(QString("select name from phoneuser where ID='%1'").arg(ID));
    query.next();
    Name = query.value(0).toString().simplified();

    query.exec(QString("select phone from phoneuser where ID='%1'").arg(ID));
    query.next();
    Phone = query.value(0).toString().simplified();

    query.exec(QString("select addr from phoneuser where ID='%1'").arg(ID));
    query.next();
    Addr = query.value(0).toString().simplified();

    query.exec(QString("select blance from charge where Phone='%1'").arg(Phone));
    query.next();
    Blance = query.value(0).toString().simplified();

    query.exec(QString("select currentcost from bill where Phone='%1'").arg(Phone));
    query.next();
    CurrentCost = query.value(0).toString().simplified();

    query.exec(QString("select calltime from bill where Phone='%1'").arg(Phone));
    query.next();
    CallTime = query.value(0).toString().simplified();

    query.exec(QString("select callcost from bill where Phone='%1'").arg(Phone));
    query.next();
    callCost = query.value(0).toString().simplified();


    ui->UserInfoTextEdit->append("Name: "+Name);
    ui->UserInfoTextEdit->append("Phone: "+Phone);
    ui->UserInfoTextEdit->append("Addr: "+Addr);
    ui->UserInfoTextEdit->append("Blance: "+Blance+"¥");
    ui->UserInfoTextEdit->append("CurrentCost: "+CurrentCost+"¥");
    ui->UserInfoTextEdit->append("CallTime: "+CallTime+"s");
    ui->UserInfoTextEdit->append("CallCost: "+callCost+"¥");
    */
}

UserWidget::~UserWidget()
{
    delete ui;
}

void UserWidget::returnSlot()
{
    this->close();
    SQLDemo * PSQLDemo = new SQLDemo;
    PSQLDemo->show();
}
void UserWidget::StartSlot(QString indexID)
{
    ID = indexID;
    emit UpdateSignal();
}

void UserWidget::updateSlot()
{
    QSqlQuery query;
    QString Name,Phone,Addr,Blance,CurrentCost,CallTime,callCost;
    QString index;

    query.exec(QString("select name from phoneuser where ID='%1'").arg(ID));
    query.next();
    Name = query.value(0).toString().simplified();

    query.exec(QString("select phone from phoneuser where ID='%1'").arg(ID));
    query.next();
    Phone = query.value(0).toString().simplified();

    query.exec(QString("select addr from phoneuser where ID='%1'").arg(ID));
    query.next();
    Addr = query.value(0).toString().simplified();

    query.exec(QString("select blance from charge where Phone='%1'").arg(Phone));
    query.next();
    Blance = query.value(0).toString().simplified();

    query.exec(QString("select currentcost from bill where Phone='%1'").arg(Phone));
    query.next();
    CurrentCost = query.value(0).toString().simplified();

    query.exec(QString("select calltime from bill where Phone='%1'").arg(Phone));
    query.next();
    CallTime = query.value(0).toString().simplified();

    query.exec(QString("select callcost from bill where Phone='%1'").arg(Phone));
    query.next();
    callCost = query.value(0).toString().simplified();


    ui->WelcomeLabel->setText("welcome "+Name);
    ui->UserInfoTextEdit->append("Name: "+Name);
    ui->UserInfoTextEdit->append("Phone: "+Phone);
    ui->UserInfoTextEdit->append("Addr: "+Addr);
    ui->UserInfoTextEdit->append("Blance: "+Blance+"¥");
    ui->UserInfoTextEdit->append("CurrentCost: "+CurrentCost+"¥");
    ui->UserInfoTextEdit->append("CallTime: "+CallTime+"s");
    ui->UserInfoTextEdit->append("CallCost: "+callCost+"¥");
}

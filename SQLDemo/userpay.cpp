#include "userpay.h"
#include "ui_userpay.h"

UserPay::UserPay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserPay)
{
    ui->setupUi(this);
    ui->UserInfoTextEdit->setReadOnly(true);
    setMaximumSize(500,400);
    setMinimumSize(500,400);
    this->setWindowTitle("闽江计费系统");
    QRegExp CountDator("[0-9]{18,18}");
    QValidator *validator = new QRegExpValidator(CountDator,0);
    ui->IDLineEdit->setValidator(validator);

    QIcon icon(":/image/github.png");
    setWindowIcon(icon);

    connect(ui->returnBtn,SIGNAL(clicked(bool)),this,SLOT(returnSlot()));
    connect(ui->ResearchBtn,SIGNAL(clicked(bool)),this,SLOT(searchSlot()));
    connect(ui->RechangeBtn,SIGNAL(clicked(bool)),this,SLOT(chargeSlot()));
    connect(this,SIGNAL(update()),this,SLOT(searchSlot()));
}

UserPay::~UserPay()
{
    delete ui;
}

void UserPay::returnSlot()
{
    this->close();
    HomePage *PHomePage = new HomePage;
    PHomePage->show();
}

void UserPay::searchSlot()
{
    ui->UserInfoTextEdit->clear();
    QString index = ui->IDLineEdit->text();
    QString billInfo;
    QString UserInfo;
    QSqlQuery query;
    if(query.exec(QString("select name from phoneuser where ID='%1'").arg(index)))
    {
        query.next();
        UserInfo = query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("Name: "+UserInfo);
        ui->UserInfoTextEdit->append("Id"+index);

        query.exec(QString("select addr from phoneuser where ID='%1'").arg(index));
        query.next();
        UserInfo = query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("Addr: "+UserInfo);

        query.exec(QString("select phone from phoneuser where ID='%1'").arg(index));
        query.next();
        UserInfo = query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("Phone: "+UserInfo);

        ui->UserInfoTextEdit->append("");




        query.exec(QString("select phone from phoneuser where ID='%1'").arg(index));
        query.next();
        billInfo = query.value(0).toString().simplified();

        query.exec(QString("select currentcost from bill where Phone='%1'").arg(billInfo));
        query.next();
        UserInfo = query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("currentcost: "+UserInfo);

        query.exec(QString("select calltime from bill where Phone='%1'").arg(billInfo));
        query.next();
        UserInfo = query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("calltime: "+UserInfo);

        query.exec(QString("select callcost from bill where Phone='%1'").arg(billInfo));
        query.next();
        UserInfo = query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("callcost: "+UserInfo);

        ui->UserInfoTextEdit->append("");

        query.exec(QString("select blance from charge where Phone='%1'").arg(billInfo));
        query.next();
        UserInfo = query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("blance: "+UserInfo);

        query.exec(QString("select receiveble from charge where Phone='%1'").arg(billInfo));
        query.next();
        UserInfo = query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("receiveble: "+UserInfo);

        query.exec(QString("select receipts from charge where Phone='%1'").arg(billInfo));
        query.next();
        UserInfo = query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("receipts: "+UserInfo);


    }
    else
    {
        QMessageBox::information(this,"No this user!","tips",QMessageBox::Yes);
    }
}

void UserPay::chargeSlot()
{
    QSqlQuery query;
    QString ID,PhoneNum;
    QString money = ui->MoneyLineEdit->text();
    ID = ui->IDLineEdit->text();
    query.exec(QString("select phone from phoneuser where ID='%1'").arg(ID));
    query.next();
    PhoneNum = query.value(0).toString().simplified();

    query.exec(QString("update bill set currentcost = currentcost+'%1' where Phone = '%2'").arg(money).arg(PhoneNum));
    query.exec(QString("update charge set receiveble = '%1' where Phone = '%2'").arg(money).arg(PhoneNum));
    query.exec(QString("update charge set receipts = '%1' where Phone = '%2'").arg(money).arg(PhoneNum));
    query.exec(QString("update charge set blance = blance + '%1' where Phone = '%2'").arg(money).arg(PhoneNum));
    ui->MoneyLineEdit->clear();
    emit  update();
}

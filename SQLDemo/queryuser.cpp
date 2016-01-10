#include "queryuser.h"
#include "ui_queryuser.h"

QueryUser::QueryUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueryUser)
{
    ui->setupUi(this);
    ui->UserInfoTextEdit->setReadOnly(true);
    setMaximumSize(500,400);
    setMinimumSize(500,400);
    this->setWindowTitle("闽江计费系统");
    QRegExp CountDator("[0-9]{18,18}");
    QValidator *validator = new QRegExpValidator(CountDator,0);
    ui->UserIDLineEdit->setValidator(validator);

    QIcon icon(":/image/github.png");
    setWindowIcon(icon);

    connect(ui->returnBtn,SIGNAL(clicked(bool)),this,SLOT(returnSlot()));
    connect(ui->QueryBtn,SIGNAL(clicked(bool)),this,SLOT(searchSlot()));
}

QueryUser::~QueryUser()
{
    delete ui;
}

void QueryUser::returnSlot()
{
    this->close();
    HomePage *PHomePage = new HomePage;
    PHomePage->show();
}

void QueryUser::searchSlot()
{
    QSqlQuery query;
    QString index;
    QString UserID = ui->UserIDLineEdit->text();
    if(query.exec(QString("select name from phoneuser where ID='%1'").arg(UserID)))
    {
        query.next();
        index = "Name: " + query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append(index);

        ui->UserInfoTextEdit->append("Id: "+ UserID);

        query.exec(QString("select addr from phoneuser where ID='%1'").arg(UserID));
        query.next();
        index = "Addr: " + query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append(index);

        query.exec(QString("select phone from phoneuser where ID='%1'").arg(UserID));
        query.next();
        index = "phone: " + query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append(index);

        index = query.value(0).toString().simplified();

        QString billIndex;
        query.exec(QString("select currentcost from bill where Phone='%1'").arg(index));
        query.next();
        billIndex =  query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("");
        ui->UserInfoTextEdit->append("currentcost: " +billIndex +"¥");



        query.exec(QString("select calltime from bill where Phone='%1'").arg(index));
        query.next();
        billIndex =  query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("calltime: " +billIndex+"s");

        query.exec(QString("select callcost from bill where Phone='%1'").arg(index));
        query.next();
        billIndex =  query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("callcost: " +billIndex+"¥");

        ui->UserInfoTextEdit->append("");
        query.exec(QString("select blance from charge where Phone='%1'").arg(index));
        query.next();
        billIndex =  query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("blance: " +billIndex+"¥");

        query.exec(QString("select receiveble from charge where Phone='%1'").arg(index));
        query.next();
        billIndex =  query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("receiveble: " +billIndex+"¥");

        query.exec(QString("select receipts from charge where Phone='%1'").arg(index));
        //query.exec("select receipts from charge where Phone='18060843504'");
        query.next();
        billIndex =  query.value(0).toString().simplified();
        ui->UserInfoTextEdit->append("receipts: " +billIndex+"¥");
    }
    else
    {
        QMessageBox::information(this,"tips","No this User");
    }

}

#include "modifyinfo.h"
#include "ui_modifyinfo.h"

modifyInfo::modifyInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modifyInfo)
{
    ui->setupUi(this);
    setMaximumSize(500,400);
    setMinimumSize(500,400);
    this->setWindowTitle("闽江计费系统");
    QRegExp CountDator("[0-9]{18,18}");

    QIcon icon(":/image/github.png");
    setWindowIcon(icon);

    QValidator *validator = new QRegExpValidator(CountDator,0);
    ui->SIDLineEdit->setValidator(validator);
    connect(ui->ReturnBtn,SIGNAL(clicked(bool)),this,SLOT(returnSlot()));
    connect(ui->SearchBtn,SIGNAL(clicked(bool)),this,SLOT(researchSlot()));
    connect(ui->modifyBtn,SIGNAL(clicked(bool)),this,SLOT(ModifyUserInfoSlot()));

}

modifyInfo::~modifyInfo()
{
    delete ui;
}

void modifyInfo::returnSlot()
{
    this->close();
    HomePage *PHomePage = new HomePage;
    PHomePage->show();
}


void modifyInfo::researchSlot()
{
    QString index = ui->SIDLineEdit->text();
    QSqlQuery query;
    /*qDebug()<<index;
    query.exec(QString("select name from phoneuser where ID='%1'").arg(index));
    query.next();
    QString bbq = query.value(0).toString();
    bbq = bbq.simplified();
    qDebug()<<bbq<<"hello";*/

    if(query.exec(QString("select name from phoneuser where ID='%1'").arg(index)))
    {
        query.next();
        QString UserInfo = query.value(0).toString();
        UserInfo = UserInfo.simplified();
        qDebug()<<UserInfo;
        ui->NameLineEdit->setText(UserInfo);
        ui->IDLineEdit->setText(index);

        query.exec(QString("select Phone from phoneuser where ID='%1'").arg(index));
        query.next();
        UserInfo = query.value(0).toString();
        UserInfo = UserInfo.simplified();
        ui->PhoneLineEdit->setText(UserInfo);


        query.exec(QString("select addr from phoneuser where ID='%1'").arg(index));
        query.next();
        UserInfo = query.value(0).toString();
        UserInfo = UserInfo.simplified();
        ui->AddrLineEdit->setText(UserInfo);
    }
    else
    {
        QMessageBox::information(this,"No this user!","tips",QMessageBox::Yes);
    }
}

void modifyInfo::ModifyUserInfoSlot()
{
    QSqlQuery query;
    QString Phone,Addr,Name;
    QString UserStr = ui->SIDLineEdit->text();
    QString account,passStr;

    query.exec(QString("select account from phoneuser where ID='%1'").arg(UserStr));
    query.next();
    account = query.value(0).toString().simplified();


    query.exec(QString("select password from phoneuser where ID='%1'").arg(UserStr));
    query.next();
    passStr = query.value(0).toString().simplified();
    query.exec(QString("delete from phoneuser where ID='%1'").arg(UserStr));

    qDebug()<<UserStr <<account<<passStr;

    UserStr = ui->IDLineEdit->text();
    Name = ui->NameLineEdit->text();
    Phone = ui->PhoneLineEdit->text();
    Addr = ui->AddrLineEdit->text();

    query.exec(QString("Insert into phoneuser values('%1','%2' ,'%3','%4','%5','%6')").arg(Name).arg(Phone).arg(Addr).arg(UserStr).arg(account).arg(passStr));

    ui->SIDLineEdit->clear();
    ui->IDLineEdit->clear();
    ui->NameLineEdit->clear();
    ui->PhoneLineEdit->clear();
    ui->AddrLineEdit->clear();
    QMessageBox::information(this,"tips","modify successful");
}

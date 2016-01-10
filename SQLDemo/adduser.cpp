#include "adduser.h"
#include "ui_adduser.h"

AddUser::AddUser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddUser)
{
    ui->setupUi(this);
    setMaximumSize(500,400);
    setMinimumSize(500,400);
    this->setWindowTitle("闽江计费系统");
    QRegExp CountDator("[0-9]{18,18}");

    QIcon icon(":/image/github.png");
    setWindowIcon(icon);

    QValidator *validator = new QRegExpValidator(CountDator,0);
    ui->IDLineEdit->setValidator(validator);
    connect(ui->OkBtn,SIGNAL(clicked(bool)),this,SLOT(addUserSlot()));
    connect(ui->returnBtn,SIGNAL(clicked(bool)),this,SLOT(returnSlot()));

}

AddUser::~AddUser()
{
    delete ui;
}

void AddUser::addUserSlot()
{
    QString Name = ui->NameLineEdit->text();
    QString PhoneNum = ui->PhoneLineEdit->text();
    QString Addr = ui->AddrLineEdit->text();
    QString ID = ui->IDLineEdit->text();
    if(Name.isEmpty()|PhoneNum.isEmpty()|Addr.isEmpty()|ID.isEmpty())
    {
        QMessageBox::information(this,"tips","Please complete information",QMessageBox::Yes);
        return ;
    }
    QSqlQuery query;
    if(query.exec(QString("Insert into phoneuser values('%1','%2' ,'%3','%4','%5','%6')").arg(Name).arg(PhoneNum).arg(Addr).arg(ID).arg(PhoneNum).arg(123456)))
       {
        query.exec(QString("Insert into charge values('%1','%2' ,'%3','%4','%5')").arg(Name).arg(PhoneNum).arg(0).arg(0).arg(0));
        query.exec(QString("Insert into bill values('%1','%2' ,'%3','%4')").arg(PhoneNum).arg(0).arg(0).arg(0));
        int index = QMessageBox::information(this,"tips","insert successful and Return to the upper layer?",QMessageBox::Yes,QMessageBox::Cancel);
        if(index == QMessageBox::Yes)
        {
            this->close();
            HomePage *PHomePage = new HomePage;
            PHomePage->show();
        }
        else if(index == QMessageBox::Cancel)
            {
            ui->NameLineEdit->clear();
            ui->PhoneLineEdit->clear();
            ui->AddrLineEdit->clear();
            ui->IDLineEdit->clear();
            qDebug()<<"user cansel it.";
            }
    }


}


void AddUser::returnSlot()
{
    this->close();
    HomePage *PHomePage = new HomePage;
    PHomePage->show();
}

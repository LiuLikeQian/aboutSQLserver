#include "deleteinfo.h"
#include "ui_deleteinfo.h"

DeleteInfo::DeleteInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteInfo)
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
    connect(ui->ReturnBtn,SIGNAL(clicked(bool)),this,SLOT(returnSlot()));
    connect(ui->SearchBtn,SIGNAL(clicked(bool)),this,SLOT(researchSlot()));
    connect(ui->DeletBtn,SIGNAL(clicked(bool)),this,SLOT(deleteSlot()));
}

DeleteInfo::~DeleteInfo()
{
    delete ui;
}

void DeleteInfo::returnSlot()
{
    this->close();
    HomePage *PhomePage = new HomePage;
    PhomePage->show();
}

void DeleteInfo::researchSlot()
{
    QString index = ui->IDLineEdit->text();

    ui->UserTextEdit->clear();

    QSqlQuery query;
    if(query.exec(QString("select name from phoneuser where ID='%1'").arg(index)))
    {
        query.next();
        QString UserInfo = query.value(0).toString().simplified();
        ui->UserTextEdit->append("Name: "+UserInfo);

        ui->UserTextEdit->append("Id: "+index);

        query.exec(QString("select phone from phoneuser where ID='%1'").arg(index));
        query.next();
        UserInfo = query.value(0).toString().simplified();
        ui->UserTextEdit->append("Phone: " +UserInfo );

        query.exec(QString("select addr from phoneuser where ID='%1'").arg(index));
        query.next();
        UserInfo = query.value(0).toString().simplified();
        ui->UserTextEdit->append("Addr: " +UserInfo );
    }
    else
    {
        QMessageBox::information(this,"tips","No this user!",QMessageBox::Yes);
    }
}

void DeleteInfo::deleteSlot()
{

   int index = QMessageBox::information(this,"tips","if u want delete he?",QMessageBox::Yes,QMessageBox::No,QMessageBox::Cancel);
           if(index == QMessageBox::Yes)
        {
           QSqlQuery query;

           QString UserStr = ui->IDLineEdit->text();

           query.exec(QString("select phone from phoneuser where ID='%1'").arg(UserStr));
           query.next();
           QString PhoneNum =query.value(0).toString().simplified();
           query.exec(QString("delete from charge where Phone='%1'").arg(PhoneNum));
           query.exec(QString("delete from bill where Phone='%1'").arg(PhoneNum));

           query.next();




           if(query.exec(QString("delete from phoneuser where ID='%1'").arg(UserStr)))
           {
               ui->UserTextEdit->clear();
               ui->IDLineEdit->clear();
               QMessageBox::information(this,"tips","delete successful",QMessageBox::Yes);
                       return;
           }
        else
           {

               QMessageBox::information(this,"tips","delete fail!",QMessageBox::Yes);
               return;
           }
        }
           else if(index == QMessageBox::No)
           return;
           else if(index == QMessageBox::Cancel)
           return;

}

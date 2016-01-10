#include "sqldemo.h"
#include "ui_sqldemo.h"

SQLDemo::SQLDemo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SQLDemo)
{
    ui->setupUi(this);
    //govermen offer:1 oracle,2 sql server,3 access

    ui->ForgetLabel->setOpenExternalLinks(true);
    ui->ForgetLabel->setText(tr("<a href=\"http://www.taijiandan.net/wuhan_weixin/user/login\">forget password"));

    setMaximumSize(450,300);
    setMinimumSize(450,300);
    this->setWindowTitle("LoadWidget");

    //QIcon icon(":/image/github.png");
    //setWindowIcon(icon);



    QRegExp CountDator("^[0-9a-zA-Z]{11}$");
    QValidator *validator = new QRegExpValidator(CountDator,0);
    ui->CountLineEdit->setValidator(validator);

    QRegExp PassWord("[A-Za-z0-9_]{6,15}");
    QValidator *PassWordvalidator = new QRegExpValidator(PassWord,0);
    ui->PasswordLineEdit->setValidator(PassWordvalidator);

    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
     db.setDatabaseName(QString("DRIVER={SQL SERVER};"
      "SERVER=%1;"     //servername
      "DATABASE=%2;"   //sqlname
      "UID=%3;"        //loadid
      "PWD=%4;"        //password
      ).arg("DELL-PC")
      .arg("PhoneCount")
      .arg("SQLproject")
      .arg("mylocalhost")
      );


     if (!db.open())
      {
       //QMessageBox::about(this,"Database Error",db.lastError().text());
       qDebug()<<"Database Error";
       qDebug()<<db.lastError();
      }
     else
     {
        //QSqlQuery query;
        //ADD query.exec("Insert into phoneuser values('李丽','18079930119' ,'福建师大','4322199812091153')");
        //Deletequery.exec("delete from phoneuser where name='李明'");
        //modify query.exec("update phoneuser set name = '李明' where name = '李华'");
        //find
        //query.exec("select name from phoneuser where addr='福建师大'");
        //query.next();//将指针指向查询的到第一条记录 并且只能查询到第一条记录，要查下一条那么得指针后移动
        //qDebug()<<query.value(0).toString();
        //query.next();
        //qDebug()<<query.value(0).toString();    //永远是zhixiang 第一条

        //int max_id = 0;
        //while(query.next())
        //{
        //max_id = query.value(0).toInt();
        //qDebug()<<query.value(0).toString() <<QString("max id:%1").arg(max_id);
        //}
        qDebug()<<"congratulation";
     }

     ui->PasswordLineEdit->setEchoMode(QLineEdit::Password);

     connect(ui->LoadBtn,SIGNAL(clicked(bool)),this,SLOT(loadSlot()));

}

SQLDemo::~SQLDemo()
{
    delete ui;
}


void SQLDemo::loadSlot()
{
    QString CountStr = ui->CountLineEdit->text();
    QString PassWordStr = ui->PasswordLineEdit->text();
    QString password;
    QSqlQuery query;
    QString index,UserID;

    if(CountStr.isEmpty()|PassWordStr.isEmpty())
    {
        QMessageBox::information(this,"tips","Count/Password is null!",QMessageBox::Yes);
        return;
    }




    if(ui->MassgeradioBtn->isChecked())
    {

        query.exec(QString("select name from administrators where name='%1'").arg(CountStr));
        query.next();
        index = query.value(0).toString().simplified();
        if(index != CountStr)
        {
            QMessageBox::information(this,"tips","The count is non-existent!");
            //qDebug()<<index<<CountStr;
            return;
        }
        query.exec(QString("select password from administrators where password='%1'").arg(PassWordStr));
        query.next();
        password = query.value(0).toString().simplified();
        if(password == PassWordStr)
        {
            //qDebug()<<password<<PassWordStr;
            this->close();
            HomePage * showWidget = new HomePage;
            showWidget->show();
        }
        else
        {
            QMessageBox::information(this,"tips","The password is error!");
            //qDebug()<<password<<PassWordStr;
            return;
        }

    }
    else if(ui->UserRadioBtn->isChecked())
    {
        query.exec(QString("select ID from phoneuser where account='%1'").arg(CountStr));
        query.next();
        UserID = query.value(0).toString().simplified();



        query.exec(QString("select account from phoneuser where account='%1'").arg(CountStr));
        query.next();
        index = query.value(0).toString().simplified();
        if(index !=CountStr)
        {
            QMessageBox::information(this,"tips","The count is non-existent!");
            qDebug()<<index<<CountStr;
            return;
        }
        else
        {
            query.exec(QString("select password from phoneuser where password='%1'").arg(PassWordStr));
            query.next();
            password = query.value(0).toString().simplified();
            if(password == PassWordStr)
            {
                this->close();
                UserWidget *PUserWidget = new UserWidget;
                PUserWidget->show();
                emit PUserWidget->StartSignal(UserID);
                //PUserWidget->ID = UserID;
                qDebug()<<password<<PassWordStr<<PUserWidget->ID;
                qDebug()<<"user is checked!";
            }
            else
            {
                QMessageBox::information(this,"tips","The password is error!");
                return;
            }
}
    }
    else
    {
        QMessageBox::information(this,"tips","Please choose type!");
        return;
    }
}

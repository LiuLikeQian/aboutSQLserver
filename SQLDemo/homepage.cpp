#include "homepage.h"
#include "ui_homepage.h"

HomePage::HomePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePage)
{
    ui->setupUi(this);
    setMaximumSize(500,400);
    setMinimumSize(500,400);
    this->setWindowTitle("闽江计费系统");

    QIcon icon(":/image/github.png");
    setWindowIcon(icon);

    connect(ui->ExitBtn,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->AddBtn,SIGNAL(clicked(bool)),this,SLOT(showAddUser()));
    connect(ui->DeleteBtn,SIGNAL(clicked(bool)),this,SLOT(showDelete()));
    connect(ui->ModifyBtn,SIGNAL(clicked(bool)),this,SLOT(showModifyInfo()));
    connect(ui->QueryBtn,SIGNAL(clicked(bool)),this,SLOT(showquery()));
    connect(ui->UserPayBtn,SIGNAL(clicked(bool)),this,SLOT(showuserpay()));

}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::showDelete()
{
    this->close();
    DeleteInfo *PDeleteInfo = new DeleteInfo;
    PDeleteInfo->show();

}

void HomePage::showModifyInfo()
{
    this->close();
    modifyInfo *PmodifyInfo = new modifyInfo;
    PmodifyInfo->show();
}


void HomePage::showAddUser()
{
    this->close();
    AddUser *PAddUser = new AddUser;
    PAddUser->show();
}

void HomePage::showquery()
{
    this->close();
    QueryUser *PQueryUser = new QueryUser;
    PQueryUser->show();
}

void HomePage::showuserpay()
{
    this->close();
    UserPay *PUserPay = new UserPay;
    PUserPay->show();
}

#include "login.h"
#include "ui_login.h"
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_bt_login_clicked()
{
    emit sendLoginSuccess();
}

void login::on_bt_exit_clicked()
{
    exit(0);
}



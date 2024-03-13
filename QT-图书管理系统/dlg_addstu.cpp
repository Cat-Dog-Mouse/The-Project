#include "dlg_addstu.h"
#include "ui_dlg_addstu.h"
#include "stusql.h"
#include <QMessageBox>
Dlg_AddStu::Dlg_AddStu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_AddStu)
{
    ui->setupUi(this);
}

Dlg_AddStu::~Dlg_AddStu()
{
    delete ui;
}

void Dlg_AddStu::setType(bool isAdd,StuInfo info)
{
    m_isAdd = isAdd;
    m_info = info;
    ui->le_sno->setText(info.sno);
    ui->sb_age->setValue(info.sage);
    ui->le_sex->setText(info.ssex);
    ui->le_phone->setText(info.phone);
    ui->le_name->setText(info.sname);

}

void Dlg_AddStu::on_btn_cancel_clicked()
{
    this->hide();
}

void Dlg_AddStu::on_btn_save_clicked()
{
    StuInfo info;
    auto ptr = stuSql::getinstance();
    info.sno = ui->le_sno->text();
    info.sage = ui->sb_age->text().toUInt();
    info.ssex = ui->le_sex->text();
    info.phone = ui->le_phone->text();
    info.sname = ui->le_name->text();
    if(m_isAdd){
        ptr->addStu(info);
    }else
    {
        ptr->UpdateStuInfo(info);
    }
    QMessageBox::information(nullptr,"信息","存储成功");
    this->hide();


}

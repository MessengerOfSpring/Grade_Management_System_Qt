// =====================================================================================
//
//       Filename:  AdminDlg.cpp
//
//    Description:  Enroll for admin
//
//        Version:  1.0
//        Created:  07/06/2016 09:58
//       Revision:  none
//       Compiler:  g++
//
//         Author:  R11happy, xushuai100@126.com
//   Organization:
//
// =====================================================================================
#include "AdminDlg.h"
#include "ui_AdminDlg.h"
#include <QMessageBox>
#include<QSqlDatabase>
#include <QSqlQuery>
#include <QString>


AdminDlg::AdminDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDlg)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("管理员注册"));
    setWindowIcon(QIcon(":/Menu/images/admin.png"));
    connect(ui->admin_ok, SIGNAL(clicked(bool)),this,SLOT(on_btnOK()));
    connect(ui->admin_cancel,SIGNAL(clicked(bool)),this,SLOT(on_btnCancel()));
}

AdminDlg::~AdminDlg()
{
    delete ui;
}


// ===  FUNCTION  ======================================================================
//         Name:  on_btnOK
//  Description:  insert (ID,Password, name) into Table(admin)
// =====================================================================================
void AdminDlg::on_btnOK()
{
    QString ID = ui->admin_id->text();
    QString Password = ui->admin_psw->text();
    QString Name = ui->admin_name->text();
    QSqlQuery Admin_query;
    if(ID.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("账号不能为空"));
        return;
    }
    else if(Password.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("密码不能为空"));
        return;
    }
    else if(Name.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("名称不能为空"));
        return;
    }
    else if(!Admin_query.exec("insert into admin values('"+ID+"','"+Password+"','"+Name+"');"))
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("注册失败"));
        return;
     }
    else
    {
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("注册成功"));
        accept();
    }

}

void AdminDlg::on_btnCancel()
{
    reject();
}

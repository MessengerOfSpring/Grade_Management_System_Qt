// =====================================================================================
//
//       Filename:  UnderDlg.cpp
//
//    Description:  Enroll for Undergraduate
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
#include "UnderDlg.h"
#include "ui_UnderDlg.h"
#include <QMessageBox>
#include<QSqlDatabase>
#include <QSqlQuery>
#include <QString>

UnderDlg::UnderDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UnderDlg)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("本科生注册"));
    setWindowIcon(QIcon(":/Menu/images/under.png"));
    connect(ui->under_ok, SIGNAL(clicked(bool)),this,SLOT(on_btnOK()));
    connect(ui->under_cancel,SIGNAL(clicked(bool)),this,SLOT(on_btnCancel()));
}

UnderDlg::~UnderDlg()
{
    delete ui;
}


// ===  FUNCTION  ======================================================================
//         Name:  on_btnOK
//  Description:  insert (ID,Password, name,'undergraduate') into Table(student)
// =====================================================================================
void UnderDlg::on_btnOK()
{
    QString ID = ui->under_id->text();
    QString Password = ui->under_psw->text();
    QString Name = ui->under_name->text();
    QSqlQuery Under_query;
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
    else if(!Under_query.exec("insert into student values('"+ID+"','"+Password+"','"+Name+"','1');"))
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

void UnderDlg::on_btnCancel()
{
    reject();
}

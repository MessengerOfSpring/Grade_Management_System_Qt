// =====================================================================================
//
//       Filename:  PhdDlg.cpp
//
//    Description:  Enroll for Phd
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
#include "PhdDlg.h"
#include "ui_PhdDlg.h"
#include <QMessageBox>
#include<QSqlDatabase>
#include <QSqlQuery>
#include <QString>
PhdDlg::PhdDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PhdDlg)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("博士生注册"));
    setWindowIcon(QIcon(":/Menu/images/doctor.png"));
    connect(ui->phd_ok, SIGNAL(clicked(bool)),this,SLOT(on_btnOK()));
    connect(ui->phd_cancel,SIGNAL(clicked(bool)),this,SLOT(on_btnCancel()));
}

PhdDlg::~PhdDlg()
{
    delete ui;
}

// ===  FUNCTION  ======================================================================
//         Name:  on_btnOK
//  Description:  insert (ID,Password, name,'Phd') into Table(student)
// =====================================================================================
void PhdDlg::on_btnOK()
{
    QString ID = ui->phd_id->text();
    QString Password = ui->phd_psw->text();
    QString Name = ui->phd_name->text();
    QSqlQuery Phd_query;
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
    else if(!Phd_query.exec("insert into student values('"+ID+"','"+Password+"','"+Name+"','3');"))
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

void PhdDlg::on_btnCancel()
{
    reject();
}

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
    setWindowTitle(QString::fromLocal8Bit("������ע��"));
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
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�˺Ų���Ϊ��"));
        return;
    }
    else if(Password.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("���벻��Ϊ��"));
        return;
    }
    else if(Name.isEmpty())
    {
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("���Ʋ���Ϊ��"));
        return;
    }
    else if(!Under_query.exec("insert into student values('"+ID+"','"+Password+"','"+Name+"','1');"))
    {
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("ע��ʧ��"));
        return;
     }
    else
    {
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("ע��ɹ�"));
        accept();
    }

}

void UnderDlg::on_btnCancel()
{
    reject();
}

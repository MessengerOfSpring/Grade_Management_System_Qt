// =====================================================================================
//
//       Filename:  MasterDlg.cpp
//
//    Description:  Enroll for Master
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
#include "MasterDlg.h"
#include "ui_MasterDlg.h"
#include <QMessageBox>
#include<QSqlDatabase>
#include <QSqlQuery>
#include <QString>

MasterDlg::MasterDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MasterDlg)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("˶ʿ��ע��"));
    setWindowIcon(QIcon(":/Menu/images/post.png"));
    connect(ui->master_ok, SIGNAL(clicked(bool)),this,SLOT(on_btnOK()));
    connect(ui->master_cancel,SIGNAL(clicked(bool)),this,SLOT(on_btnCancel()));
}

MasterDlg::~MasterDlg()
{
    delete ui;
}


// ===  FUNCTION  ======================================================================
//         Name:  on_btnOK
//  Description:  insert (ID,Password, name,'Master') into Table(student)
// =====================================================================================
void MasterDlg::on_btnOK()
{
    QString ID = ui->master_id->text();
    QString Password = ui->master_psw->text();
    QString Name = ui->master_name->text();
    QSqlQuery Master_query;
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
    else if(!Master_query.exec("insert into student values('"+ID+"','"+Password+"','"+Name+"','2');"))
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

void MasterDlg::on_btnCancel()
{
    reject();
}

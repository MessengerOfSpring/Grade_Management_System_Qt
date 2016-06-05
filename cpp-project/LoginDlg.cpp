#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include "LoginDlg.h"
#include "Check.h"
#include "ui_LoginDlg.h"
#include<QSqlDatabase>
#include <QSqlQuery>

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);

    m_Info = new LoginInfo;
    m_Info->ID = "";
    m_Info->Password = "";
    m_Info->Type = UNDERGRADUATE;

    //connect to database
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("grade_manage");
    db.setUserName("root");
    db.setPassword("root");//你的mysql密码可能是空***********
    bool ok=db.open();
    if(ok){
        //QMessageBox::information(NULL,"提示","连接数据库成功");
    }
    else{
        QMessageBox::information(NULL,"提示","连接数据库失败");
        qApp->quit();
    }

    setWindowTitle(tr("登录"));

    // Do not show password
    ui->Password->setEchoMode(QLineEdit::Password);

    ui->under->setChecked(true);
}

LoginDlg::~LoginDlg()
{
    delete ui;
    delete m_Info;
}

void LoginDlg::on_Login_clicked()
{
    QString ErrorMsg;

    // get ID and remove the spaces
    m_Info->ID = ui->ID->text().trimmed();
    // get Password but do not remove the spaces
    m_Info->Password = ui->Password->text();

    // if both ID and password are valid
    if(Check(m_Info->ID, m_Info->Password, m_Info->Type, ErrorMsg))
    {
        accept();
    }
    // if ID or password is not valid
    else
    {
        QMessageBox::warning(this, "警告",ErrorMsg);
        m_Info->ID = "";
        m_Info->Password = "";
        ui->ID->clear();
        ui->Password->clear();
        ui->ID->setFocus();
    }
}

void LoginDlg::on_Quit_clicked()
{
    qApp->quit();
}

void LoginDlg::on_under_clicked()
{
    m_Info->Type = UNDERGRADUATE;
}

void LoginDlg::on_post_clicked()
{
    m_Info->Type = POSTGRADUATE;
}

void LoginDlg::on_doc_clicked()
{
    m_Info->Type = DOCTORAL;
}

void LoginDlg::on_admin_clicked()
{
    m_Info->Type = ADMIN;
}

//--------------------------------------------------------------------------------------
//       Class:  LoginDlg
//      Method:  getInfo
//--------------------------------------------------------------------------------------
LoginInfo& LoginDlg::getInfo() const
{
    return *m_Info;
}		// -----  end of accessor Login::getInfo  -----

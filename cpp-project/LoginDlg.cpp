#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include "LoginDlg.h"
#include "Check.h"
#include "ui_LoginDlg.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

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
    db.setPassword("root");//���mysql��������ǿ�***********
    bool ok=db.open();
    if(ok){
        //QMessageBox::information(NULL,"��ʾ","�������ݿ�ɹ�");
    }
    else{
        QMessageBox::information(NULL,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�������ݿ�ʧ��"));
        qApp->quit();
    }

    setWindowTitle(QString::fromLocal8Bit(" ѧ���ɼ�����ϵͳ"));

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
        QMessageBox::warning(this, QString::fromLocal8Bit("����"),ErrorMsg);
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

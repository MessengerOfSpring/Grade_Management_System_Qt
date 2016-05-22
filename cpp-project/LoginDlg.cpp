#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include "LoginDlg.h"
#include "Check.h"
#include "ui_LoginDlg.h"

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);

    m_Info = new LoginInfo;
    m_Info->ID = "";
    m_Info->Password = "";
    m_Info->Type = STUDENT;

    setWindowTitle(tr("登录"));

    // Do not show password
    ui->Password->setEchoMode(QLineEdit::Password);

    ui->student->setChecked(true);
}

LoginDlg::~LoginDlg()
{
    delete ui;
    delete m_Info;
}

void LoginDlg::on_Login_clicked()
{
    std::string ErrorMsg;

    if(Check(m_Info->ID.toStdString(), m_Info->Password.toStdString(), m_Info->Type, ErrorMsg))
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr(ErrorMsg.c_str()));
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

void LoginDlg::on_ID_textEdited(const QString &arg1)
{
    m_Info->ID = arg1;
}

void LoginDlg::on_Password_textEdited(const QString &arg1)
{
    m_Info->Password = arg1;
}

void LoginDlg::on_student_clicked()
{
    m_Info->Type = STUDENT;
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

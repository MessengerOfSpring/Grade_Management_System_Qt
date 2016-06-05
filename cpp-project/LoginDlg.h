#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
#include <QString>

enum LoginType{UNDERGRADUATE, POSTGRADUATE, DOCTORAL, ADMIN};
struct LoginInfo
{
    QString ID;
    QString Password;
    LoginType Type;
};

namespace Ui {
class LoginDlg;
}

class LoginDlg : public QDialog
{
    Q_OBJECT

private slots:
    void on_Login_clicked();
    void on_Quit_clicked();
    void on_under_clicked();
    void on_post_clicked();
    void on_doc_clicked();
    void on_admin_clicked();

public:
    explicit LoginDlg(QWidget *parent = 0);
    ~LoginDlg();
    LoginInfo& getInfo() const;

private:
    Ui::LoginDlg *ui;
    LoginInfo *m_Info;
};

#endif // LOGINDLG_H

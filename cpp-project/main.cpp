#include "LoginDlg.h"
#include "StudentMainWindow.h"
#include "AdminMainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDlg Login;

    // if login successfully
    if(Login.exec() == QDialog::Accepted)
    {
        LoginInfo Info = Login.getInfo();
        switch(Info.Type)
        {
            // login as a student
            case UNDERGRADUATE:
            case POSTGRADUATE:
            case DOCTORAL:
            {
                StudentMainWindow Student(Info.ID);
                Student.show();

                return a.exec();
            }
            // login as an administrator
            case ADMIN:
            {
                AdminMainWindow Admin(Info.ID);
                Admin.show();

                return a.exec();
            }
        }
    }

    // if push quit
    else
    {
        return 0;
    }
}

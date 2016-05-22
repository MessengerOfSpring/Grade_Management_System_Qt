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
            case STUDENT:
            {
                StudentMainWindow Student(Info.ID, Info.Password);
                Student.show();

                return a.exec();
            }
            // login as an administrator
            case ADMIN:
            {
                AdminMainWindow Admin(Info.ID, Info.Password);
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

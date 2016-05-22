#include "AdminMainWindow.h"
#include "ui_AdminMainWindow.h"

AdminMainWindow::AdminMainWindow(QString ID, QString Password, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("学生成绩管理系统"));
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}

void AdminMainWindow::on_Quit_clicked()
{
    qApp->quit();
}

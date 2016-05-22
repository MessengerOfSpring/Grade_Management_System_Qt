#include "StudentMainWindow.h"
#include "ui_StudentMainWindow.h"

StudentMainWindow::StudentMainWindow(QString ID, QString Password, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentMainWindow)
{
    ui->setupUi(this);
}

StudentMainWindow::~StudentMainWindow()
{
    delete ui;
}

void StudentMainWindow::on_Quit_clicked()
{
    qApp->quit();
}

#include "AddDlg.h"
#include "ui_AddDlg.h"

AddDlg::AddDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDlg)
{
    ui->setupUi(this);
}

AddDlg::~AddDlg()
{
    delete ui;
}

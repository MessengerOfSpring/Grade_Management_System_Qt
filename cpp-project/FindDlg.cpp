#include "FindDlg.h"
#include "ui_FindDlg.h"

FindDlg::FindDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDlg)
{
    ui->setupUi(this);
}

FindDlg::~FindDlg()
{
    delete ui;
}

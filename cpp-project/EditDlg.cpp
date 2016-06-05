#include "EditDlg.h"
#include "ui_EditDlg.h"

EditDlg::EditDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDlg)
{
    ui->setupUi(this);
}

EditDlg::~EditDlg()
{
    delete ui;
}

#include "Administrator.h"
#include "ui_Administrator.h"

Administrator::Administrator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Administrator)
{
    ui->setupUi(this);
}

Administrator::~Administrator()
{
    delete ui;
}
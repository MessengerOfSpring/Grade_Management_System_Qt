#include "AdiminMainWindow.h"
#include "ui_AdiminMainWindow.h"

AdiminMainWindow::AdiminMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdiminMainWindow)
{
    ui->setupUi(this);
}

AdiminMainWindow::~AdiminMainWindow()
{
    delete ui;
}

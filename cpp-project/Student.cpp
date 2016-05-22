#include "Student.h"
#include "ui_Student.h"

Student::Student(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Student)
{
    ui->setupUi(this);
}

Student::~Student()
{
    delete ui;
}

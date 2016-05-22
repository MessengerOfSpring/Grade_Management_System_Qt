#ifndef STUDENT_H
#define STUDENT_H

#include <QMainWindow>

namespace Ui {
class Student;
}

class Student : public QMainWindow
{
    Q_OBJECT

public:
    explicit Student(QWidget *parent = 0);
    ~Student();

private:
    Ui::Student *ui;
};

#endif // STUDENT_H

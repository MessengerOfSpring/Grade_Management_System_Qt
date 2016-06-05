#ifndef STUDENTMAINWINDOW_H
#define STUDENTMAINWINDOW_H

#include "Grade.h"
#include <vector>
#include <QMainWindow>

namespace Ui {
class StudentMainWindow;
}

class StudentMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentMainWindow(QString ID, QWidget *parent = 0);
    ~StudentMainWindow();
    void showGradeInfo();

private slots:
    void on_Quit_clicked();

private:
    Ui::StudentMainWindow *ui;
    Grade *m_Grade;
};

#endif // STUDENTMAINWINDOW_H

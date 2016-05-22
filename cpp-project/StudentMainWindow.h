#ifndef STUDENTMAINWINDOW_H
#define STUDENTMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class StudentMainWindow;
}

class StudentMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StudentMainWindow(QString ID, QString Password, QWidget *parent = 0);
    ~StudentMainWindow();

private slots:
    void on_Quit_clicked();

private:
    Ui::StudentMainWindow *ui;
};

#endif // STUDENTMAINWINDOW_H

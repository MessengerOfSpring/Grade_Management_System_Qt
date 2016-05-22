#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QString ID, QString Password, QWidget *parent = 0);
    ~AdminMainWindow();

private slots:
    void on_Quit_clicked();

private:
    Ui::AdminMainWindow *ui;
};

#endif // ADMINMAINWINDOW_H

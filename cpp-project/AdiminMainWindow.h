#ifndef ADIMINMAINWINDOW_H
#define ADIMINMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class AdiminMainWindow;
}

class AdiminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdiminMainWindow(QWidget *parent = 0);
    ~AdiminMainWindow();

private:
    Ui::AdiminMainWindow *ui;
};

#endif // ADIMINMAINWINDOW_H

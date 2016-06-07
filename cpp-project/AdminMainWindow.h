#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include "Grade.h"
#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <qdialog.h>

namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QString ID, QWidget *parent = 0);
    ~AdminMainWindow();
    void showGradeInfo();

private slots:
    void on_Quit_clicked();
    void on_Find_clicked();
    void on_Add_clicked();
    void contextMenu(const QPoint &Pos);
    void editTuple();
    void deleteTuple();
    void on_Enroll_admin();
    void on_Enroll_under();
    void on_Enroll_master();
    void on_Enroll_phd();
private:
    Ui::AdminMainWindow *ui;
    QMenu *m_ContextMenu;
    QAction *m_DeleteAction;
    QAction *m_EditAction;
    Grade *m_Grade;
};

#endif // ADMINMAINWINDOW_H

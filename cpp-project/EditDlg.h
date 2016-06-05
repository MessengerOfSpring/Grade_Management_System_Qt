#ifndef EDITDLG_H
#define EDITDLG_H

#include "Grade.h"
#include <QDialog>

namespace Ui {
class EditDlg;
}

class EditDlg : public QDialog
{
    Q_OBJECT

public:
    explicit EditDlg(const QString& StudentName, const QString& CourseName, QWidget *parent = 0);
    ~EditDlg();
    unsigned int getNewScore() const;

private slots:
    void on_Ok_clicked();
    void on_Cancel_clicked();

private:
    Ui::EditDlg *ui;
    unsigned int m_NewScore;
};

#endif // EDITDLG_H

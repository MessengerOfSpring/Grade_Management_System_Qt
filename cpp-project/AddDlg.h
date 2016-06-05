#ifndef ADDDLG_H
#define ADDDLG_H

#include "Grade.h"
#include <QDialog>

namespace Ui {
class AddDlg;
}

class AddDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddDlg(QWidget *parent = 0);
    ~AddDlg();
    GradeInfo getGradeInfo() const;

private slots:
    void on_Ok_clicked();
    void on_Cancel_clicked();

private:
    Ui::AddDlg *ui;
    GradeInfo *m_GradeInfo;
};

#endif // ADDDLG_H

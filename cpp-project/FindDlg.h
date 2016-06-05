#ifndef FINDDLG_H
#define FINDDLG_H

#include "Grade.h"
#include <QDialog>

namespace Ui {
class FindDlg;
}

class FindDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FindDlg(QWidget *parent = 0);
    ~FindDlg();
    const Condition& getCondition1() const;
    const Condition& getCondition2() const;
    const ConditionRelation& getConditionRelation() const;

private slots:
    void on_OK_clicked();
    void on_Cancel_clicked();
    void on_And_clicked();
    void on_Or_clicked();

private:
    Ui::FindDlg *ui;
    Condition m_Condition1;
    Condition m_Condition2;
    ConditionRelation m_CRelation;
};

#endif // FINDDLG_H

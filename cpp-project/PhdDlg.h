#ifndef PHDDLG_H
#define PHDDLG_H

#include <QDialog>

namespace Ui {
class PhdDlg;
}

class PhdDlg : public QDialog
{
    Q_OBJECT
private slots:
    void on_btnOK();
    void on_btnCancel();
public:
    explicit PhdDlg(QWidget *parent = 0);
    ~PhdDlg();

private:
    Ui::PhdDlg *ui;
};

#endif // PHDDLG_H

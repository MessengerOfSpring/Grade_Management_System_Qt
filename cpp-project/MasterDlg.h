#ifndef MASTERDLG_H
#define MASTERDLG_H

#include <QDialog>

namespace Ui {
class MasterDlg;
}

class MasterDlg : public QDialog
{
    Q_OBJECT
private slots:
    void on_btnOK();
    void on_btnCancel();
public:
    explicit MasterDlg(QWidget *parent = 0);
    ~MasterDlg();

private:
    Ui::MasterDlg *ui;
};

#endif // MASTERDLG_H

#ifndef UNDERDLG_H
#define UNDERDLG_H

#include <QDialog>

namespace Ui {
class UnderDlg;
}

class UnderDlg : public QDialog
{
    Q_OBJECT
private slots:
    void on_btnOK();
    void on_btnCancel();
public:
    explicit UnderDlg(QWidget *parent = 0);
    ~UnderDlg();

private:
    Ui::UnderDlg *ui;
};

#endif // UNDERDLG_H

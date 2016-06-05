#ifndef ADDDLG_H
#define ADDDLG_H

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

private:
    Ui::AddDlg *ui;
};

#endif // ADDDLG_H

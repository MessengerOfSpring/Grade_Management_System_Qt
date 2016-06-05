#include "Grade.h"
#include "EditDlg.h"
#include "ui_EditDlg.h"
#include <QMessageBox>

EditDlg::EditDlg(const QString& StudentName, const QString& CourseName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDlg)
{
    ui->setupUi(this);
    setWindowTitle("编辑成绩");
    ui->label->setText("请输入" + StudentName + "同学在" + CourseName + "课程中新的成绩:");
    ui->label->adjustSize();
}

EditDlg::~EditDlg()
{
    delete ui;
}

//--------------------------------------------------------------------------------------
//       Class:  EditDlg
//    Accessor:  getNewScore
//--------------------------------------------------------------------------------------
unsigned int EditDlg::getNewScore() const
{
    return m_NewScore;
}		// -----  end of accessor EditDlg::getNewScore  ----- 

void EditDlg::on_Ok_clicked()
{
    bool Ok;
    m_NewScore = ui->NewScore->text().toUInt(&Ok, 10);
    if(!Ok || m_NewScore > 100)
    {
        QMessageBox::warning(this, "警告", "成绩必须为0～100的整数！请重新输入");
        ui->NewScore->clear();
        return;
    }
    else
        accept();
}

void EditDlg::on_Cancel_clicked()
{
    close();
}

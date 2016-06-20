#include "Grade.h"
#include "EditDlg.h"
#include "ui_EditDlg.h"
#include <QMessageBox>
#include <QString>

EditDlg::EditDlg(const QString& StudentName, const QString& CourseName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDlg)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("�༭�ɼ�"));
    ui->label->setText(QString::fromLocal8Bit("������") + StudentName + QString::fromLocal8Bit("ͬѧ��") + CourseName + QString::fromLocal8Bit("�γ����µĳɼ�:"));
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
        QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ɼ�����Ϊ0��100������������������"));
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

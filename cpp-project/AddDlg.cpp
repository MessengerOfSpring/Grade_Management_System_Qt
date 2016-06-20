#include "AddDlg.h"
#include "ui_AddDlg.h"
#include <QMessageBox>
#include <QString>

AddDlg::AddDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDlg)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("��ӳɼ�"));
    m_GradeInfo = new GradeInfo;
}

AddDlg::~AddDlg()
{
    delete ui;
    delete m_GradeInfo;
}

//--------------------------------------------------------------------------------------
//       Class:  AddDlg
//    Accessor:  getGradeInfo
//--------------------------------------------------------------------------------------
GradeInfo AddDlg::getGradeInfo() const
{
	return *m_GradeInfo;
}		// -----  end of accessor AddDlg::getGradeInfo  ----- 

void AddDlg::on_Ok_clicked()
{
    bool Ok;

    m_GradeInfo->StudentID = ui->StudentID->text();
    m_GradeInfo->CourseID  = ui->CourseID->text();
    m_GradeInfo->Score     = ui->Score->text().toUInt(&Ok, 10);
    if(m_GradeInfo->StudentID == "")
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("ѧ��ѧ��Ϊ���"));
        return;
    }
    else if(m_GradeInfo->CourseID  == "")
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�γ̴���Ϊ���"));
        return;
    }
    else if(!Ok || m_GradeInfo->Score > 100)
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ɼ�Ϊ������Ϊ0��100��������"));
        return;
    }

    accept();
}

void AddDlg::on_Cancel_clicked()
{
    close();
}

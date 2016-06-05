#include "AddDlg.h"
#include "ui_AddDlg.h"
#include <QMessageBox>

AddDlg::AddDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDlg)
{
    ui->setupUi(this);
    setWindowTitle("添加成绩");
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
        QMessageBox::warning(this, "警告", "学生学号为必填！");
        return;
    }
    else if(m_GradeInfo->CourseID  == "")
    {
        QMessageBox::warning(this, "警告", "课程代码为必填！");
        return;
    }
    else if(!Ok || m_GradeInfo->Score > 100)
    {
        QMessageBox::warning(this, "警告", "成绩为必填且为0～100的整数！");
        return;
    }

    accept();
}

void AddDlg::on_Cancel_clicked()
{
    close();
}

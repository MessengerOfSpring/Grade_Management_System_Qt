#include "FindDlg.h"
#include "ui_FindDlg.h"

FindDlg::FindDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDlg)
{
    ui->setupUi(this);

    setWindowTitle(QString::fromLocal8Bit("查找成绩"));

    QStringList Fields, FieldRelations;
    Fields << QString::fromLocal8Bit("学号") << QString::fromLocal8Bit("课程名称") << QString::fromLocal8Bit("课程代码");
    FieldRelations <<QString::fromLocal8Bit("等于") << QString::fromLocal8Bit("包含");
    ui->Field1->addItems(Fields);
    ui->Field2->addItems(Fields);
    ui->FieldRelation1->addItems(FieldRelations);
    ui->FieldRelation2->addItems(FieldRelations);

    ui->And->setChecked(true);
    m_CRelation = AND;
}

FindDlg::~FindDlg()
{
    delete ui;
}

//--------------------------------------------------------------------------------------
//       Class:  FindDlg
//    Accessor:  getCondition1
//--------------------------------------------------------------------------------------
const Condition& FindDlg::getCondition1() const
{
    return m_Condition1;
}		// -----  end of accessor FindDlg::getCondition1  ----- 

//--------------------------------------------------------------------------------------
//       Class:  FindDlg
//    Accessor:  getCondition2
//--------------------------------------------------------------------------------------
const Condition& FindDlg::getCondition2() const
{
	return m_Condition2;
}		// -----  end of accessor FindDlg::getCondition2  ----- 

//--------------------------------------------------------------------------------------
//       Class:  FindDlg
//    Accessor:  getConditionRelation
//--------------------------------------------------------------------------------------
const ConditionRelation& FindDlg::getConditionRelation() const
{
	return m_CRelation;
}		// -----  end of accessor FindDlg::getConditionRelation  ----- 

void FindDlg::on_OK_clicked()
{
    // get information of Condition1
    switch(ui->Field1->currentIndex())
    {
        case 0: m_Condition1.Field = STUDENTID; break;
        case 1: m_Condition1.Field = COURSENAME; break;
        case 2: m_Condition1.Field = COURSEID; break;
    }
    switch(ui->FieldRelation1->currentIndex())
    {
        case 0: m_Condition1.Relation = EQUAL; break;
        case 1: m_Condition1.Relation = CONTAIN; break;
    }
    m_Condition1.Key = ui->Key1->text();

    // get information of Condition2
    switch(ui->Field2->currentIndex())
    {
        case 0: m_Condition2.Field = STUDENTID; break;
        case 1: m_Condition2.Field = COURSENAME; break;
        case 2: m_Condition2.Field = COURSEID; break;
    }
    switch(ui->FieldRelation2->currentIndex())
    {
        case 0: m_Condition2.Relation = EQUAL; break;
        case 1: m_Condition2.Relation = CONTAIN; break;
    }
    m_Condition2.Key = ui->Key2->text();

    accept();
}

void FindDlg::on_Cancel_clicked()
{
    close();
}

void FindDlg::on_And_clicked()
{
    m_CRelation = AND;
}

void FindDlg::on_Or_clicked()
{
    m_CRelation = OR;
}

#include <vector>
#include <QDateTime>
#include <QMessageBox>
#include "AdminMainWindow.h"
#include "ui_AdminMainWindow.h"
#include "FindDlg.h"
#include "AddDlg.h"
#include "EditDlg.h"
#include "Grade.h"

AdminMainWindow::AdminMainWindow(QString ID, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("学生成绩管理系统"));

    // set tablewidget
    QStringList Header;
    Header << tr("学号") << tr("姓名") << tr("课程代码") << ("课程名称") << ("成绩");
    ui->tableWidget->setColumnCount(5);         // 5 columns
    ui->tableWidget->setHorizontalHeaderLabels(Header); // set horizontal header labels
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // can't be edited
    ui->tableWidget->verticalHeader()->setVisible(false); // set vertical header invisiable
    ui->tableWidget->horizontalHeader()->setVisible(true); // set horizontal header visiable
    ui->tableWidget->horizontalHeader()->setSectionsClickable(false); // horizontal header can't be clicked
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // set selection only rows

    QString LabelInfo = ID + QString("老师，欢迎来到学生成绩管理系统！今天是") +
            QDate::currentDate().toString("yyyy-MM-dd");
    ui->label->setText(LabelInfo);
    ui->label->adjustSize();

    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    m_ContextMenu = new QMenu(ui->tableWidget);
    m_DeleteAction = new QAction("删除成绩", this);
    m_EditAction = new QAction("编辑成绩", this);
    connect(ui->tableWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenu(QPoint)));
    connect(m_DeleteAction, SIGNAL(triggered()), this, SLOT(deleteTuple()));
    connect(m_EditAction, SIGNAL(triggered()), this, SLOT(editTuple()));

    m_Grade = new Grade;
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
    delete m_ContextMenu;
    delete m_DeleteAction;
    delete m_EditAction;
    delete m_Grade;
}

//--------------------------------------------------------------------------------------
//       Class:  AdminMainWindow
//      Method:  showGradeInfo
// Description:  
//--------------------------------------------------------------------------------------
void AdminMainWindow::showGradeInfo()
{
    // Remove all rows in the table
    for(int Row = ui->tableWidget->rowCount() - 1; Row >= 0; Row --)
        ui->tableWidget->removeRow(0);

    const std::vector<GradeInfo>& Info = m_Grade->getInfo();
    // If the result of query is empty, then show nothing
    if(Info.size() == 0)
    {
        QMessageBox::information(this, "提示", "没有您要查找的成绩！");
        return;
    }

    for(unsigned int Row = 0; Row < Info.size(); Row ++)
    {
        // Insert one row into the table
        ui->tableWidget->insertRow(Row);

        // Insert StudentID into the table
        QTableWidgetItem *StudentID = new QTableWidgetItem(Info[Row].StudentID);
        StudentID->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(Row, 0, StudentID);

        // Insert StudentName into the table
        QTableWidgetItem *StudentName = new QTableWidgetItem(Info[Row].StudentName);
        StudentName->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(Row, 1, StudentName);

        // Insert CourseID into the table
        QTableWidgetItem *CourseID = new QTableWidgetItem(Info[Row].CourseID);
        CourseID->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(Row, 2, CourseID);

        // Insert CourseName into the table
        QTableWidgetItem *CourseName = new QTableWidgetItem(Info[Row].CourseName);
        CourseName->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(Row, 3, CourseName);

        // Insert the Score into the table
        QTableWidgetItem *Score = new QTableWidgetItem(QString("%1").arg(Info[Row].Score));
        Score->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(Row, 4, Score);
    }
}		// -----  end of method AdminMainWindow::showGradeInfo  ----- 

void AdminMainWindow::on_Quit_clicked()
{
    qApp->quit();
}

void AdminMainWindow::on_Find_clicked()
{
    FindDlg find;
    if(find.exec() == QDialog::Accepted)
    {
        const Condition& condition1 = find.getCondition1();
        const Condition& condition2 = find.getCondition2();
        const ConditionRelation& CRelation = find.getConditionRelation();
        QString ErrorMsg;
        if(m_Grade->query(condition1, condition2, CRelation, ErrorMsg))
            showGradeInfo();
        else
            QMessageBox::warning(this, "警告", ErrorMsg);
    }
}

void AdminMainWindow::on_Add_clicked()
{
    AddDlg add;
    if(add.exec() == QDialog::Accepted)
    {
        GradeInfo info = add.getGradeInfo();
        QString ErrorMsg;
        if(!m_Grade->insertGrade(info, ErrorMsg))
            QMessageBox::warning(this, "警告", ErrorMsg);
    }
}

void AdminMainWindow::contextMenu(const QPoint &Pos)
{
    QTableWidgetItem *currentItem = ui->tableWidget->itemAt(Pos);
    if(currentItem == NULL)
        return;
    m_ContextMenu->addAction(m_EditAction);
    m_ContextMenu->addAction(m_DeleteAction);
    m_ContextMenu->exec(QCursor::pos());
}

void AdminMainWindow::editTuple()
{
    int Row = ui->tableWidget->currentRow();
    EditDlg edit(ui->tableWidget->item(Row, 1)->text(), ui->tableWidget->item(Row, 3)->text());
    if(edit.exec() == QDialog::Accepted)
    {
        GradeInfo info;

        info.StudentID   = ui->tableWidget->item(Row, 0)->text();
        info.StudentName = ui->tableWidget->item(Row, 1)->text();
        info.CourseID    = ui->tableWidget->item(Row, 2)->text();
        info.CourseName  = ui->tableWidget->item(Row, 3)->text();
        info.Score       = edit.getNewScore();

        QString ErrorMsg;
        if(m_Grade->updateGrade(info, ErrorMsg)) // Update the information in the database
        {
            QTableWidgetItem *Score = new QTableWidgetItem(QString("%1").arg(info.Score));
            Score->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            ui->tableWidget->setItem(Row, 4, Score);
        }
        else
            QMessageBox::warning(this, "警告", ErrorMsg);
    }
}

void AdminMainWindow::deleteTuple()
{
    QMessageBox::StandardButton rb =
            QMessageBox::warning(this, "警告", "您确定要删除这条成绩吗？删除后将无法撤销！",
                                 QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Cancel);
    // if push "Cancel", then do nothing
    if(rb == QMessageBox::Cancel)
        return;

    GradeInfo info;
    int Row = ui->tableWidget->currentRow();
    bool ok;

    info.StudentID   = ui->tableWidget->item(Row, 0)->text();
    info.StudentName = ui->tableWidget->item(Row, 1)->text();
    info.CourseID    = ui->tableWidget->item(Row, 2)->text();
    info.CourseName  = ui->tableWidget->item(Row, 3)->text();
    info.Score       = ui->tableWidget->item(Row, 4)->text().toInt(&ok, 10);

    QString ErrorMsg;
    if(m_Grade->deleteGrade(info, ErrorMsg)) // Delete from database
        ui->tableWidget->removeRow(Row); // Delete from the table
    else
        QMessageBox::warning(this, "警告", ErrorMsg);
}

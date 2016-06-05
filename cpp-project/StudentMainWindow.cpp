#include <QDateTime>
#include <vector>
#include "Grade.h"
#include "StudentMainWindow.h"
#include "ui_StudentMainWindow.h"

StudentMainWindow::StudentMainWindow(QString ID, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StudentMainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("学生成绩管理系统"));

    // set tablewidget
    QStringList Header;
    Header << tr("课程号") << ("课程名称") << ("成绩");
    ui->tableWidget->setColumnCount(3);         // 3 columns
    ui->tableWidget->setHorizontalHeaderLabels(Header); // set horizontal header labels
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // can't be edited
    ui->tableWidget->verticalHeader()->setVisible(false); // set vertical header invisiable
    ui->tableWidget->horizontalHeader()->setVisible(true); // set horizontal header visiable
    ui->tableWidget->horizontalHeader()->setSectionsClickable(false); // horizontal header can't be clicked
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); // set selection only rows

    QString LabelInfo = ID + QString("同学，欢迎来到学生成绩管理系统！今天是") +
            QDate::currentDate().toString("yyyy-MM-dd");
    ui->label->setText(LabelInfo);
    ui->label->adjustSize();

    m_Grade = new Grade;
    Condition Condition1 = {STUDENTID, EQUAL, ID}, Condition2 = {STUDENTID, EQUAL, ID};
    ConditionRelation CRelation = AND;
    QString ErrorMsg;
    m_Grade->query(Condition1, Condition2, CRelation, ErrorMsg);

    showGradeInfo();
}

StudentMainWindow::~StudentMainWindow()
{
    delete ui;
    delete m_Grade;
}

//--------------------------------------------------------------------------------------
//       Class:  StudentMainWindow
//      Method:  showGradeInfo
// Description:  Show CourseID, CourseName, and Score
//--------------------------------------------------------------------------------------
void StudentMainWindow::showGradeInfo()
{
    // Remove all rows in the table
    for(int Row = ui->tableWidget->rowCount() - 1; Row >= 0; Row --)
        ui->tableWidget->removeRow(0);

    const std::vector<GradeInfo>& Info = m_Grade->getInfo();
    for(unsigned int Row = 0; Row < Info.size(); Row ++)
    {
        // Insert one row into the table
        ui->tableWidget->insertRow(Row);

        // Insert CourseID into the table
        QTableWidgetItem *CourseID = new QTableWidgetItem(Info[Row].CourseID);
        CourseID->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(Row, 0, CourseID);

        // Insert CourseName into the table
        QTableWidgetItem *CourseName = new QTableWidgetItem(Info[Row].CourseName);
        CourseName->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(Row, 1, CourseName);

        // Insert the Score into the table
        QTableWidgetItem *Score = new QTableWidgetItem(QString("%1").arg(Info[Row].Score));
        Score->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidget->setItem(Row, 2, Score);
    }
}		// -----  end of method StudentMainWindow::showGradeInfo  ----- 

void StudentMainWindow::on_Quit_clicked()
{
    qApp->quit();
}

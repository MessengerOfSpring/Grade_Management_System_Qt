#include <QDateTime>
#include "StudentMainWindow.h"
#include "ui_StudentMainWindow.h"

StudentMainWindow::StudentMainWindow(QString ID, QString Password, QWidget *parent) :
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

    QString LabelInfo = ID + QString("，欢迎来到学生成绩管理系统！今天是") +
            QDate::currentDate().toString(Qt::LocalDate);
    ui->label->setText(LabelInfo);
    ui->label->adjustSize();
}

StudentMainWindow::~StudentMainWindow()
{
    delete ui;
}

void StudentMainWindow::on_Quit_clicked()
{
    qApp->quit();
}

// =====================================================================================
//
//       Filename:  Grade.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  03/06/2016 12:12
//       Revision:  none
//       Compiler:  g++
//
//         Author:  TCX4C70, bu2_int
//   Organization:  
//
// =====================================================================================

#include "Grade.h"
#include <vector>
#include <QSqlQuery>
#include <QMessageBox>
#include <QVariant>
#include <QString>
using namespace std;

//--------------------------------------------------------------------------------------
//       Class:  Grade
//      Method:  Grade
// Description:  constructor
//--------------------------------------------------------------------------------------
Grade::Grade()
{
}  // -----  end of method Grade::Grade(constructor)  ----- 


//--------------------------------------------------------------------------------------
//       Class:  Grade
//      Method:  ~Grade
// Description:  destructor
//--------------------------------------------------------------------------------------
Grade::~Grade ()
{
}  // -----  end of method Grade::~Grade(destructor)  ----- 

//--------------------------------------------------------------------------------------
//       Class:  Grade
//    Accessor:  getInfo
//--------------------------------------------------------------------------------------
const vector<GradeInfo>& Grade::getInfo() const
{
    return m_Info;
}		// -----  end of accessor Grade::getInfo  ----- 

//--------------------------------------------------------------------------------------
//       Class:  Grade
//      Method:  query
// Description:  query grade from database
//               Condition: Field: STUDENTID, COURSENAME, COURSEID -- which field to query
//                          FieldRelation: EQUAL or CONTAIN -- Field = Key or Field like %Key%
//                          Key -- the query key
//               ConditionRelation: AND or OR -- the relationship of Condition1 and Condition2
//--------------------------------------------------------------------------------------
bool Grade::query(const Condition& Condition1, const Condition& Condition2,
                  const ConditionRelation& Relation, QString& ErrorMsg)
{
    QSqlQuery Grade_query;
    // if GradeInfo is not empty, then clean it
    if(m_Info.size() != 0)
        vector<GradeInfo>().swap(m_Info);

    // if both conditions are empty
    if(Condition1.Key == "" && Condition2.Key == "")
    {
        return true;
    }
    // if just one of the conditions is empty
    else if(Condition1.Key != "" && Condition2.Key == "")
    {
        switch(Condition1.Field)
        {
        case STUDENTID:
        {
            if(Condition1.Relation==EQUAL){
                Grade_query.exec("select * from grade natural join course natural join student where s_id = '"+ Condition1.Key + "';");
            }
            else if(Condition1.Relation==CONTAIN){
                Grade_query.exec("select * from grade natural join course natural join student where s_id like '%"+Condition1.Key+"%';");
            }
        }
            break;

        case COURSENAME:
        {
            QSqlQuery Grade_query;
            if(Condition1.Relation==EQUAL){
                Grade_query.exec("select * from grade natural join course natural join student where course_name = '"+ Condition1.Key + "';");
            }
            else if(Condition1.Relation==CONTAIN){
                Grade_query.exec("select * from grade natural join course natural join student where course_name like '%"+Condition1.Key+"%';");
            }
        }
            break;

        case COURSEID:
        {
            if(Condition1.Relation==EQUAL){
                Grade_query.exec("select * from grade natural join course natural join student where course_id = '"+ Condition1.Key + "';");
            }
            else if(Condition1.Relation==CONTAIN){
                Grade_query.exec("select * from grade natural join course natural join student where course_id like '%"+Condition1.Key+"%';");
            }
        }
            break;
        }

        while(Grade_query.next()){
            GradeInfo  Info1;
            Info1.StudentID=Grade_query.value("s_id").toString();
            Info1.StudentName=Grade_query.value("s_name").toString();
            Info1.CourseID=Grade_query.value("course_id").toString();
            Info1.CourseName=Grade_query.value("course_name").toString();
            Info1.Score=(unsigned int)Grade_query.value("grade").toInt();
            m_Info.push_back(Info1);
        }
    }
    else if(Condition1.Key == "" && Condition2.Key != "")
    {
        QMessageBox::information(NULL,"warning","请先将条件填至第一条信息栏！");//偷懒^_^
    }
    // if both conditions are not empty
    else
    {
        QString c1,c2,r11,r12,r21,r22,cr;
        switch(Condition1.Field){
        case STUDENTID:c1="s_id";break;
        case COURSENAME:c1="course_name";break;
        case COURSEID:c1="course_id";break;
        }
        switch(Condition2.Field){
        case STUDENTID:c2="s_id";break;
        case COURSENAME:c2="course_name";break;
        case COURSEID:c2="course_id";break;
        }
        switch(Condition1.Relation){
        case EQUAL:r11=" = '";r12="'";break;
        case CONTAIN:r11=" like '%";r12="%'";break;
        }
        switch(Condition2.Relation){
        case EQUAL:r21=" = '";r22="'";break;
        case CONTAIN:r21=" like '%";r22="%'";break;
        }
        switch(Relation){
        case AND:cr=" and ";break;
        case OR:cr=" or ";break;
        }
        QString ss="select * from grade natural join course natural join student where "+c1+r11+Condition1.Key+r12+cr+c2+r21+Condition2.Key+r22+";";
        Grade_query.exec(ss);

        while(Grade_query.next()){
            GradeInfo  Info1;
            Info1.StudentID=Grade_query.value("s_id").toString();
            Info1.StudentName=Grade_query.value("s_name").toString();
            Info1.CourseID=Grade_query.value("course_id").toString();
            Info1.CourseName=Grade_query.value("course_name").toString();
            Info1.Score=(unsigned int)Grade_query.value("grade").toInt();
            m_Info.push_back(Info1);
        }
        return true;
    }
}		// -----  end of method Grade::query  ----- 

//--------------------------------------------------------------------------------------
//       Class:  Grade
//      Method:  deleteGrade
// Description:  delete the information of grade from database
//--------------------------------------------------------------------------------------
bool Grade::deleteGrade(const GradeInfo& Info, QString& ErrorMsg)
{
    QSqlQuery Grade_query;
    //Grade_query.exec("delete from grade natural join course natural join student where course_name = '"+ Condition1.Key + "';");
    Grade_query.exec("delete from grade where s_id = '"+Info.StudentID+"' and course_id = '"+Info.CourseID+"';");

    return true;
}		// -----  end of method Grade::deleteGrade  ----- 

//--------------------------------------------------------------------------------------
//       Class:  Grade
//      Method:  updateGrade
// Description:  update the information(only score) of grade in the database
//--------------------------------------------------------------------------------------
bool Grade::updateGrade(const GradeInfo& Info, QString& ErrorMsg)
{
    QString sc=QString::number(Info.Score,10);
    QSqlQuery Grade_query;
    //Grade_query.exec("delete from grade natural join course natural join student where course_name = '"+ Condition1.Key + "';");
    Grade_query.exec("update grade set grade = "+sc+" where s_id = '"+Info.StudentID+"' and course_id = '"+Info.CourseID+"';");

    return true;
}		// -----  end of method Grade::updateGrade  ----- 

//--------------------------------------------------------------------------------------
//       Class:  Grade
//      Method:  insertGrade
// Description:  insert GradeInfo(only contain StudentID, CourseID, Score) into the database
//--------------------------------------------------------------------------------------
bool Grade::insertGrade(const GradeInfo& Info, QString& ErrorMsg)
{
    QSqlQuery Insert_query;
    QString sc=QString::number(Info.Score,10);
    bool ok=Insert_query.exec("insert into grade values ('"+Info.StudentID+"','"+Info.CourseID+"',"+sc+");");

    if(ok){
        QMessageBox::information(NULL,"hint","insert successfully");
    }
    else {
        QMessageBox::information(NULL,"hint","insert failed");
    }
    return true;
}		// -----  end of method Grade::insertGrade  ----- 


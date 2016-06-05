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
//         Author:  TCX4C70, tcx4c70@zju.edu.cn
//   Organization:  
//
// =====================================================================================

#include "Grade.h"
#include <vector>
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
    // if GradeInfo is not empty, then clean it
    if(m_Info.size() != 0)
        vector<GradeInfo>().swap(m_Info);

    // if both conditions are empty
    if(Condition1.Key == "" && Condition2.Key == "")
    {
        return true;
    }
    // if just one of the conditions is empty
    else if(Condition1.Key == "" || Condition2.Key == "")
    {
    }
    // if both conditions are not empty
    else
    {
        // those are just for test, which should be deleted after completing
        GradeInfo Info1, Info2;
        Info1.StudentID = TEST_STUDENTID;
        Info1.StudentName = TEST_STUDENTNAME;
        Info1.CourseID = QString(TEST_COURSEID) + "1";
        Info1.CourseName = QString(TEST_COURSENAME) + "1";
        Info1.Score = TEST_SCORE;
        Info2.StudentID = TEST_STUDENTID;
        Info2.StudentName = TEST_STUDENTNAME;
        Info2.CourseID = QString(TEST_COURSEID) + "2";
        Info2.CourseName = QString(TEST_COURSENAME) + "2";
        Info2.Score = TEST_SCORE;
        m_Info.push_back(Info1);
        m_Info.push_back(Info2);
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
    return true;
}		// -----  end of method Grade::deleteGrade  ----- 

//--------------------------------------------------------------------------------------
//       Class:  Grade
//      Method:  updateGrade
// Description:  update the information(only score) of grade in the database
//--------------------------------------------------------------------------------------
bool Grade::updateGrade(const GradeInfo& Info, QString& ErrorMsg)
{
    return true;
}		// -----  end of method Grade::updateGrade  ----- 

//--------------------------------------------------------------------------------------
//       Class:  Grade
//      Method:  insertGrade
// Description:  insert GradeInfo(only contain StudentID, CourseID, Score) into the database
//--------------------------------------------------------------------------------------
bool Grade::insertGrade(const GradeInfo& Info, QString& ErrorMsg)
{
    return true;
}		// -----  end of method Grade::insertGrade  ----- 


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
vector<Grade>& Grade::getInfo() const
{
	return m_Info;
}		// -----  end of accessor Grade::getInfo  ----- 

//--------------------------------------------------------------------------------------
//       Class:  Grade
//      Method:  query
// Description:  
//--------------------------------------------------------------------------------------
void Grade::query(const QString& Key, const QueryField Field)
{
    if(m_Info.size() != 0)
        vector<GradeInfo>().swap(m_Info);
    switch(Field)
    {
        case STUDENTID : queryStudentID(Key) ; break;
        case COURSEID  : queryCourseID(Key)  ; break;
        case COURSENAME: queryCourseName(Key); break;
    }
}		// -----  end of method Grade::query  ----- 

//--------------------------------------------------------------------------------------
//       Class:  Grade
//      Method:  queryStudentID
// Description:  
//--------------------------------------------------------------------------------------
void Grade::queryStudentID(const QString& StudentID)
{
    GradeInfo Info;
    Info.StudentID = TEST_STUDENTID;
    Info.StudentName = TEST_STUDENTNAME;
    Info.CourseID = TEST_COURSEID;
    Info.CourseName = TEST_COURSENAME;
    Info.Score = TEST_SCORE;
    m_Info.push_back(Info);
}		// -----  end of method Grade::queryStudentID  ----- 

//--------------------------------------------------------------------------------------
//       Class:  Grade
//      Method:  queryCourseID
// Description:  
//--------------------------------------------------------------------------------------
void Grade::queryCourseID(const QString& CourseID)
{
}		// -----  end of method Grade::queryCourseID  ----- 

//--------------------------------------------------------------------------------------
//       Class:  Grade
//      Method:  queryCourseName
// Description:  
//--------------------------------------------------------------------------------------
void Grade::queryCourseName(const QString& CourseName)
{
}		// -----  end of method Grade::queryCourseName  ----- 


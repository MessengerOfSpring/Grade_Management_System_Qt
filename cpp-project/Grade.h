/*
 * =====================================================================================
 *
 *       Filename:  Grade.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/06/2016 12:12
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  TCX4C70, tcx4c70@zju.edu.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __GRADE_H__
#define __GRADE_H__

#include <vector>

// Those definitions are just for testing
#define TEST_STUDENTID "s001"
#define TEST_STUDENTNAME "teststudent"
#define TEST_COURSEID "c001"
#define TEST_COURSENAME "testcourse"
#define TEST_SCORE 90

struct GradeInfo 
{
    QString StudentID;
    QString StudentName;
    QString CourseID;
    QString CourseName;
    unsigned int Score;
};				/* ----------  end of struct GradeInfo  ---------- */

enum QueryField 
{
    STUDENTID,
    COURSEID,
    COURSENAME
};				/* ----------  end of enum QueryField  ---------- */

/*
 * =====================================================================================
 *        Class:  Grade
 *  Description:  
 * =====================================================================================
 */
class Grade
{
public:
    /* ====================  LIFECYCLE     ======================================= */
    Grade();                             /* constructor      */
    ~Grade();                            /* destructor       */

	/* ====================  ACCESSORS     ======================================= */
    std::vector<GradeInfo>& getInfo() const;

	/* ====================  MUTATORS      ======================================= */

	/* ====================  METHODS       ======================================= */
    void query(const QString& Key, const QueryField Field = STUDENTID);

private:
	/* ====================  METHODS       ======================================= */
    void queryStudentID(const QString& StudentID);
    void queryCourseID(const QString& CourseID);
    void queryCourseName(const QString& CourseName);

	/* ====================  DATA MEMBERS  ======================================= */
    std::vector<GradeInfo> m_Info;

}; /* -----  end of class Grade  ----- */

#endif


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
#include <QString>

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
    COURSENAME,
    COURSEID
};				/* ----------  end of enum QueryField  ---------- */

enum FieldRelation 
{
    EQUAL,
    CONTAIN
};				/* ----------  end of enum FieldRelation  ---------- */

struct Condition 
{
    QueryField Field;
    FieldRelation Relation;
    QString Key;
};				/* ----------  end of struct Condition  ---------- */

enum ConditionRelation 
{
    AND,
    OR
};				/* ----------  end of enum ConditionRelation  ---------- */

typedef enum ConditionRelation ConditionRelation;
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
    const std::vector<GradeInfo>& getInfo() const;

	/* ====================  MUTATORS      ======================================= */

	/* ====================  METHODS       ======================================= */
    bool query(const Condition& Condition1, const Condition& Condition2,
            const ConditionRelation& Relation, QString& ErrorMsg);
    bool deleteGrade(const GradeInfo& Info, QString& ErrorMsg);
    bool updateGrade(const GradeInfo& Info, QString& ErrorMsg);
    bool insertGrade(const GradeInfo& Info, QString& ErrorMsg);

private:
	/* ====================  DATA MEMBERS  ======================================= */
    std::vector<GradeInfo> m_Info;

}; /* -----  end of class Grade  ----- */

#endif


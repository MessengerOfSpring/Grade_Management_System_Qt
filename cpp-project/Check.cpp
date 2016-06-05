// =====================================================================================
//
//       Filename:  Check.cpp
//
//    Description:  Check ID and password
//
//        Version:  1.0
//        Created:  22/05/2016 09:58
//       Revision:  none
//       Compiler:  g++
//
//         Author:  TCX4C70, tcx4c70@zju.edu.cn
//   Organization:  
//
// =====================================================================================

#include <string>
#include "Check.h"
#include<QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QString>

// ===  FUNCTION  ======================================================================
//         Name:  Check
//  Description:  Check ID and password
// =====================================================================================
bool Check(const QString& ID, const QString& Password, const LoginType Type, QString& ErrorMsg)
{
    switch(Type)
    {
        case UNDERGRADUATE:
        {
            QSqlQuery query1;
            query1.exec("select s_id from student where s_id = '"+ID+"' and psw = '"
                        +Password+"' and s_degree = 'undergraduate'");
            if(!query1.next()){
                ErrorMsg="用户名或密码错误";
                return false;
            }
            else
                return true;
        } break;
        case POSTGRADUATE:
        {
            QSqlQuery query1;
            query1.exec("select s_id from student where s_id = '"+ID+"' and psw = '"
                        +Password+"' and s_degree = 'master'");
            if(!query1.next()){
                ErrorMsg="用户名或密码错误";
                return false;
            }
            else
                return true;
        } break;
        case DOCTORAL:
        {
            QSqlQuery query1;
            query1.exec("select s_id from student where s_id = '"+ID+"' and psw = '"
                        +Password+"' and s_degree = 'phd'");
            if(!query1.next()){
                ErrorMsg="用户名或密码错误";
                return false;
            }
            else
                return true;
        } break;
        case ADMIN:
        {
            QSqlQuery query1;
            query1.exec("select admin_id from admin where admin_id = '"+ID+"' and psw = '"+Password+"'");
            if(!query1.next()){
                ErrorMsg="用户名或密码错误";
                return false;
            }
            else
                return true;
        } break;
        default:
        {
            ErrorMsg = "请选择登录类型！";
            return false;
        } break;
    }
}		// -----  end of function Check  -----

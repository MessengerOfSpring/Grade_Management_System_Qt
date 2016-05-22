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
using namespace std;


// ===  FUNCTION  ======================================================================
//         Name:  Check
//  Description:  Check ID and password
// =====================================================================================
bool Check(const string ID, const string Password, const LoginType Type, string& ErrorMsg)
{
    switch(Type)
    {
        case STUDENT:
        {
            if(ID != VALID_STU_ID)
            {
                ErrorMsg = "用户名不存在！";
                return false;
            }
            else if(Password != VALID_STU_PASSWORD)
            {
                ErrorMsg = "密码错误！";
                return false;
            }
            else
                return true;
        } break;
        case ADMIN:
        {
            if(ID != VALID_ADMIN_ID)
            {
                ErrorMsg = "用户名不存在！";
                return false;
            }
            else if(Password != VALID_ADMIN_PASSWORD)
            {
                ErrorMsg = "密码错误！";
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

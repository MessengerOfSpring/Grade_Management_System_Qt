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
bool Check(const string ID, const string Password, const LoginType Type)
{
    switch(Type)
    {
        case STUDENT:
        {
            if(ID != VALID_STU_ID)
                throw runtime_error("用户不存在！");
            else if(Password != VALID_STU_PASSWORD)
                throw runtime_error("密码错误！");
            else
                return true;
        } break;
        case ADMIN:
        {
            if(ID != VALID_ADMIN_ID)
                throw runtime_error("用户不存在！");
            else if(Password != VALID_ADMIN_PASSWORD)
                throw runtime_error("密码错误！");
            else
                return true;
        } break;
        default:
        {
            throw runtime_error("请选择登录类型！");
        } break;
    }
}		// -----  end of function Check  -----

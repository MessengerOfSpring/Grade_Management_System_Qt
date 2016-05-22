/*
 * =====================================================================================
 *
 *       Filename:  Check.h
 *
 *    Description:  Check ID and password
 *
 *        Version:  1.0
 *        Created:  22/05/2016 09:58
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  TCX4C70, tcx4c70@zju.edu.cn
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __CHECK_H__
#define __CHECK_H__

#include <string>
#include "Login.h"

// Those definitions are just for testing
#define VALID_STU_ID         "123456"
#define VALID_STU_PASSWORD   "654321"
#define VALID_ADMIN_ID       "12345678"
#define VALID_ADMIN_PASSWORD "87654321"

bool Check(const std::string ID, const std::string Password， const LoginType Type);

#endif


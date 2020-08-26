//
// Created by Ezra on 8/11/2020.
//

#ifndef __ENCRYPTION__
#define __ENCRYPTION__

#include "aes_defs.h"
#include <string>
#include"commonfunc.h"
#include<sstream>

std::stringstream encryption(std::istream &raw_msg, std::string key);

#endif //__ENCRYPTION__
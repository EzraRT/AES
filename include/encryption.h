#ifndef __ENCRYPTION__
#define __ENCRYPTION__

#include "aes_defs.h"
#include <string>

std::string encryption(std::string raw_msg, std::string key);

#endif //__ENCRYPTION__
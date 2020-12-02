//
// Created by Ezra on 8/11/2020.
//

#ifndef __DECRYPTION__
#define __DECRYPTION__

#include "aes_defs.h"
#include <string>
#include <sstream>

std::stringstream decryption(std::ifstream &raw_msg, std::string key);

#endif //__DECRYPTION__
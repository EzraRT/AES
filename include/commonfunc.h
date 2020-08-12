//
// Created by szc26 on 8/11/2020.
//

#ifndef EASY_AES_COMMONFUNC_H
#define EASY_AES_COMMONFUNC_H

extern unsigned char w[100][4][4];

unsigned char FFmul(unsigned char a, unsigned char b);

void AddRoundKey(unsigned char state[][4], unsigned char k[][4]);

#endif //EASY_AES_COMMONFUNC_H

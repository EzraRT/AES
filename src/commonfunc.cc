//
// Created by Ezra on 8/11/2020.
//

#include"commonfunc.h"

unsigned char w[100][4][4];

unsigned char FFmul(unsigned char a, unsigned char b) {
    unsigned char bw[4];
    unsigned char res = 0;
    int i;
    bw[0] = b;
    for (i = 1; i < 4; i++) {
        bw[i] = bw[i - 1] << 1;
        if (bw[i - 1] & 0x80) {
            bw[i] ^= 0x1b;
        }
    }
    for (i = 0; i < 4; i++) {
        if ((a >> i) & 0x01) {
            res ^= bw[i];
        }
    }
    return res;
}

void AddRoundKey(unsigned char state[][4], unsigned char k[][4]) {
    int r, c;
    for (c = 0; c < 4; c++) {
        for (r = 0; r < 4; r++) {
            state[r][c] ^= k[r][c];
        }
    }
}

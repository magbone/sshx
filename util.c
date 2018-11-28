//
//  util.c
//  sshx
//
//  Created by 徐鸿宇 on 2018/11/23.
//  Copyright © 2018 magbone. All rights reserved.
//

#include "util.h"

unsigned char ssh_hex_to_dec_1(char ch)
{
    if(ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    if(ch >= 'A' && ch <='F')
    {
        return ch - 'A' + 10;
    }
    if(ch >= 'a' && ch <= 'f')
    {
        return ch - 'a' + 10;
    }
    return -1;
}

unsigned char* ssh_hex_to_dec(char *src,size_t len)
{
    unsigned char dec[len / 2];
    memset(dec, 0, len / 2);
    int j = 0;
    for (int i = 0; i < len - 1; i+=2,j++) {
        dec[j] = ssh_hex_to_dec_1(src[i]) * 16 + ssh_hex_to_dec_1(src[i+1]);
    }
    unsigned char *dec_ptr = dec;
    return dec_ptr;
}

int ssh_random_16(u_int8_t *src)
{
    int result = 0;
    u_int8_t i,n;
    src = (u_int8_t *)malloc(sizeof(char) * 16);
    if (!src)
        return ERROR;
    srand((unsigned)time(NULL));
    for (i = n = 0; i < 16; ) {
        if (n == 0) {
            result = rand();
            n = 3;
        }
        src[i++] = result & 15;
        result >>= 4;
        --n;
    }
    return OK;
}


//
//  util.c
//  sshx
//
//  Created by 徐鸿宇 on 2018/11/23.
//  Copyright © 2018 magbone. All rights reserved.
//

#include "util.h"

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

char *sshx_uint8_to_charp(u_int8_t t)
{
    char *c = malloc(sizeof(char) * 8);
    sprintf(c,"%d" ,t);
    return c;
}

char *sshx_uint32_to_charp(u_int32_t t)
{
    char *c = malloc(sizeof(char) * 32);
    sprintf(c, "%d",t);
    return c;
}


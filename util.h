//
//  util.h
//  sshx
//
//  Created by 徐鸿宇 on 2018/11/23.
//  Copyright © 2018 magbone. All rights reserved.
//

#ifndef util_h
#define util_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "sshx.h"

#define MAX_RANDOM 281474976710656

int sshx_random_16(u_int8_t *);
char *sshx_uint8_to_charp(u_int8_t);
char *sshx_uint32_to_charp(u_int8_t);

#endif /* util_h */

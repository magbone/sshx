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

#include "protocols.h"

#define MAX_RANDOM 281474976710656

unsigned char * ssh_hex_to_dec(char *,size_t len);
unsigned char ssh_hex_to_dec_1(char);
int ssh_random_16(uint8_t *);
int ssh_packet(void*);

#endif /* util_h */

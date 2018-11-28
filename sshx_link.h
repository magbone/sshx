//
//  sshx_link.h
//  sshx
//
//  Created by 徐鸿宇 on 2018/11/28.
//  Copyright © 2018 magbone. All rights reserved.
//

#ifndef sshx_link_h
#define sshx_link_h

#include <stdio.h>
#include "sshx.h"
#define INIT_SIZE 1024 //init size
#define INCREATEMENT 10 //increatment size

typedef struct
{
    char *data; //data
    int size; //data size
}sshx_link;

int sshx_link_init(sshx_link *);
int sshx_link_add(sshx_link *,char *d);
int sshx_link_len(sshx_link);
#endif /* sshx_link_h */

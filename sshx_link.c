//
//  sshx_link.c
//  sshx
//
//  Created by 徐鸿宇 on 2018/11/28.
//  Copyright © 2018 magbone. All rights reserved.
//

#include "sshx_link.h"

int sshx_link_init(sshx_link *s)
{
    if (!s) {
        printf("link init must null\n");
        return ERROR;
    }
    
    s->data = (char *)malloc(sizeof(char) * INIT_SIZE);
    if (! (s->data)) {
        printf("link init failde\n");
        return FAIL;
    }
    s->size = INIT_SIZE;
    return OK;
}

int sshx_link_add(sshx_link *s)
{
    if (sshx_link_len(*s) + 1 > s->size) {
        s->data = ralloc(sizeof(char) * (s->size + INCREATEMENT));
    }
    if (!(s->data)) {
        printf("link ralloc failed\n");
        return FAIL;
    }
    return OK;
}

int sshx_link_len(sshx_link s)
{
    int i;
    for (i = 0; s.data[i++] != '\0';);
    return i;
}

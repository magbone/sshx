//
//  sshx_transport_protocols.h
//  sshx
//
//  Created by 徐鸿宇 on 2018/11/28.
//  Copyright © 2018 magbone. All rights reserved.
//

#ifndef sshx_transport_protocols_h
#define sshx_transport_protocols_h

#include <stdio.h>
#include "sshx.h"
#include "util.h"
#include "sshx_link.h"

#define CLIENT_HELLO "SSH-2.0-sshx_1.0\n"

typedef struct
{
    u_int32_t  packet_len;
    u_int8_t padding;
    
}sshx_packet_head;

typedef struct{
    u_int32_t len;
    char* content;
}sshx_name_list;

typedef struct
{
    char *hello;
}sshx_client_hello;

// Key Exchange init protocol
typedef struct
{
    /* Packet head */
    sshx_packet_head head;
    /* Algorithms */
    u_int8_t message_code; //Key Exchange init(20), set 20
    u_int8_t* cookie; //cookie (random bytes)
    sshx_name_list hex_algorithms;
    sshx_name_list server_host_algorithms;
    sshx_name_list encryption_algorithms_client_to_server;
    sshx_name_list encryption_algorithms_server_to_client;
    sshx_name_list mac_algorithms_client_to_server;
    sshx_name_list mac_algotithms_server_to_client;
    sshx_name_list compression_algorithms_client_to_server;
    sshx_name_list compression_algotithms_server_to_client;
    sshx_name_list languages_client_to_server;
    sshx_name_list languages_server_to_client;
    u_int8_t first_hex_packet_follows;
    u_int32_t reserve; //0 (reserved for future extension)
    /* Padding String */
    char* padding;
    
}sshx_key_exchange_init;

int create_client_hello(sshx_client_hello *);

int create_key_exchange_init(sshx_key_exchange_init *);

int create_key_exchange_init_packet(sshx_key_exchange_init,char*);
#endif /* sshx_transport_protocols_h */

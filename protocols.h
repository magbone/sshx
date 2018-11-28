//
//  protocols.h
//  sshx
//
//  Created by 徐鸿宇 on 2018/11/26.
//  Copyright © 2018 magbone. All rights reserved.
//

#ifndef protocols_h
#define protocols_h

#include <stdio.h>
#include "sshx.h"

#define CLIENT_HELLO "SSH-2.0-sshx_1.0\n"

typedef struct
{
    u_int32_t  packet_len;
    u_int8_t padding;

}PacketHead;

typedef struct{
    u_int32_t len;
    char* content;
}NameList;

typedef struct
{
    char *hello;
}ClientHello;

// Key Exchange init protocol
typedef struct
{
    /* Packet head */
    PacketHead head;
    /* Algorithms */
    u_int8_t message_code; //Key Exchange init(20), set 20
    u_int8_t* cookie; //cookie (random bytes)
    NameList hex_algorithms;
    NameList server_host_algorithms;
    NameList encryption_algorithms_client_to_server;
    NameList encryption_algorithms_server_to_client;
    NameList mac_algorithms_client_to_server;
    NameList mac_algotithms_server_to_client;
    NameList compression_algorithms_client_to_server;
    NameList compression_algotithms_server_to_client;
    NameList languages_client_to_server;
    NameList languages_server_to_client;
    u_int8_t first_hex_packet_follows;
    u_int32_t reserve; //0 (reserved for future extension)
    /* Padding String */
    char* padding;
    
}KeyExchangeInit;

int create_ClientHello(ClientHello *);
int create_KeyExchangeInit_packet(KeyExchangeInit *);





#endif /* protocols_h */

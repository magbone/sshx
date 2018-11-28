//
//  protocols.c
//  sshx
//
//  Created by 徐鸿宇 on 2018/11/26.
//  Copyright © 2018 magbone. All rights reserved.
//

#include "protocols.h"
#include "util.h"

int create_ClientHello(ClientHello *C)
{
    ClientHello c;
    c.hello = CLIENT_HELLO;
    *C = c;
    return OK;
}

int create_KeyExchangeInit_packet(KeyExchangeInit *K)
{
    KeyExchangeInit k;
    /* message code */
    k.message_code = 20;
    /* cookie */
    u_int8_t * cookie = malloc(sizeof(u_int8_t) * 16);
    if (!cookie)
        return ERROR;
    int len = ssh_random_16(cookie);
    if (len == ERROR) {
        return ERROR;
    }
    k.cookie = cookie;
    /* hex_algorithms */
    NameList hex_algorithms;
    //We set defualt
    hex_algorithms.content = "curve25519-sha256@libssh.org,ecdh-sha2-nistp256,ecdh-sha2-nistp384,ecdh-sha2-nistp521,diffie-hellman-group-exchange-sha256,diffie-hellman-group-exchange-sha1,diffie-hellman-group14-sha1,rsa2048-sha256,rsa1024-sha1,diffie-hellman-group1-sha1";
    hex_algorithms.len = 240;
    k.hex_algorithms = hex_algorithms;
    /* server_host_key_algorithms */
    NameList server_host_key_algotithms;
    //We set defualt
    //TODO
    server_host_key_algotithms.content = "ssh-ed25519,ecdsa-sha2-nistp256,ecdsa-sha2-nistp384,ecdsa-sha2-nistp521,ssh-rsa,ssh-dss";
    server_host_key_algotithms.len = 87;
    k.server_host_algorithms = server_host_key_algotithms;
    /* encryption_algorithms_client_to_server */
    NameList encryption_algorithms_client_to_server;
    encryption_algorithms_client_to_server.content = "aes256-ctr,aes256-cbc,rijndael-cbc@lysator.liu.se,aes192-ctr,aes192-cbc,aes128-ctr,aes128-cbc,chacha20-poly1305@openssh.com,blowfish-ctr,blowfish-cbc,3des-ctr,3des-cbc,arcfour256,arcfour128";
    encryption_algorithms_client_to_server.len = 189;
    k.encryption_algorithms_client_to_server = encryption_algorithms_client_to_server;
    /* encryption_algorithms_server_to_client */
    NameList encryption_algorithms_server_to_client;
    encryption_algorithms_server_to_client.content = "aes256-ctr,aes256-cbc,rijndael-cbc@lysator.liu.se,aes192-ctr,aes192-cbc,aes128-ctr,aes128-cbc,chacha20-poly1305@openssh.com,blowfish-ctr,blowfish-cbc,3des-ctr,3des-cbc,arcfour256,arcfour128";
    encryption_algorithms_server_to_client.len = 189;
    k.encryption_algorithms_server_to_client = encryption_algorithms_server_to_client;
    /* mac_algorithms_client_to_server */
    NameList mac_algorithms_client_to_server;
    mac_algorithms_client_to_server.content = "hmac-sha2-256,hmac-sha1,hmac-sha1-96,hmac-md5,hmac-sha2-256-etm@openssh.com,hmac-sha1-etm@openssh.com,hmac-sha1-96-etm@openssh.com,hmac-md5-etm@openssh.com";
    mac_algorithms_client_to_server.len = 155;
    k.mac_algorithms_client_to_server = mac_algorithms_client_to_server;
    /* mac_algorithms_server_to_client */
    NameList mac_algorithms_server_to_client;
    mac_algorithms_server_to_client.content = "hmac-sha2-256,hmac-sha1,hmac-sha1-96,hmac-md5,hmac-sha2-256-etm@openssh.com,hmac-sha1-etm@openssh.com,hmac-sha1-96-etm@openssh.com,hmac-md5-etm@openssh.com";
    mac_algorithms_server_to_client.len = 155;
    k.mac_algotithms_server_to_client = mac_algorithms_server_to_client;
    /* compression_algorithms_client_server */
    NameList compression_algorithms_client_to_server;
    compression_algorithms_client_to_server.content = "none,zlib";
    compression_algorithms_client_to_server.len = 9;
    k.compression_algorithms_client_to_server = compression_algorithms_client_to_server;
    /* compresson_algorithms_server_to_client */
    NameList compression_algorithms_server_to_client;
    compression_algorithms_server_to_client.content = "none,zlib";
    compression_algorithms_server_to_client.len = 9;
    k.compression_algotithms_server_to_client = compression_algorithms_server_to_client;
    /* languages_client_to_server */
    NameList languages_client_to_server;
    languages_client_to_server.content = "";
    languages_client_to_server.len = 0;
    k.languages_client_to_server = languages_client_to_server;
    /* languages_server_to_client */
    NameList languages_server_to_client;
    languages_server_to_client.content = "";
    languages_server_to_client.len = 0;
    /* first_hex_packet_follows */
    k.first_hex_packet_follows = 0;
    /* reserved */
    k.reserve = 0;
    
    /* Packet head */
    PacketHead head;
    head.padding = 5;
    head.packet_len = 0; //We set stable length
    k.head = head;
    
    /* Padding String */
    k.padding = "0000000000";
    
    *K = k;
    return FAIL;
}


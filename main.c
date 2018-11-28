//
//  main.c
//  sshx
//
//  Created by 徐鸿宇 on 2018/11/21.
//  Copyright © 2018 magbone. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>


#include "util.h"
#include "protocols.h"
#include "sshx.h"
#define BUFF_SIZE 1024


int main(int argc, const char * argv[]) {
    int client_socketfd;
    ssize_t len;
    struct sockaddr_in remote_addr;
    char buf[BUFF_SIZE]; // data
    memset(&remote_addr,0,sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr("39.108.169.48");
    remote_addr.sin_port = htons(22);
    printf("connect to 39.108.169.48\n");
    if ((client_socketfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(0);
        
    }
    if (connect(client_socketfd, (struct sockaddr*)&remote_addr, sizeof(remote_addr)) < 0) {
        perror("connnect");
        exit(0);
    }
    
    // handshake
    //client ---> ssh server Request:SSH-2.0-xxx
    ClientHello client;
    create_ClientHello(&client);
    len = send(client_socketfd, client.hello, strlen(CLIENT_HELLO), 0);
    memset(buf, 0, BUFF_SIZE);
    len = recv(client_socketfd, buf, BUFF_SIZE, 0);
    printf("%s\n",buf);
    
    //client ---> ssh server Exchange Key Init
    KeyExchangeInit init;
    create_KeyExchangeInit_packet(&init);
    
    //close socket
    close(client_socketfd);
    return 0;
}

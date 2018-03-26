//
// @author zy 
// @time 2018-02-12 10:55
//

#ifndef TCPUTIL_FILETCPCLIENT_H
#define TCPUTIL_FILETCPCLIENT_H
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include <fstream>
#include "Config.h"
#include "util.h"

using namespace std;

/**
 * 将传送的文件打开并发送
 *
 * @param url
 * @param buffer
 * @param connfd
 * @return
 */

int readFile(char *url,char *buffer,int connfd) {

    ifstream file(url, ios::ate | ios::binary);

    if (!file) {
        cout << "error. not open" << endl;
        return -1;
    }
    file.seekg(ios::beg);

    int writelen;

    char *filename = split(url, '/');
    filename = strcat(filename,"|");
    cout << "send file name is :" << filename << endl;
    /*
     * 2.12修改部分*******************
     */

    putNull(filename);
    cout << "send length:" << strlen(filename) << endl;


    //*******************************
    writelen = write(connfd, filename, strlen(filename));
    if (writelen < 0) {
        cout << "write failed " << endl;
        close(connfd);
        return 0;
    } else {
        cout << "write success:" << writelen << endl;
    }

    while (!file.eof()) {
        file.read(buffer, sizeof(buffer));
        writelen = write(connfd, buffer, sizeof(buffer));
        if (writelen < 0) {
            cout << "write failed " << endl;
            close(connfd);
            return 0;
        } else {
            cout << "write success:" << writelen << endl;
        }
    }
    file.close();

}

/**
 * 客户端传送文件接口,url为传送文件的绝对路径
 *
 * @param url
 * @return
 */

int fileclient(string url,string ip,int port){
    char *to_ip = StrToChar(url);
    int to_port = port;

    char *curl = StrToChar(url);
    int   connfd, n;
    char  recvline[4096], sendline[4096];
    struct sockaddr_in  servaddr;

    if( (connfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
        return 0;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(to_port);
    if( inet_pton(AF_INET,to_ip, &servaddr.sin_addr) <= 0){
        cout << "inet_pton error for " << to_ip << endl;
        return 0;
    }

    if(connect(connfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
        printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
        return 0;
    }
    static char sendMsg[FILETRANSERBUFFER] = {0};
    readFile(curl, sendMsg, connfd);
    close(connfd);
    return 0;
}
#endif //TCPUTIL_FILETCPCLIENT_H

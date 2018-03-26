//
// @author zy 
// @time 2018-02-12 10:56
//

#ifndef TCPUTIL_FILETCPSERVER_H
#define TCPUTIL_FILETCPSERVER_H
#include <iostream>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include <fstream>
#include "Config.h"

#define MAXLINE 4096

using namespace std;

/**
 * 将服务端接受数据写入文件.其中flag表示文件名是否读完,传输文件格式为:文件名|文件内容
 * 先将文件名读出,并创建文件,然后将数据写入.
 * (buffer这个好像有点不太对劲,我想是因为前面没有malloc所以到这里的buffer只是栈变量,
 * 只有1字节)
 *
 * @param buffer
 * @param acceptfd
 * @return
 */

int writeToFile(char* buffer,int acceptfd) {
    ofstream file;
    ssize_t totallen;
    int flag = 0;
    string filenamerecord;
    while (1) {
        ssize_t readlen = read(acceptfd, buffer, sizeof(buffer));
        cout << "read len:" << (int)readlen << endl;
        if (flag == 0) {
            char *temp;
            for (int i = 0; i < readlen; ++i) {
                cout << buffer[i] << endl;
                if (buffer[i] == '|') {
                    string filename = filenamerecord;
                    filename = FILESAVEPATH + filename;
                    file.open(filename, ios::ate | ios::binary);
                    cout << "file save path:" << filename << endl;
                    flag = 1;
                    break;
                }
                filenamerecord += buffer[i];
            }
            continue;
        }
        if (flag == 1) {
            if (readlen < 0) {
                cout << "error" << endl;
                return -1;
            } else if (readlen == 0) {
                cout << "read finish:" << totallen << endl;
                close(acceptfd);
                return 0;
            } else {
                file.write(buffer, sizeof(buffer));
                totallen += readlen;
            }
        }
    }

}

/**
 * tcp文件传输的server端,端口号配置以及文件保存都在config中进行配置
 *
 * @return
 */

int fileserver() {
    int    listenfd, acceptfd;
    struct sockaddr_in     servaddr;
    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
        printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
        return -1;
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(FILETRANSFERPORT);
    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
        printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
        return -1;
    }
    if( listen(listenfd, 10) == -1){
        printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
        return -1;
    }
    printf("======waiting for client's request======\n");
    if( (acceptfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1){
        printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
    }else{
        printf("accept succ\n");
        int rcvbuf_len;
        socklen_t len = sizeof(rcvbuf_len);
        if( getsockopt( acceptfd, SOL_SOCKET, SO_RCVBUF, (void *)&rcvbuf_len, &len ) < 0 ){
            perror("getsockopt: " );
        }
        printf("the recv buf len: %d\n" , rcvbuf_len );
    }
    char recvMsg[FILETRANSERBUFFER]={0};
    ssize_t totalLen = 0;
    writeToFile(recvMsg, acceptfd);
    close(acceptfd);
    return 0;
}
#endif //TCPUTIL_FILETCPSERVER_H

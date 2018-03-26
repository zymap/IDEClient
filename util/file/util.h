//
// @author zy
// @time 2018-02-12 10:57
//

#ifndef TCPUTIL_UTIL_H
#define TCPUTIL_UTIL_H
#include <iostream>
#include <cstring>

using namespace std;

/**
 * 求离num最近的二的n次幂
 *
 * @param num
 * @return
 */

int makesize(int num) {
    unsigned int n = num - 1;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    return n + 1;
}

/**
 * 分割函数,将字符串url以c作为分割符分开,在文件传输中使用
 *
 * @param url
 * @param c
 * @return
 */
char* split(char* url,char c) {
    for (int i = strlen(url); i > 0; --i) {
        if (url[i] == c) {
            char *result = (char *) malloc(sizeof(strlen(url) - i));
            for (int j = 0; j < strlen(url) - i; ++j) {
                result[j] = url[i + j + 1];
            }
            return result;
        }
    }
}



/**
 * 将string类型转换为char*类型
 *
 * @param str
 * @return
 */

char *StrToChar(string str) {
    char *copy = new char[str.length() + 1];
    copy = strcpy(copy, str.c_str());
    return copy;
}



/**
 * 将数据message填充到二的倍数
 * 因为在向服务端传输数据时,要先传送文件名,再以二进制传输文件,传送的文件名可能占不定大小,
 * 在文件名后面可能会包含着数据,导致二进制传输数据失败.所以将发送的message进行对齐.
 *
 * @param message
 * @return
 */

int putNull(char * message) {
    cout << "message length:" << strlen(message) << endl;
    int length = strlen(message);

    int size = makesize(length);
    cout << size <<"======"<< endl;
    for (int i = 0; i < size-length; ++i) {
        message = strcat(message, "|");
    }
    cout << strlen(message) << "=====" << endl;
}

#endif //TCPUTIL_UTIL_H

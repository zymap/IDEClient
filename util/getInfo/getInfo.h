//
// @author zy 
// @time 2018-02-15 09:08
//

#ifndef REDISUTIL_GETINFO_H
#define REDISUTIL_GETINFO_H
#include <iostream>
#include <fstream>
#include "Info-config.h"

using namespace std;

class Info{
private:
    string getInfo(string url);
public:
    string getCpuInfo();

    string getMemInfo();

    string getOsInfo();
};

string Info::getInfo(string url) {
    ifstream file;
    file.open(url, ios::in);
    if (!file) {
        cout << "error.not open" << endl;
        return "";
    }

    string info;
    while (!file.eof()) {
        string temp;
        getline(file, temp);
        info += temp;
        info = info + "\n";
    }
    file.close();
    return info;
}

string Info::getCpuInfo() {
    return getInfo(CPU);
}

string Info::getMemInfo() {
    return getInfo(MEM);
}

string Info::getOsInfo() {
    return getInfo(OS);
}
#endif //REDISUTIL_GETINFO_H

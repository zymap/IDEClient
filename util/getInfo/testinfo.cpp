//
// @author zy 
// @time 2018-02-15 09:06
//
#include <iostream>
#include "getInfo.h"

using namespace std;
void testinfo() {
    Info *info = new Info();
    string aa = info->getCpuInfo();
//    cout << aa << endl;
    cout << info->getOsInfo() << endl;
    cout << info->getMemInfo() << endl;
}
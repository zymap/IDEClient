//
// @author zy 
// @time 2018-01-30 10:25
//
#include <iostream>
#include <fstream>

#include "./ideclient.h"

using namespace std;


/*
 * from user to server
 * */
int read(string local_url) {
    fstream test(local_url, ios::in);
    char string[READLENTH];
    test.seekg(ios::beg);
    while (!test.eof()) {
        test >> string;
        cout << string;
    }
    cout << endl;
    test.close();
    return 0;
}

int write(string local_url) {

}
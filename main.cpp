#include <iostream>

extern void testideclient();
using namespace std;
#define url ""

extern int read(string local_url);

int main() {

    testideclient();
//    system("nohup redis-server &");
//    read("../testFile/a.txt");


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
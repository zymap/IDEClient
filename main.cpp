#include <iostream>

using namespace std;
#define url ""

extern int read(string local_url);

int main() {


    read("../testFile/a.txt");


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
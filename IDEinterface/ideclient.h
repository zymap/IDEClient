//
// @author zy 
// @time 2018-01-30 09:36
//

#ifndef IDECLIENT_IDECLIENT_H
#define IDECLIENT_IDECLIENT_H

#include <iostream>
#include "../pojo/ServerArgs.h"

using namespace std;

class IdeClient {
private:
    string getServerIP(string servername);

public:
    int setcache(ServerArgs &serverArgs);
    int submit_server(ServerArgs &serverArgs);

    int search_server(string servername);

    int start_server(string servername);

    int stop_server(string servername);
};


#define READLENTH 1024

#endif //IDECLIENT_IDECLIENT_H

//
// @author zy 
// @time 2018-01-30 09:30
//

#include <iostream>
#include "../pojo/ServerArgs.h"

using namespace std;

class IdeClient {
private:
    int upload(ServerArgs &serverArgs);

    string getServerIP();

    int connection();

    int download();

    int setcache();
public:
    int submit_server(ServerArgs &serverArgs);

    int search_server();

    int start_server();

    int stop_server();
};

int IdeClient::submit_server(ServerArgs &serverArgs) {

}

string IdeClient::getServerIP() {

}

int IdeClient::upload(ServerArgs &serverArgs) {

}
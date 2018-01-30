//
// @author zy 
// @time 2018-01-30 09:38
//

#ifndef IDECLIENT_SERVERARGS_H
#define IDECLIENT_SERVERARGS_H

//ServerArgs type
#define PHONE   0001
#define LAPTOP  0010
#define COMPUTER    0011
#define SERVERS 0100

//ServerArgs overwrite
#define OVERWRITE   1
#define NOTVERWRITE 0


#include <iostream>

using namespace std;

struct ServerArgs {
    string server_name;
    string service_url;
    int overwrite;
    string time;
    int type;
    string environment;
};




#endif //IDECLIENT_SERVERARGS_H

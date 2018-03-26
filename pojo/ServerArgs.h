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


class ServerArgs {
private:
    string server_name;
    string service_url;
    string service_startshell;
    int overwrite;
    string time;
    int type;
//    string environment;
public:


    const string &getServer_name() const {
        return server_name;
    }

    void setServer_name(const string &server_name) {
        ServerArgs::server_name = server_name;
    }

    const string &getService_url() const {
        return service_url;
    }

    void setService_url(const string &service_url) {
        ServerArgs::service_url = service_url;
    }

    int getOverwrite() const {
        return overwrite;
    }

    void setOverwrite(int overwrite) {
        ServerArgs::overwrite = overwrite;
    }

    const string &getTime() const {
        return time;
    }

    void setTime(const string &time) {
        ServerArgs::time = time;
    }

    int getType() const {
        return type;
    }

    void setType(int type) {
        ServerArgs::type = type;
    }

    const string &getStartshell() const {
        return service_startshell;
    }

    void setStartshell(const string &startshell) {
        ServerArgs::service_startshell = startshell;
    }
};
//struct ServerArgs {
//    string server_name;
//    string service_url;
//    int overwrite;
//    string time;
//    int type;
//    string environment;
//};




#endif //IDECLIENT_SERVERARGS_H

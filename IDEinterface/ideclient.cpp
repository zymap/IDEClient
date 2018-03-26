//
// @author zy 
// @time 2018-01-30 09:30
//

#include <iostream>
#include "../pojo/ServerArgs.h"
#include "../util/redis/redisutil.h"
#include "config/config.h"
#include "../util/file/filetcpclient.h"
#include "../util/ideclientutil.h"
#include "ideclient.h"

using namespace std;

/**
 * 本地客户段所需要的接口,上传服务及启动脚本,上传后可以 选择是否启动服务,或者停止服务
 */


int IdeClient::stop_server(string servername) {
    /**
     * udp通知关闭服务
     */
}

int IdeClient::start_server(string servername) {
    /**
     * udp发送到server进行服务启动
     */
}

int IdeClient::search_server(string servername) {
    /**
     * udp发送广播进行搜查
     */
}

int IdeClient::setcache(ServerArgs &serverArgs) {
    string servername = serverArgs.getServer_name();
    string url = serverArgs.getService_url();
    string service_startshell = serverArgs.getStartshell();

    string record = createRedisCache(servername, url,service_startshell);

    CRedis *redis = new CRedis();
    redis->lpush(SERVERCACHE, record);
    delete (redis);
}

int IdeClient::submit_server(ServerArgs &serverArgs) {
    string redis_ip = getServerIP(serverArgs.getServer_name());
    vector<string> v_ip;
    ssplit(redis_ip, v_ip, ":");
    string ip = v_ip[0];
    int port = StrToInt(v_ip[1]);
//    fileclient(serverArgs.getService_url(),ip,port);
//    fileclient(serverArgs.getStartshell(), ip, port);
}

string IdeClient::getServerIP(string servername) {
    CRedis *redis = new CRedis();
    string name = redis->get(servername);
    delete (redis);
    return name;
}


//---------------------------------------------------

void testideclient() {
    IdeClient *ideClient = new IdeClient;
    ServerArgs *serverArgs = new ServerArgs;
    serverArgs->setServer_name("wawawa");
    serverArgs->setService_url("/a/a/a/b");
    serverArgs->setStartshell("/b/c/d/sss.sh");
//    ideClient->submit_server(*serverArgs);

    ideClient->setcache(*serverArgs);
}


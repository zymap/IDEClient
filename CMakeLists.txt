cmake_minimum_required(VERSION 3.8)
project(IDEClient)

#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fno-stack-protector ${CMAKE_CXX_FLAGS} -std=c++11 ")

#set(SOURCE_FILES main.cpp IDEinterface/ideclient.cpp IDEinterface/ideclient.h pojo/ServerArgs.h IDEinterface/fileopt.cpp test/MyTest.cpp test/MyTest.h util/redis/config.h util/redis/transformUtil.h IDEinterface/config/config.h util/file/Config.h util/file/filetcpclient.h)
#set(SOURCE_FILES
#        local/UdpMessageHandle.cpp pojo/TransportMessageInfo.cpp pojo/TransportMessageInfo.h
#        IDEinterface/search/searched.h util/ideclientutil.h
#        util/utiltest.cpp local/UdpMessageState.h util/file/readpid.h)
set(SOURCE_FILES util/utiltest.cpp)
set(SOURCE_FILES IDEinterface/ideclient.cpp util/udp/UDPUtil.h)
add_subdirectory( startup )

AUX_SOURCE_DIRECTORY(. SOURCE_FILES)
add_executable(IDEClient ${SOURCE_FILES} IDEinterface/search/searched.cpp)


link_directories("/usr/lib")
link_directories("/usr/local/include")
target_link_libraries(IDEClient hiredis STARTUP)

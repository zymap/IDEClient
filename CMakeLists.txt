cmake_minimum_required(VERSION 3.8)
project(IDEClient)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp IDEinterface/ideclient.cpp IDEinterface/ideclient.h pojo/ServerArgs.cpp pojo/ServerArgs.h)
add_executable(IDEClient ${SOURCE_FILES})
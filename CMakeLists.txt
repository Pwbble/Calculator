cmake_minimum_required(VERSION 3.20)

# Declares the project name?
project(CPP)

set(CMAKE_CXX_STANDARD 17)
find_package(Threads REQUIRED)

add_executable(CPP source/Main.cpp source/computation/Operations.cpp source/computation/Operations.h source/logic/ParseTree.cpp source/logic/ParseTree.h source/handlers/ErrorHandler.cpp source/handlers/ErrorHandler.h source/handlers/StringUtils.cpp source/handlers/StringUtils.h)
target_link_libraries(CPP Threads::Threads)
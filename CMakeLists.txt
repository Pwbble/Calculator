cmake_minimum_required(VERSION 3.20)

# Declares the project name
project(CPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPP Main.cpp Operations.cpp HeaderFiles/operators.h ParseTree.cpp HeaderFiles/parsetree.h)
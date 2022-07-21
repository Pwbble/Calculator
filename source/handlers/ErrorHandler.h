#include <iostream>

#ifndef CPP_ERRORHANDLER_H
#define CPP_ERRORHANDLER_H

enum error {
    COMPLEX_SOLUTION, SYNTAX, UNDEFINED_SOLUTION
};

std::string getError(error type);

#endif
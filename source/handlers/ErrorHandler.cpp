#include "ErrorHandler.h"

using std::cout;
using std::string;

string getError(error type) {
    switch (type) {
        case COMPLEX_SOLUTION:
            return "Complex Solution: The solution to the equation you entered contains imaginary numbers.";
        case SYNTAX:
            return "Syntax: I do not understand the equation you entered.";
        case UNDEFINED_SOLUTION:
            return "Undefined Solution: I do not understand the equation you entered.";
    }
}
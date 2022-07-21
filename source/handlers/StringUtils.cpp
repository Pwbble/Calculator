#include "StringUtils.h"

using std::string;

string StringUtils::toLowerCase(string s) {
    string evaluation;
    for (char a : s) evaluation += tolower(a);
    return evaluation;
}
#include <iostream>
#include <vector>

using std::string;

#ifndef CPPTESTS_OPERATIONS_H
#define CPPTESTS_OPERATIONS_H

string simplify(string n);

int charToInt(char c);

char intToChar(int i);

string flip(string& n);

string vectorToString(std::vector<int> n);

string createZeroString(string n, int length);

bool isInt(string n);

bool isEven(string n);

bool isEqual(string x, string y);

bool isBetween(string x, string y, string z);

bool isBetweenOrEqual(string x, string y, string z);

string lambertW(string n);

string logBase(string x, string y);

string exponent(string x, string y);

string multiply(string x, string y);

string multiply(std::vector<string> n);

string divide(string x, string y);

string add(string x, string y);

string add(std::vector<string> n);

string subtract(string x, string y);

#endif
#include <iostream>
#include <vector>
#include "General.h"

using std::cout;
using std::string;
using std::vector;

bool isOperator(const char arg) {
    return (arg == '^' || arg == '*' || arg == '/' || arg == '!' || arg == '(' || arg == ')');
}

// Splits a(n) (string) input into tokens which are returned as a (string) vector.
vector<string> tokenization(string input) {
    vector<string> equation;
    int skip = 1;
    cout << "["; // Debug
    for (int a = 0; a < input.length(); a++) {
        if (input[a] == ' ') break;
        if (a == 0 || input[a] == '+' || input[a] == '-' || isOperator(input[a]) ||
            isOperator(input.at(a - 1))) {
            equation.push_back({input.at(a)});
            // Creates a new element in the array and adds input.at(a) to it.
            cout << ((a == 0) ? "pb" : ", pb"); // Debug
        } else {
            equation[a - skip] += input.at(a); // Adds input.at(a) to the element equation[a - skip].
            skip++;
            cout << ", s"; // Debug
        }
    }
    cout << "], {"; // Debug
    for (auto &b: equation) cout << "\"" << b << "\", "; // Debug
    cout << "}, equation.size() = " << equation.size(); // Debug
    return equation;
}
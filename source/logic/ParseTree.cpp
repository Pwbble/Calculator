#include <vector>
#include "../computation/Operations.h"

using std::cout;
using std::vector;

bool isOperator(char arg) {
    return (arg == '^' || arg == '*' || arg == '/' || arg == '!' || arg == '(' || arg == ')');
}

// Splits a(n) (string) input into tokens which are returned as a (string) vector
vector<string> tokenization(string input) {
    vector<string> equation;
    int skip = 1;
    cout << "["; // Debug
    for (int a = 0; a < input.length(); a++) {
        // Skips past spaces
        if (input[a] == ' ') skip++;
        else if (a == 0 || input[a] == '+' || input[a] == '-' || isOperator(input[a]) ||
            isOperator(input[a - 1])) {
            // Creates a new element in the (string vector) equation and adds (string) input[a] to it
            equation.push_back({input[a]});
            cout << ((a == 0) ? "pb" : ", pb"); // Debug
        } else {
            equation.at(a - skip) += input[a]; // Adds input[a] to the element equation.at(a - skip)
            skip++;
            cout << ", s"; // Debug
        }
    }
    cout << "], {"; // Debug
    for (auto &b: equation) cout << "\"" << b << "\", "; // Debug
    cout << "}, equation.size() = " << equation.size(); // Debug
    return equation;
}

// Simplify given an input which doesn't contain a parenthesis
string simplifyNonParenthetic(int lower_bound, int upper_bound, vector<string> equation) {
    for (int a = lower_bound; a < upper_bound; a++) {
        if (equation.at(a) == "^") equation.at(a - 1) = exponent(equation.at(a - 1), equation.at(a + 1));
        // Erases (string vector) equation[a] through (string vector) equation[a + 1]
        // equation.erase(equation.begin() + a - 1, equation.begin() + a);
        cout << "\n\nsimplifyNonParenthetic()"; // Debug
    }
    for (string &b: equation) cout << "\"" << b << "\", "; // Debug
    cout << "\n\n" << equation[0]; // Debug
    // for (int a = lower_bound; a < ; a++) {}
    // for (int a = lower_bound; a < ; a++) {}
    return {};
}

string simplifyNonParenthetic(vector<string> equation) {
    return simplifyNonParenthetic(0, equation.size(), equation);
}

// Simplify given an input containing parenthesis
string simplifyParenthetic(vector<string> equation) {
    vector<int> OPLoc;
    int OPC, CPC;
    for (int a = 0; a < equation.size(); a++) {
        if (equation.at(a) == "(") {
            OPLoc.push_back({a});
            OPC++;
        } else if (equation.at(a) == ")") CPC++;
        if (equation.at(a) == ")" && CPC == 0) {
            equation.at(OPLoc[OPLoc.size()]) = simplifyNonParenthetic(OPLoc.size(), a, equation);
            // Erase equation.at(OPLoc[OPLoc.size()] + 1) through equation.at(a)
        }
    }
    // if (OPC != CPC) syntax
    if (OPC == 0) return simplifyNonParenthetic(equation);
    return {};
}

string calculate(string expression) {
    return simplifyParenthetic(tokenization(expression));
}
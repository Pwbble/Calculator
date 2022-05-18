#include <vector>
#include "HeaderFiles/operators.h"

using std::cout;
using std::vector;

bool isOperator(const char arg) {
    return (arg == '^' || arg == '*' || arg == '/' || arg == '!' || arg == '(' || arg == ')');
}

// Splits a(n) (string) input into tokens which are returned as a (string) vector
vector<string> tokenization(string input) {
    vector<string> equation;
    int skip = 1;
    cout << "["; // Debug
    for (int a = 0; a < input.length(); a++) {
        // Skips past spaces
        if (input[a] == ' ') continue;
        if (a == 0 || input[a] == '+' || input[a] == '-' || isOperator(input[a]) ||
            isOperator(input[a - 1])) {
            equation.push_back({input[a]});
            // Creates a new element in the array and adds input[a] to it
            cout << ((a == 0) ? "pb" : ", pb"); // Debug
        } else {
            equation[a - skip] += input[a]; // Adds input[a] to the element equation[a - skip]
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
    }
    cout << "\n\n" << equation[0];

    /*
     * Notes:

     1) After parenthesis, we need to simplify all functions.
     2) Next, we need to look for exponents.
     3) Next we need to look for multiplication and division.
     4) Finally, we need to look for addition and subtraction.
     */
    return "";
}

// Simplify given an input containing parenthesis
string simplifyParenthetic(vector<string> equation) {
    int OpenParenthesisCounter, ClosedParenthesisCounter;
    for (int a = 0; a < equation.size(); a++) {
        if (equation[a] == "(" || equation[a] == ")")
            (equation[a] == "(") ? OpenParenthesisCounter++ : ClosedParenthesisCounter++;
    }
    // if (OpenParenthesisCounter != ClosedParenthesisCounter) syntax
    if (OpenParenthesisCounter == 0) return simplifyNonParenthetic(0, equation.size(), equation);
    return "";
}

string calculate(string input) {
    return simplifyParenthetic(tokenization(input));
}
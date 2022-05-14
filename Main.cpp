#include <cmath>
#include <iostream>
#include <vector>
#include "General.h"

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::to_string;
using std::tolower;
using std::vector;

// Lambert W or Omega function is the inverse of xe^x
string lambertW(string arg) {
    cout << "Approximating Lambert W logarithm of " << arg << "...\n"; // Debug
    if (stod(arg) <= -1 / exp(1)) return "Error: Domain..."; // Update once new error system is done.
    double Guess = (stod(arg) <= 1) ? -0.25 : log(stod(arg));
    for (int a = 0; a < 10; a++) Guess = Guess - (((Guess * exp(Guess) - stod(arg)) / (Guess * exp(Guess) + exp(Guess))));
    return to_string(Guess);
}

string logBase(string base, string arg) {
    cout << "Approximating log base " << base << " of " << arg << "...\n"; // Debug
    return to_string(log(stod(arg)) / log(stod(base)));
}

string multiply(string number1, string number2) {
    cout << "Multiplying " << number1 << " and " << number2 << "...\n"; // Debug
    return to_string(stod(number1) * stod(number2));
}

string divide(string number1, string number2) {
    cout << "Dividing " << number1 << " and " << number2 << "...\n"; // Debug
    return to_string(stod(number1) / stod(number2));
}

string add(string number1, string number2) {
    cout << "Adding " << number1 << " and " << number2 << "...\n"; // Debug
    return to_string(stod(number1) + stod(number2));;
}

string subtract(string number1, string number2) {
    cout << "Subtracting " << number1 << " and " << number2 << "...\n"; // Debug
    return to_string(stod(number1) - stod(number2));
}

string toLowerCase(string arg) {
    string evaluation;
    for (int a = 0; a < arg.length(); a++) evaluation += tolower(arg.at(a));
    return evaluation;
}

// Simplify given an input which doesn't contain a parenthesis
string simplifyNonParenthetic(int lower_bound, int upper_bound, vector<string> equation) {

    /*
     * Notes:

     1) After parenthesis, we need to simplify all functions.
     2) Next, we need to look for exponents.
     3) Next we need to look for multiplication and division.
     4) Finally, we need to look for addition and subtraction.
     */
    cout << "test"; // Debug
    return "";
}

// Simplify given an input containing parenthesis.
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

string lookUpCommand(string command) {
    if (toLowerCase(command) == "stop") return "Terminating program, please wait...";
    if (toLowerCase(command) == "help")
        return "+---------------------------------------------------+\n"
               "| This calculator supports the following operators: |\n"
               "|                                                   |\n"
               "| Trigonometry: All trigonometric functions         |\n"
               "|               are included in this calculator.    |\n"
               "| Calculus: No calculus functions are included yet. |\n"
               "| Exponential: exp(x), sqrt(x), cbrt(x), rooty(x),  |\n"
               "|              and x^y are included in this         |\n"
               "|              calculator.                          |\n"
               "| Logarithmic: ln(x), log(x), logy(x), and W(x) are |\n"
               "|              all included in this calculator.     |\n"
               "| Miscellaneous: x!, x!!, |x|, mod(x,y), round(x),  |\n"
               "|                floor(x), ceil(x), and sign(x) are |\n"
               "|                included in this calculator.       |\n"
               "+---------------------------------------------------+";
    return simplifyParenthetic(tokenization(command));
}

void run() {
    string command;
    cout << "\n░███████╗░███████╗░██╗░░░░░░███████╗░██╗░░░██╗░██╗░░░░░░███████╗░████████╗░███████╗░███████╗░\n"
            "░██╔══██║░██╔══██║░██║░░░░░░██╔══██║░██║░░░██║░██║░░░░░░██╔══██║░╚══██╔══╝░██╔══██║░██╔══██║░\n"
            "░██║░░╚═╝░███████║░██║░░░░░░██║░░╚═╝░██║░░░██║░██║░░░░░░███████║░░░░██║░░░░██║░░██║░█████╬═╝░\n"
            "░██║░░██╗░██╔══██║░██║░░░░░░██║░░██╗░██║░░░██║░██║░░░░░░██╔══██║░░░░██║░░░░██║░░██║░██╔══██╗░\n"
            "░███████║░██║░░██║░███████╗░███████║░████████║░███████╗░██║░░██║░░░░██║░░░░███████║░██║░░██║░\n"
            "░╚══════╝░╚═╝░░╚═╝░╚══════╝░░╚═════╝░╚═══════╝░╚══════╝░╚═╝░░╚═╝░░░░╚═╝░░░░░╚═════╝░╚═╝░░╚═╝░\n"
            "\nType \"help\" for help.\n"
            "Supported operators: (+, -, *, /, ^, √() sqrt())\n";
    do {
        cout << "> ";
        getline(cin, command);
        cout << "\n" << lookUpCommand(command) << "\n\n";
    } while (toLowerCase(command) != "stop");
}

int main() {
    run();
    return 0;
}
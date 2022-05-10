#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

string lambertW(string arg) {
    cout << "Approximating Lambert W logarithm of " << arg << "...\n"; // Debug
    if (stod(arg) <= -1 / exp(1)) return "Error: Domain..."; // Due to be updated.
    double guess = (stod(arg) <= 1) ? -0.25 : log(stod(arg));
    for (int a = 0; a < 10; a++) guess = guess - (((guess * exp(guess) - stod(arg)) / (guess * exp(guess) + exp(guess))));
    return to_string(guess);
} // Inverse of xe^x

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

bool isOperator(char arg) {
    if (arg == '^' || arg == '*' || arg == '/' || arg == '!' || arg == '(' || arg == ')') return true;
    return false;
}

class EquationSorter {
public:
    vector<string> equation;
    int skip = 1;

    string mainFunc(string command) {
        cout << "["; // Debug
        for (int a = 0; a < command.length(); a++) {
            if (a == 0 || command.at(a) == '+' || command.at(a) == '-' || isOperator(command.at(a)) ||
                isOperator(command.at(a - 1))) {
                equation.push_back({command.at(a)});
                // Creates a new element in the array and adds command.at(a) to it.
                cout << ((a == 0) ? "pb" : ", pb"); // Debug
            } else {
                equation[a - skip] += command.at(a); // Adds command.at(a) to the element equation[a - skip].
                skip++;
                cout << ", s"; // Debug
            }
        }
        cout << "], {"; // Debug
        for (auto &b: equation) cout << "\"" << b << "\", "; // Debug
        cout << "}, equation.size() = " << equation.size() << "\n"; // Debug
        return "";
    }
};

string orderOfOperations(int lower_bound, int upper_bound, vector<string> dynamic_arraylist) {
    int skip = 2;

    /*
     * Notes:

     1) After parenthesis, we need to simplify all functions.
     2) Next, we need to look for exponents.
     3) Next we need to look for multiplication and division.
     4) Finally, we need to look for addition and subtraction.
     dynamic_arraylist[a] will always be a number, so perhaps start at dynamic_arraylist[a + 1]?


     */

    for (int a = lower_bound + 1; a < upper_bound; a++) {
        if (dynamic_arraylist[a] == "^");
    }
    return "";
}

string evaluationAlgorithm(string command) {

    EquationSorter equationSorter;
    equationSorter.mainFunc(command);

    for (int a = 0; a < equationSorter.equation.size(); a++) {

    }
    return ("Answer: " + equationSorter.equation[0]);
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
    if (toLowerCase(command) == "run test") {
        cout << lambertW("777");
        return "";
    }
    return evaluationAlgorithm(command);
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
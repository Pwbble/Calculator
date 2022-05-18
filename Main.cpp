#include "HeaderFiles/parsetree.h"

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::tolower;

string toLowerCase(string arg) {
    string evaluation;
    for (int a = 0; a < arg.length(); a++) evaluation += tolower(arg.at(a));
    return evaluation;
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
    return calculate(command);
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
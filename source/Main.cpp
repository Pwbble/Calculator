#include "computation/Operations.h"
#include "handlers/StringUtils.h"
#include "logic/ParseTree.h"

using std::cout;
using std::cin;
using std::getline;
using std::string;

string lookUpCommand(const string& command) {
    if (StringUtils::toLowerCase(command) == "stop") return "Terminating program, please wait...";
    if (StringUtils::toLowerCase(command) == "help")
        return "+---------------------------------------------------+\n"
               "| Help Menu                                         |\n"
               "+---------------------------------------------------+\n"
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

void run(const string& system) {
    if (system == "calculator") {
        string command;
        cout << "\n░███████╗░███████╗░██╗░░░░░░███████╗░██╗░░░██╗░██╗░░░░░░███████╗░████████╗░███████╗░███████╗░\n"
                "░██╔══██║░██╔══██║░██║░░░░░░██╔══██║░██║░░░██║░██║░░░░░░██╔══██║░╚══██╔══╝░██╔══██║░██╔══██║░\n"
                "░██║░░╚═╝░███████║░██║░░░░░░██║░░╚═╝░██║░░░██║░██║░░░░░░███████║░░░░██║░░░░██║░░██║░█████╬═╝░\n"
                "░██║░░██╗░██╔══██║░██║░░░░░░██║░░██╗░██║░░░██║░██║░░░░░░██╔══██║░░░░██║░░░░██║░░██║░██╔══██╗░\n"
                "░███████║░██║░░██║░███████╗░███████║░████████║░███████╗░██║░░██║░░░░██║░░░░███████║░██║░░██║░\n"
                "░╚══════╝░╚═╝░░╚═╝░╚══════╝░░╚═════╝░╚═══════╝░╚══════╝░╚═╝░░╚═╝░░░░╚═╝░░░░░╚═════╝░╚═╝░░╚═╝░\n"
                "\nType \"help\" for help.\n";
        do {
            cout << "> ";
            getline(cin, command);
            cout << "\n" << lookUpCommand(command) << "\n\n";
        } while (StringUtils::toLowerCase(command) != "stop");
    } else if (system == "test") {
        cout << add("1749812472981472149678657982136457896381763874965879168734919", "19834795712739846798162379846587162384765871623487916598173648197651111") << "\n";
        // cout << subtract("", "") << "\n";
    }
}

int main() {
    run("test");
    return 0;
}
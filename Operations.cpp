#include <cmath>
#include <iostream>

using std::cout;
using std::string;
using std::to_string;

// The Lambert W function or Omega function is the inverse of xe^x
string lambertW(string arg) {
    cout << "Approximating Lambert W logarithm of " << arg << "...\n"; // Debug
    if (stod(arg) <= -1 / exp(1)) return "Error: Domain..."; // Update once new error system is done.
    double Guess = (stod(arg) <= 1) ? -0.25 : log(stod(arg));
    for (int a = 0; a < 10; a++) Guess = Guess - (((Guess * exp(Guess) - stod(arg)) / (Guess * exp(Guess) + exp(Guess))));
    return to_string(Guess);
}

// A Logarithm is the inverse of arg = base^x
string logBase(string base, string arg) {
    cout << "Approximating log base " << base << " of " << arg << "...\n"; // Debug
    return to_string(log(stod(arg)) / log(stod(base)));
}

string exponent(string base, string power) {
    return to_string(pow(stod(base), stod(power)));
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
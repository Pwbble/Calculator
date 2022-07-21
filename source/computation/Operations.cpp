#include <cmath>
#include <iostream>
#include <thread>
#include <vector>
#include "../handlers/ErrorHandler.h"
#include "Operations.h"

using std::cout;
using std::endl;
using std::thread;
using std::to_string;
using std::vector;

/**
 * Removes unnecessary 0s from n.
 * @return n in simplest form.
 */
string simplify(string n) {
    int minusCount;
    for (auto &a: n) {
        if (a == '-') {
            minusCount++;
            continue;
        }
        if (a != 0);
    }

    return n;
}

/**
 * Converts a char to an integer.
 * @return The char as an integer.
 */
int charToInt(char c) {
    return c - '0';
}

/**
 * Converts an integer to a char.
 * @return The integer as a char.
 */
char intToChar(int i) {
    return i + '0';
}

/**
 * @return The opposite of n.
 */
string flip(string& n) {
    if (n[0] == '-') {
        for (int a = 0; a < n.length(); a++) n[a] = n[a + 1];
        n.resize(n.size() - 1);
        return n;
    }
    return '-' + n;
}

/**
 * Strings together all of the elements in n in reverse.
 * @return The vector reversed as a string.
 */
string vectorToString(vector<int> n) {
    string evaluation;
    // Reverses the elements
    for (int a = n.size(); a > 0; a--) evaluation += intToChar(n[a - 1]);
    return evaluation;
}

string createZeroString(string n, int length) {
    cout << n << endl; // Debug
    string zeros;
    for (int a = 0; a < length - n.length(); a++) zeros += '0';
    return zeros + n;
}

/**
 * Checks if n is an integer.
 * @return Returns true if n is an integer, and false if n is not an integer.
 */
bool isInt(string n) {
    bool decimal = false;
    for (int a = 0; a < n.length(); a++) {
        if (n[a] == '.') {
            decimal = true;
            continue;
        }
        // If n has any decimal numbers that aren't 0
        if (decimal && n[a] != '0') return false;
    }
    return true;
}

/**
 * Checks if n is divisible by 2.
 * @return True if n is even, and false if n is odd.
 */
bool isEven(string n) {
    for (int a = 0; a < n.length(); a++) if (n[a] == '.') return (isInt(n) && n[a - 1] % 2 == 0);
    return false;
}

/**
 * Checks if the value of x is equal to the value of y.
 * @return True if x = y, and false if x != y.
 */
bool isEqual(const string x, const string y) {

    return false;
}

/**
 * Checks if the value of y is inbetween x and z. (x \< y \< z)
 * @return True if x \< y \< z, and false if !(x \< y \< z).
 */
bool isBetween(const string x, const string y, const string z) {

    return false;
}

/**
 * Checks if the value of y is between or equal to either x or z. (x \<= y \<= z)
 * @return True if x \<= y \<= z, and false if !(x \<= y \<= z).
 */
bool isBetweenOrEqual(const string x, const string y, const string z) {
    return isBetween(x, y, z) || isEqual(x, y) || isEqual(y, z);
}

/**
 * @return The approximation for the inverse of n = xe^x.
 */
string lambertW(string n) {
    if (stod(n) <= -1 / exp(1)) return getError(error(COMPLEX_SOLUTION));
    double Guess = (stod(n) <= 1) ? -0.25 : log(stod(n));
    for (int a = 0; a < 10; a++)
        Guess = Guess - (((Guess * exp(Guess) - stod(n)) / (Guess * exp(Guess) + exp(Guess))));
    return to_string(Guess);
}

/**
 * @return The approximation for the base x logarithm of y.
 */
string logBase(string x, string y) {
    return to_string(log(stod(y)) / log(stod(x)));
}

/**
 * Raises x to the y.
 * @return x to the y.
 */
string exponent(string x, string y) {
    if (isEqual(y, "0")) return "1";

    return {};
}

// Multiplies x and y (x * y)

/**
 * Multiplies x and y together.
 * @return The product of x and y.
 */
string multiply(string x, string y) {
    if (isEqual(x, "0") || isEqual(y, "0")) return "0";
    /*
     * Let x, y be positive real numbers.
     * 0x = 0y = y
     * xy = -x(-y)
     * -xy = x(-y)
     */
    bool positive = true;
    if ((x[0] == '-' && y[0] != '-') || (x[0] != '-' && y[0] == '-')) {
        positive = false;
        flip(x);
        flip(y);
    }
    return {};
}

/**
 * Multiplies a list of numbers together (n_1 * n_2 * ... * n_n.size()), allowed by the commutative property.
 * Allowed by the commutative property.
 * @param n The list of numbers.
 * @return The product of n_1, n_2, ..., n_n.size().
 */
string multiply(vector<string> n) {
    int amountOfNegatives;
    bool positive = true;
    for (auto &a: n) {
        if (isEqual(a, "0")) return "0";
        if (a[0] == '-') amountOfNegatives++;
    }
    if (amountOfNegatives % 2 != 0) positive = false;


    return {};
}

/**
 * Divides x by y (x / y).
 * @return The quotient of x and y.
 */
string divide(string x, string y) {
    /*
     * Let x, y be positive real numbers.
     * x / 0 is undefined
     * 0 / y = 0
     * -x / y = x / -y = -(x / y)
     * -x / -y = x / y
     */
    if (isEqual(y, "0")) return "UNDEFINED";
    if (isEqual(x, y)) return "1";
    return {};
}

/**
 * Adds x to y.
 * @return The sum of x and y.
 */
string add(string x, string y) {
    /*
     * Let x, y be positive real numbers
     * x + y = x + y positive
     * x + (-y) = x - y
     * -x + y = y - x
     * -x + (-y) = -x - y = -(x + y) negative
     */
    if (isEqual(y, "0")) return x;
    if (isEqual(x, "0")) return y;
    bool positive = true;
    int xLength = x.length(), yLength = y.length();
    // If x and y are both negative the final solution will also be negative
    if (x[0] == '-' && y[0] == '-') {
        positive = false; // Sets the final solution to be negative
        // Changes x and y to positive values by reference
        flip(x);
        flip(y);
        xLength--;
        yLength--;
    } else if (x[0] == '-' || y[0] == '-') return subtract((x[0] == '-') ? y, x : x, y);
    vector<int> evaluation;
    int iterations = xLength, digitSum;
    bool carry = false; // Max carry is 1 for the sum of 2 digits
    cout << "x.length(): " << xLength << endl << "y.length(): " << yLength << endl; // Debug
    if (xLength > yLength) {
        y = createZeroString(y, xLength);
        // iterations = yLength + 1; Plans for different implementation
        iterations = xLength;
    } else {
        x = createZeroString(x, yLength);
        // iterations = xLength + 1;
        iterations = yLength;
    }
    cout << "x: " << x << endl; // Debug
    cout << "y: " << y << endl; // Debug
    cout << "iterations: " << iterations << endl; // Debug
    for (int a = iterations - 1; a > -1; a--) {
        digitSum = charToInt(x[a]) + charToInt(y[a]);
        cout << "digitSum: " << digitSum << ", digitSum + carry: " << digitSum + carry << ", carry: " << carry
             << endl; // Debug
        cout << "mod(" << digitSum + carry << ", 10) = " << (digitSum + carry) % 10 << endl; // Debug
        evaluation.push_back({(digitSum + carry) % 10});
        // Accounts for digitSum > 10 and digitSum + carry > 10
        if (digitSum + carry >= 10) carry = true;
        else carry = false;
    }
    if (carry) evaluation.push_back(1);
    // for (auto &a: evaluation) cout << a << endl; // Debug
    return (positive) ? vectorToString(evaluation) : '-' + vectorToString(evaluation);
}

/**
 * Adds a list of numbers together (n_1 + n_2 + ... + n_n.size()), allowed by the commutative property.
 * Allowed by the commutative property.
 * @param n : The list of numbers.
 * @return The sum of n_1, n_2, ..., n_n.size().
 */
string add(vector<string> n) {
    vector<string> positiveElements, negativeElements;
    vector<int> positiveEvaluation, negativeEvaluation, carries;
    int secondmaxlength[2];
    for (auto &a: n) {
        if (isEqual(a, "0")) continue;
        if (a[0] == '-') negativeElements.push_back({flip(a)});
        else positiveElements.push_back({a});
        if (a.length() > secondmaxlength[0]) {
            secondmaxlength[0] = a.length();
            secondmaxlength[1] = secondmaxlength[0];
        }
    }
    // Returns the absolute value of the sum of all the elements in n
    auto sum = [=](vector<string> n) {
        // for (int a = /*Iterations*/; a > 0; a--) {}
    };
    thread positiveSum(sum, positiveElements);
    thread negativeSum(sum, negativeElements);
    // Ensures both threads finish before moving on
    positiveSum.join();
    negativeSum.join();
    cout << vectorToString(positiveEvaluation) << endl; // Debug
    cout << vectorToString(negativeEvaluation) << endl; // Debug
    return subtract(vectorToString(positiveEvaluation), vectorToString(negativeEvaluation));
}

/**
 * Subtracts y from x. (x - y)
 * @return The difference between y and x.
 */
string subtract(string x, string y) {
    /*
     * Let x, y be positive real numbers
     * x - y = x - y
     * x - (-y) = x + y
     * -x - y = -(x + y)
     * -x - (-y) = -x + y = y - x
     */
    if (isEqual(y, "0")) return x;
    if (isEqual(x, 0)) return flip(y);
    if (y[0] == '-') return add(x, flip(y));
    return {};
}
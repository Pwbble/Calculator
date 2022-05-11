## Libraries

- [iostream](https://www.cplusplus.com/reference/istream/iostream/?kw=iostream)
- [cmath](https://www.cplusplus.com/reference/cmath/)
- [vector](https://www.cplusplus.com/reference/vector/vector/?kw=vector)

## Logic

This calculator works in steps:

1. Break the (string) input into tokens which are then stored as a(n) (vector) equation.
2. Determine best section to start or continue simplification.
3. Simplify using my Non-Parenthetic function.
4. Repeat steps 2 and 3 until answer is found.

The method I am using for my calculator is one that I formulated myself through some experimentation. I am positive this is not the first time this method is being used in a calculator, so by no means dub me the original source of it.

## Equation Interpretation Loop

> Arguments: mainFunc(string input)

The mainFunc is the general process for the class "EquationSorter". I decided to create a class for this operation because I plan to make several calls of it throughout the calculator. This also allows me to refer to the (string) vector equation made in "EquationSorter".

For the next section it is important to know that the iterator 'a' is looping over the (string) input.

- If a = 0 -> create a new element in the (vector) equation.
- If command.at(a) is an operator -> create a new element in the (vector) equation.
- If command.at(a - 1) is an operator -> create a new element in the (vector) equation.
- If a is not an operator and command.at(a - 1) is not an operator -> add command.at(a) to last element in (vector) equation.

## Debug

When a user inputs an equation, some useful debug information will be sent.

Example: Suppose somebody enters the equation "4 * 8".
The debug information that will be sent should look like this: [pb, pb, pb] -> {"4", "*", "8"}, equation.size() = 3.

This information gives us all the steps taken to sort the equation, each element in the array, and the equation size.
[pb, pb, pb] -> {"4", "*", "8"}, equation.size() = 3. ('pb' is short for pushback and 's' is short for skip).

## Solving Non-Parenthetic Equations

> Arguments: simplifyNonParenthetic(int lower_bound, int upper_bound, vector<string> equation)

This function is in charge of calculating simple expressions which do not contain parenthesis.

This function should never be called if the (string) input contains parenthesis...

## Solving Parenthetic Equations

> Arguments: simplifyParenthetic(vector<string> equation)

- I am stil working on the logic for this section.

This function is mainly in charge of finding parenthesis and determining when to apply the Non-Parenthetic function.

This function takes a(n) (vector) equation and determines where to begin simplification with our Non-Parenthetic function.

# Equation Interpretation Loop

The mainFunc is responsible for separating the math operators and numbers.

The loop counter 'a' begins at 0 and adds 1 until 'a' is equal to command.length(),
this loop will separate numbers and mathematical operators.

If 'a' == 0, create a new element in the dynamic array. 'pb'
If 'command.at(a)' is an operator, create a new element in the dynamic array. 'pb'
If 'command.at(a - 1)' is an operator, create a new element in the dynamic array. 'pb'
If 'a' is not an operator, and 'command.at(a - 1)' is not an operator, add character to current element. 's'

Example: Suppose somebody enters the equation '8 * 4'.

# Debug

When a user enters an equation, some useful debug information will be sent.

Example: Suppose somebody enters the equation '4 * 8'.
The debug information that will be sent will look like this: [pb, pb, pb] -> {"4", "*", "8"}, equation.size() = 3.

This information gives us all the steps taken to sort the equation, each element in the array, and the equation size.
[pb, pb, pb] -> {"4", "*", "8"}, equation.size() = 3. ('pb' is short for pushback and 's' is short for skip).

# "E.M.D.A.S." Function (Exponent, Multiplication, Division, Addition, Subtraction)

This function is in charge of calculating simple expressions.
Simple expressions are expressions which fit the following criteria:

1. For all exponential equations (e.g. "2^5-8", "2/sqrt(11+3)", "4^(2-3)+1"), the
exponent and the base of the exponent should be written as a single value.

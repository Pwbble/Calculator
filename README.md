## Libraries
> - [cmath](https://www.cplusplus.com/reference/cmath/?kw=cmath)
> - [iostream](https://www.cplusplus.com/reference/istream/iostream/?kw=iostream)
> - [vector](https://www.cplusplus.com/reference/vector/vector/?kw=vector)
## Logic
My calculator runs in steps:

1. Split the (string) equation into a bunch of tokens, which then get stored in a (string) vector.
2. Loop through the (string vector) equation.
3. If the (string vector) equation does not contain parenthesis, simplify non-parenthetically.
4. If the (string vector) equation does contain parenthesis, run several processes to determine when to apply the `simplifyNonParenthetic()` function.

The method I have chosen for this calculator is one that I formulated myself through some experimentation. I am positive this is not the first time an approach like this has been implemented into a calculator, so by no means dub me the original source of it.
## Tokenization
> `vector<string> tokenization(string input) {}`

The `tokenization()` function is responsible for splitting the (string) input into tokens. The `tokenization()` function returns a (string) vector containing the equation.

For the next part, it is important to know two things

1. `a` is an iterator looping over the (string) input.
2. An operator is anything except for a positive or negative number (+x, -x).

- If `a == 0` -> create a new element in (vector string) equation.
- If `equation[a]` is an operator -> create a new element in (vector string) equation.
- If `equation[a - 1]` is an operator -> create a new element in (vector string) equation.
- If `equation[a]` is not an operator and `equation[a - 1]` is not an operator -> add `input[a]` `to equation.at(a - skip)`.
## Non-Parenthetic Simplification
> `string simplifyNonParenthetic(int lower_bound, int upper_bound, vector<string> equation) {}`

The `simplifyNonParenthetic()` function is responsible for simplifying pieces of the (string vector) equation from lower_bound to upper_bound that do not contain parenthesis.
## Parenthetic Simplification
> `string simplifyParenthetic(vector<string> equation) {}`

Parenthetic Simplification is the default process ran if the `commandLookUp()` function is unable to classify the (string) input as a command, but rather as an equation.

If the (string vector) equation does not contain any parenthesis, then the `simplifyParenthetic()` function will return `simplifyNonParenthetic(0, equation.size(), equation)`.

If the (string vector) equation does contain parenthesis, many processes will be run to determine when to apply the `simplifyNonParenthetic()` function...

`I am not finished with the logic of this process.`
## Debug
When a user enters an equation, some useful debug information will be sent.

> Example: Suppose a user inputs the equation `4 * 8`.
>
> During the `tokenization()` process, some useful debug information will be sent that looks like this:
>
> `[pb, pb, pb] -> {"4", "*", "8"}, equation.size() = 3`.

- The steps taken to sort the equation are sent (`[pb, pb, pb]`)
- The (string vector) equation containing the equation is sent (`{"4", "*", "8"})
- And, `equation.size()` is sent.
## Text Formatting
I am working on a program 
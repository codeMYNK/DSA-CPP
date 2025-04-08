/*
A const keyword is used to declare that a variable, function or object is immutable which means we cannot change the value
throughout our program once we set it.

Compiler stores the states marked with const keyword in read-only memory which might result in faster execution.


Const keyword with pointers :
Consider the following line of code : const *int a = new int; , here the value created in the heap memory is constant
whereas the pointer a has the capacity to be reassigned.

However if we want to make the pointer constant but not the value we can write it as follows :
int *const a = new int;

If we want that both the value and the pointer stays constant, then we can write it as follows :
const int *const a = new int;
*/

#include <iostream>

using namespace std;

int main()
{

    const int x = 5; // Initialising a variable with const keyword to make it readonly.

    // x = 7; Compiler will throw an error when anyone tries to modify it.

    // int *p = &x; This is a workaround that can be used to modify const variables
    // *p = 7;      But it will only work in C based old fashioned compilers.
    cout << x << endl;
    return 0;
}
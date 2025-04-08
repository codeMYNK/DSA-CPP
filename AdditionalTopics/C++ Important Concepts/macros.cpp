/*
Macros are pre processor directives that allow us to define constants, functions or code snippets that can
be used throughout the code.
They are defined using the #define keyword and are evaluated by the pre processor before the code is compiled

Can be used for variety of purposes such as defining constants or creating shorthand for commonly used
expressions.

*/

#include <iostream>

using namespace std;
#define PI 3.1456778683 // Macros

double areaCalc(int radius)
{
    return PI * radius * radius;
}

int main()
{
    int userRadius;
    cout << "Enter the radius of the circle : " << endl;
    cin >> userRadius;
    double result = areaCalc(userRadius);
    cout << result;
    return 0;
}
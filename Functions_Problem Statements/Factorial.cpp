#include <iostream>

using namespace std;

int calcFactorial(int n)
{
    int currProd = 1;
    for (int i = n; i > 0; i--)
    {
        currProd = currProd * i;
    }
    return currProd;
}

int main()
{
    int userInput;

    cout << "Enter the number : ";
    cin >> userInput;

    int factorial = calcFactorial(userInput);

    cout << "The factorial of the number is : " << factorial << endl;
}
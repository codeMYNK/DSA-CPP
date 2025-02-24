#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int digitReverser(int n)
{
    string numToString = to_string(n);
    int length = numToString.length();
    int reversedDigit = 0;
    int op;
    for (int i = 0; i < length; i++)
    {
        int lastDigit = n % 10;
        op = pow(10, length - i - 1);
        reversedDigit = reversedDigit + (lastDigit * op);
        n = n / 10;
    }
    return reversedDigit;
}

int main()
{
    int userInput;
    cout << "Enter the number to reverse : ";
    cin >> userInput;

    int reversedNum = digitReverser(userInput);

    cout << "Your reversed number is : " << reversedNum << endl;
}
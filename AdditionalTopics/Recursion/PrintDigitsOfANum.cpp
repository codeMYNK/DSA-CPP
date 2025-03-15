#include <iostream>
#include <string.h>

using namespace std;

void digitExtractorandPrinter(int n, int length)
{
    if (length <= 1)
    {
        cout << n << " ";
        return;
    }
    cout << n % 10 << " ";
    digitExtractorandPrinter(n / 10, length - 1);
}

int main()
{
    int userInput;
    cout << "Enter the number for which you want to extract the digits : ";
    cin >> userInput;

    string numString = to_string(userInput);
    int length = numString.length();

    digitExtractorandPrinter(userInput, length);
    return 0;
}
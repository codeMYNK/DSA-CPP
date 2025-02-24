#include <iostream>

using namespace std;

void primeNumPrinter(int userInput)
{

    for (int i = 2; i <= userInput; i++)
    {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int userInput;

    cout << "Enter the number till which you want prime numbers: ";
    cin >> userInput;

    primeNumPrinter(userInput);
}
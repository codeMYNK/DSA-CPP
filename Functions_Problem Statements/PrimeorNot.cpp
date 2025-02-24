#include <iostream>

using namespace std;

bool primeChecker(int num)
{
    if (num == 0 || num == 1)
    {
        return false;
    }

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int userInput;
    cout << "Enter the number to check: ";
    cin >> userInput;

    if (primeChecker(userInput))
    {
        cout << "The input number is prime." << endl;
    }
    else
    {
        cout << "The input number is not prime." << endl;
    }

    return 0;
}

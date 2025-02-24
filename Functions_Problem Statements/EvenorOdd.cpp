#include <iostream>

using namespace std;

bool inputChecker(int num)
{
    if (num % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int userInput;

    cout << "Enter the number : ";
    cin >> userInput;

    bool result = inputChecker(userInput);

    if (result)
    {
        cout << "The given number is even" << endl;
    }
    else
    {
        cout << "The given number is odd" << endl;
    }
}
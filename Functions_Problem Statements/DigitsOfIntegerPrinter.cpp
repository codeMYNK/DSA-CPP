#include <iostream>
#include <string>

using namespace std;

void digitPrinter(int input)
{
    string inputToString = to_string(input);
    int length = inputToString.length();

    for (int i = 0; i < length; i++)
    {
        int digit = input % 10;
        cout << digit << ", ";
        input = input / 10;
    }
}

int main()
{
    int userInput;
    cout << "Enter the number : ";
    cin >> userInput;

    digitPrinter(userInput);
}
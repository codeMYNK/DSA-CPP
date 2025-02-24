#include <iostream>
#include <cmath>

using namespace std;

int digitBuilder(int builtNum, int digit, int position)
{
    int op = pow(10, position);
    return builtNum + (digit * op);
}

int inputTaker(int length)
{
    int builtNum = 0;

    for (int i = 0; i < length; i++)
    {
        int digit;
        cout << "Enter your " << i + 1 << "th digit: ";
        cin >> digit;

        builtNum = digitBuilder(builtNum, digit, length - i - 1);
    }

    return builtNum;
}

int main()
{
    int length;
    cout << "Enter the number of digits: ";
    cin >> length;

    int finalNumber = inputTaker(length);
    cout << "The constructed number is: " << finalNumber << endl;
}

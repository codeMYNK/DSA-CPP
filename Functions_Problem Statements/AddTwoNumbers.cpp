#include <iostream>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int firstNum, secondNum;

    cout << "Enter the first number" << endl;
    cin >> firstNum;

    cout << "Enter the second number" << endl;
    cin >> secondNum;

    int result = add(firstNum, secondNum);
    cout << result << endl;
    return 0;
}
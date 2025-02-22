#include <iostream>

using namespace std;

int maxNum(int firstNum, int secondNum, int thirdNum)
{
    if (firstNum > secondNum && firstNum > thirdNum)
    {
        return firstNum;
    }
    else if (secondNum > thirdNum)
    {
        return secondNum;
    }
    else
    {
        return thirdNum;
    }
}

int main()
{
    int firstNum, secondNum, thirdNum;

    cout << "Enter the first number: " << endl;
    cin >> firstNum;

    cout << "Enter the second number: " << endl;
    cin >> secondNum;

    cout << "Enter the third number : " << endl;
    cin >> thirdNum;

    int max = maxNum(firstNum, secondNum, thirdNum);

    cout << "The highest number in your provided input is : " << max << endl;
}
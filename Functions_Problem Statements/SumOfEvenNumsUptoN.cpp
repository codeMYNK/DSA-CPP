#include <iostream>

using namespace std;

int sumOfEvenNums(int maxLimit)
{
    int currSum = 0;

    for (int flag = 0; flag <= maxLimit; flag++)
    {
        if (flag % 2 == 0)
        {
            currSum = currSum + flag;
        }
        else
        {
            continue;
        }
    }
    return currSum;
}

int main()
{
    int userLimit;

    cout << "Enter your limit : " << endl;
    cin >> userLimit;

    int evenNumSum = sumOfEvenNums(userLimit);

    cout << "The total sum of even numbers only is : " << evenNumSum << endl;
}
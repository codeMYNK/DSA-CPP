#include <iostream>

using namespace std;

int squareRootFinder(int x)
{
    if (x == 0)
    {
        return 0;
    }
    if (x == 1)
    {
        return 1;
    }
    int start = 2;
    int end = x / 2;
    int ans = 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid * mid == x)
        {
            return mid;
        }
        if (mid * mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int userNum;

    cout << "Enter the number to find the square root : ";
    cin >> userNum;

    int squareRoot = squareRootFinder(userNum);
    int precision;
    cout << "Enter the number of floating digits you want in your ans : ";
    cin >> precision;

    double step = 0.1;
    double finalAns = squareRoot;

    for (int i = 0; i < precision; i++)
    {
        for (double j = finalAns; j * j <= userNum; j = j + step)
        {
            finalAns = j;
        }
        step = step / 10;
    }

    cout << "The square root of " << userNum << " is " << finalAns;
}
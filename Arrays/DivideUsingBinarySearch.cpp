#include <iostream>
#include <cmath>

using namespace std;

int solve(int dividend, int divisor)
{
    if (divisor == 0)
    {
        cout << "Error: Division by zero is undefined!" << endl;
        return -1;
    }

    int start = 0;
    int end = abs(dividend);
    int ans = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (abs(mid * divisor) == abs(dividend))
        {
            ans = mid;
            break;
        }
        if (abs(mid * divisor) < abs(dividend))
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }

    if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
    {
        return ans;
    }
    else
    {
        return -ans;
    }
}

int main()
{
    int dividend, divisor;

    cout << "Enter the number you want to divide : ";
    cin >> dividend;

    cout << "Enter the number you want to divide by : ";
    cin >> divisor;

    int result = solve(dividend, divisor);

    int precision;
    cout << "Enter the number of floating digits you want in your ans : ";
    cin >> precision;

    double step = 0.1;
    double finalAns = result;

    for (int i = 0; i < precision; i++)
    {
        for (double j = finalAns; j * divisor <= dividend; j += step)
        {
            finalAns = j;
        }
        step /= 10;
    }

    cout << "The division of " << dividend << " with " << divisor << " is " << finalAns << endl;

    return 0;
}
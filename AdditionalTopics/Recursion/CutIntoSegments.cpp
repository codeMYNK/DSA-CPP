#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int solve(int n, int x, int y, int z)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }

    int ans1 = solve(n - x, x, y, z) + 1;
    int ans2 = solve(n - y, x, y, z) + 1;
    int ans3 = solve(n - z, x, y, z) + 1;

    return max(ans1, max(ans2, ans3));
}

int main()
{
    int rodLength, segmentCalc1, segmentCalc2, segmentCalc3;

    cout << "Enter the rod length : ";
    cin >> rodLength;

    cout << "Enter the first acceptable segment value: ";
    cin >> segmentCalc1;

    cout << "Enter the second acceptable segment value: ";
    cin >> segmentCalc2;

    cout << "Enter the third acceptable segment value: ";
    cin >> segmentCalc3;

    int result = solve(rodLength, segmentCalc1, segmentCalc2, segmentCalc3);

    if (result < 0)
    {
        result = 0;
    }

    cout << "The maximum number of segments possible are : " << result << endl;
}
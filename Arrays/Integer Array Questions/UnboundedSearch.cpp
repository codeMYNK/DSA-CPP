#include <iostream>
using namespace std;

bool f(int x)
{
    return x >= 10;
}

int unboundedBinarySearch()
{
    int bound = 1;

    while (!f(bound))
    {
        bound *= 2;
    }

    int start = bound / 2, end = bound, ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (f(mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    cout << "First occurrence of f(x) == true is at x = " << unboundedBinarySearch();
}

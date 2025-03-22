#include <iostream>
#include <limits.h>
#include <math.h>

using namespace std;

class Solution
{
public:
    int numSquaresHelper(int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;

        int endPoint = sqrt(n);
        int i = 1;
        int ans = INT_MAX;
        while (i <= endPoint)
        {
            int perfectSquare = i * i;
            int numOfPerfectSquares = 1 + numSquaresHelper(n - perfectSquare);
            if (numOfPerfectSquares < ans)
            {
                ans = numOfPerfectSquares;
            }
            ++i;
        }
        return ans;
    }
    int numSquares(int n)
    {
        return numSquaresHelper(n) - 1;
    }
};
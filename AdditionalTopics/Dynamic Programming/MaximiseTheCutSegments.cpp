// GfG Problem - Maximise The Cut Segments(Medium)

/*
Given an integer n denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum. Return the maximum number of cut segments possible.

Note: if no segment can be cut then return 0.

Examples:

Input: n = 4, x = 2, y = 1, z = 1
Output: 4
Explanation: Total length is 4, and the cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1.
Input: n = 5, x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and the cut lengths are 5, 3 and 2. We can make two segments of lengths 3 and 2.
Input: n = 7, x = 8, y = 9, z = 10
Output: 0
Explanation: Here the total length is 7, and the cut lengths are 8, 9, and 10. We cannot cut the segment into lengths that fully utilize the segment, so the output is 0.
Constraints
1 <= n, x, y, z <= 104


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int solveBottomUp(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, INT_MIN);

        dp[0] = 0;
        if (n < 0)
            return INT_MIN;

        for (int i = 1; i <= n; i++)
        {
            if (i - x >= 0)
                dp[i] = max(dp[i], dp[i - x] + 1);
            if (i - y >= 0)
                dp[i] = max(dp[i], dp[i - y] + 1);
            if (i - z >= 0)
                dp[i] = max(dp[i], dp[i - z] + 1);
        }

        if (dp[n] < 0)
            return 0;
        else
            return dp[n];
    }
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {

        return solveBottomUp(n, x, y, z);
    }
};
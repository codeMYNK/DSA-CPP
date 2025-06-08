// GfG Problem : Check if it is possible to Survive on Island(Easy)

/*
ays, or determine that it isn’t possible to survive.

Example 1:

Input: S = 10, N = 16, M = 2
Output: 2
Explaination: One possible solution is to
buy a box on the first day (Monday),
it’s sufficient to eat from this box up to
8th day (Monday) inclusive. Now, on the 9th
day (Tuesday), you buy another box and use
the chocolates in it to survive the 9th and
10th day.
Example 2:

Input: S = 10, N = 9, M = 8
Output: -1
Explaination: Let's start by detailing the days of the week and the net number of food units available after purchasing and consuming them:
Monday - Net 1 food unit available.
Tuesday - Net 2 food units available.
Wednesday - Net 3 food units available.
Thursday - Net 4 food units available.
Friday - Net 5 food units available.
Saturday - Net 6 food units available.
Sunday - 6 food units available and that is not sufficient amount of food units to survive and you can't buy more on Sunday.
Your Task:
You do not need to read input or print anything. Your task is to complete the function minimumDays() which takes S, N, and M as input parameters and returns the minimum number of days Geekina needs to buy food. Otherwise, returns -1 if she cannot survive.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N, S ≤ 50
1 ≤ M ≤ 30
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        if (((N * 6) < (M * 7) && S > 6) || M > N)
            return -1;
        else
        {
            int days = (M * S) / N;
            if (((M * S) % N) != 0)
                days++;
            return days;
        }
    }
};

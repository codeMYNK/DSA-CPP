// Leetcode Problem No : 354 - Russian Doll Envelopes(Hard)

/*
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.



Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1


Constraints:

1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi, hi <= 105
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int val = envelopes[i][1];
            int index = lower_bound(ans.begin(), ans.end(), val) - ans.begin();
            if (index >= ans.size())
            {
                ans.push_back(val);
            }
            else
            {
                ans[index] = val;
            }
        }
        return ans.size();
    }
};
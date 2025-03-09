// Leetcode Question no 179 : Largest Number(Medium)

/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.



Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class Solution
{
public:
    static bool mycomp(string a, string b)
    {
        return a + b > b + a;
    }

    string largestNumber(vector<int> &nums)
    {
        vector<string> snums;

        for (auto n : nums)
        {
            snums.push_back(to_string(n));
        }

        sort(snums.begin(), snums.end(), mycomp);

        if (snums[0] == "0")
            return "0";

        string ans = "";
        for (auto &str : snums)
        {
            ans += str;
        }

        return ans;
    }
};

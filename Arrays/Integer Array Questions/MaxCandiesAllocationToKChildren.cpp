// Leetcode Problem No - 2226 : Maximum Candies Allocated to k children (Medium)

/*
You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.

You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.

Return the maximum number of candies each child can get.



Example 1:

Input: candies = [5,8,6], k = 3
Output: 5
Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.
Example 2:

Input: candies = [2,5], k = 11
Output: 0
Explanation: There are 11 children but only 7 candies in total, so it is impossible to ensure each child receives at least one candy. Thus, each child gets no candy and the answer is 0.


Constraints:

1 <= candies.length <= 105
1 <= candies[i] <= 107
1 <= k <= 1012
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool validate(vector<int> &arr, int maxValue, int totalChildren)
{

    int currNoOfChildren = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        currNoOfChildren = currNoOfChildren + arr[i] / maxValue;
    }
    return currNoOfChildren >= totalChildren;
}

int findMaxinPile(vector<int> &arr, int totalChildren)
{
    int start = 1;
    int end = *max_element(arr.begin(), arr.end());
    int ans = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (validate(arr, mid, totalChildren))
        {
            ans = mid;
            start = mid + 1;
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
    int noOfPiles, totalNoOfChildren;

    cout << "Enter the number of piles of candies you have : ";
    cin >> noOfPiles;

    vector<int> candies(noOfPiles);

    cout << "Enter the total number of candies in each pile : " << endl;
    for (int i = 0; i < noOfPiles; i++)
    {
        cin >> candies[i];
    }

    cout << "Enter the total number of children present : ";
    cin >> totalNoOfChildren;

    cout << "The maximum no of candies that can be allocated to the " << totalNoOfChildren << " are: " << findMaxinPile(candies, totalNoOfChildren) << endl;
}
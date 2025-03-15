// Leetcode Problem No : 204 - Count Primes(Medium)

/*
Given an integer n, return the number of prime numbers that are strictly less than n.



Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0


Constraints:

0 <= n <= 5 * 106
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0)
            return 0;

        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;

        int ans = 0;

        for (int i = 2; i * i <= n; i++)
        {
            if (prime[i])
            {
                ans++;
                int j = i * i;
                while (j < n)
                {
                    prime[j] = false;
                    j += i;
                }
            }
        }
        return ans;
    }
};
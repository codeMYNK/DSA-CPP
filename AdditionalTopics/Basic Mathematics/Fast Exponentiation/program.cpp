#include <iostream>

using namespace std;

class Solution
{
public:
    int fastExponentiation(int a, int b)
    {
        int ans = 1;
        while (b > 0)
        {
            if (b & 1)
            { // checking for odd
                ans = ans * a;
            }
            a = a * a;
            b >>= 1;
        }
        return ans;
    }
};
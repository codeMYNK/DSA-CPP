// gcd(a,b) = gcd(a - b, b) if(a > b) else gcd(b - a, a) if(b > a) - Euclid's optimal approach to find GCD
// LCM = (a * b)/gcd
// LCM * GCD = a * b

#include <iostream>

using namespace std;

class Solution
{
public:
    int gcd(int A, int B)
    {
        if (A == 0)
            return B;
        if (B == 0)
            return A;

        while (A > 0 && B > 0)
        {
            if (A > B)
            {
                A = A - B;
            }
            else
            {
                B = B - A;
            }
        }
        return A == 0 ? B : A;
    }
};
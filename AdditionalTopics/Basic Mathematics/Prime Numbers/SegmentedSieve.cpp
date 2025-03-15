#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> findSievefrombase(int n)
{
    vector<bool> userSieve(n + 1, true);

    userSieve[0] = userSieve[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (userSieve[i])
        {
            int j = i * i;

            while (j < n)
            {
                userSieve[j] = false;
                j += i;
            }
        }
    }
    return userSieve;
}

vector<bool> segmentSieve(int lowerBound, int upperBound)
{
    vector<bool> baseSieve = findSievefrombase(sqrt(upperBound));
    vector<int> basePrimes;

    for (int i = 0; i < baseSieve.size(); i++)
    {
        if (baseSieve[i])
        {
            basePrimes.push_back(i);
        }
    }

    vector<bool> segSieve(upperBound - lowerBound + 1, true);

    if (lowerBound == 0 || lowerBound == 1)
    {
        segSieve[lowerBound] == false;
    }

    for (auto prime : basePrimes)
    {
        int first_mul = (lowerBound / prime) * prime;

        if (first_mul < lowerBound)
        {
            first_mul += prime;
        }
        int j = max(first_mul, prime * prime);

        while (j <= upperBound)
        {
            segSieve[j - lowerBound] = false;
            j += prime;
        }
    }
    return segSieve;
}

int main()
{
    int L, R;

    cout << "Enter the lowerbound for your prime number search : ";
    cin >> L;

    cout << "Enter the upperbound for your prime number search : ";
    cin >> R;

    vector<bool> result = segmentSieve(L, R);

    for (int i = 0; i < result.size(); i++)
    {
        if (result[i])
        {
            cout << i + L << " ";
        }
    }
    return 0;
}
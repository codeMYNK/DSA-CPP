// Codeforces Problem No: 240-B : T- Primes

/*
T-primes
time limit per test 2 seconds
memory limit per test 256 megabytes
We know that prime numbers are positive integers that have exactly two distinct positive divisors. Similarly, we'll call a positive integer t Т-prime, if t has exactly three distinct positive divisors.

You are given an array of n positive integers. For each of them determine whether it is Т-prime or not.

Input
The first line contains a single positive integer, n (1 ≤ n ≤ 105), showing how many numbers are in the array. The next line contains n space-separated integers xi (1 ≤ xi ≤ 1012).

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is advised to use the cin, cout streams or the %I64d specifier.

Output
Print n lines: the i-th line should contain "YES" (without the quotes), if number xi is Т-prime, and "NO" (without the quotes), if it isn't.

Examples
3
4 5 6

YES
NO
NO

Note
The given test has three numbers. The first number 4 has exactly three divisors — 1, 2 and 4, thus the answer for this number is "YES". The second number 5 has two divisors (1 and 5), and the third number 6 has four divisors (1, 2, 3, 6), hence the answer for them is "NO".
*/

/*
Approach :
Step 1 : Precompute the prime numbers until 10^6
Step 2 : Apply the checks for T-primes
Step 3 : Return the output
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> primePreComputation(int n)
{
    vector<bool> userSieve(n + 1, true);
    userSieve[0] = userSieve[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (userSieve[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                userSieve[j] = false;
            }
        }
    }
    return userSieve;
}

vector<bool> outputReturn(vector<int> &arr)
{
    int maxNum = 1000000;
    vector<bool> preComputedSieve = primePreComputation(maxNum);
    vector<bool> outputArr(arr.size(), false);

    for (int i = 0; i < arr.size(); i++)
    {
        int num = arr[i];

        if (num < 4)
        {
            outputArr[i] = false;
            continue;
        }

        int sqrtNum = sqrt(num);
        if (1LL * sqrtNum * sqrtNum == num && preComputedSieve[sqrtNum])
        {
            outputArr[i] = true;
        }
    }
    return outputArr;
}

int main()
{
    int userLength;

    cout << "Enter the length of the array : ";
    cin >> userLength;

    vector<int> userArr(userLength);

    cout << "Enter the array elements : " << endl;
    for (int i = 0; i < userLength; i++)
    {
        cin >> userArr[i];
    }

    vector<bool> result = outputReturn(userArr);

    for (int i = 0; i < result.size(); i++)
    {
        if (result[i])
        {
            cout << "Yes" << " ";
        }
        else
        {
            cout << "No" << " ";
        }
    }
}
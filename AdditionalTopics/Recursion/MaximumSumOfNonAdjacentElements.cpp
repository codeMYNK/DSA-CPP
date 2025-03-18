#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int solve(vector<int> &arr, int sum, int &maxi, int &i)
{
    if (i >= arr.size())
    {
        maxi = max(sum, maxi);
        return maxi;
    }

    int counterinInclusion = i + 2;
    int counterinExclusion = i + 1;
    solve(arr, sum, maxi, counterinInclusion);

    solve(arr, sum, maxi, counterinExclusion);
}

int main()
{
    int userLength;
    cout << "Enter the length of the array : ";
    cin >> userLength;

    vector<int> userArr(userLength);
    cout << "Enter the elements of the array : " << endl;

    for (int i = 0; i < userLength; i++)
    {
        cin >> userArr[i];
    }

    int sum = 0;
    int maxi = INT_MIN;
    int counter = 0;

    int result = solve(userArr, sum, maxi, counter);

    cout << "The maximum sum of non adjacent elements of the provided array are : " << result << endl;

    return 0;
}
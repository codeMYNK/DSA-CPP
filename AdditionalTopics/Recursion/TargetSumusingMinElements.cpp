#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solve(vector<int> &arr, int target)
{
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = solve(arr, target - arr[i]);
        if (ans != INT_MAX)
        {
            mini = min(ans + 1, mini);
        }
    }

    return mini;
}

int main()
{
    int userLength;
    cout << "Enter the length of the array : ";
    cin >> userLength;

    vector<int> userArr(userLength);
    int target;
    cout << "Enter the elements of the array : " << endl;

    for (int i = 0; i < userLength; i++)
    {
        cin >> userArr[i];
    }

    cout << "Enter the target value : " << endl;
    cin >> target;

    int ans = solve(userArr, target);

    cout << "The ans is : " << ans << endl;

    return 0;
}
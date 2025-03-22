#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxCashFinder(vector<int> &nums, int i)
{
    if (i >= nums.size())
    {
        return 0;
    }
    int robAmount1 = nums[i] + maxCashFinder(nums, i + 2);
    int robAmount2 = 0 + maxCashFinder(nums, i + 1);
    return max(robAmount1, robAmount2);
}

int main()
{
    int userLength;
    cout << "Enter the length of the array : ";
    cin >> userLength;

    vector<int> userArr(userLength);

    cout << "Enter the cash present in each house : " << endl;

    for (int i = 0; i < userLength; i++)
    {
        cin >> userArr[i];
    }

    int counter = 0;

    int maxCashRobbed = maxCashFinder(userArr, counter);

    cout << "The maximum cash that can be robbed is : " << maxCashRobbed << endl;

    return 0;
}
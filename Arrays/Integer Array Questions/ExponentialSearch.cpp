#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getBoundsForBS(const vector<int> &arr, int target)
{
    int bound = 1;

    while (bound < arr.size() && arr[bound] < target)
    {
        bound *= 2;
    }

    return {bound / 2, min(bound, (int)arr.size() - 1)};
}

int binarySearchOnBounds(const vector<int> &arr, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int userLength, userTarget;

    cout << "Enter the length of the array: ";
    cin >> userLength;

    vector<int> userArr(userLength);

    cout << "Enter the elements of the array (sorted): " << endl;
    for (int i = 0; i < userLength; i++)
    {
        cin >> userArr[i];
    }

    cout << "Enter the target value you want to search: ";
    cin >> userTarget;

    vector<int> bounds = getBoundsForBS(userArr, userTarget);
    int lowerBound = bounds[0];
    int upperBound = bounds[1];

    int searchResult = binarySearchOnBounds(userArr, userTarget, lowerBound, upperBound);

    if (searchResult == -1)
    {
        cout << "The searched element " << userTarget << " is not present in the array." << endl;
    }
    else
    {
        cout << "The searched element " << userTarget << " is present at position " << searchResult + 1 << " in the array." << endl;
    }
}

#include <iostream>
#include <vector>

using namespace std;

int binarySearchinNearlySortedArray(const vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (mid + 1 < arr.size() && arr[mid + 1] == target)
        {
            return mid + 1;
        }
        if (mid - 1 >= 0 && arr[mid - 1] == target)
        {
            return mid - 1;
        }
        if (target > arr[mid])
        {
            start = mid + 2;
        }
        else
        {
            end = mid - 2;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr{10, 3, 40, 20, 50, 80, 70};
    int target;

    cout << "Enter the target value : ";
    cin >> target;

    int searchResult = binarySearchinNearlySortedArray(arr, target);

    if (searchResult == -1)
    {
        cout << "The element is not found." << endl;
    }
    else
    {
        cout << "The target " << target << " is present at " << searchResult + 1 << "th position." << endl;
    }
}
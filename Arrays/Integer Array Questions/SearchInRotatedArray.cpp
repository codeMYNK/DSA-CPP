// Leetcode Problem no 33:Search in Rotated Sorted Array (Medium)

#include <iostream>
#include <vector>

using namespace std;

int findPivot(const vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid < arr.size() - 1 && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        if (mid > 0 && arr[mid - 1] > arr[mid])
        {
            return mid - 1;
        }

        if (arr[start] <= arr[mid])
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

int binarySearch(const vector<int> &arr, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int searchInRotatedArray(const vector<int> &arr, int target)
{
    int n = arr.size();
    if (n == 0)
    {
        return -1;
    }

    int pivot = findPivot(arr);

    if (pivot == -1)
    {
        return binarySearch(arr, 0, n - 1, target);
    }

    if (arr[pivot] == target)
    {
        return pivot;
    }

    if (target >= arr[0])
    {
        return binarySearch(arr, 0, pivot, target);
    }

    return binarySearch(arr, pivot + 1, n - 1, target);
}

int main()
{
    int userLength, userTarget;

    cout << "Enter the length of the array : ";
    cin >> userLength;

    vector<int> userArr(userLength);

    cout << "Enter the elements in the array : " << endl;
    for (int i = 0; i < userLength; i++)
    {
        cin >> userArr[i];
    }

    cout << "Enter the value you want to search : ";
    cin >> userTarget;

    int searchIndex = searchInRotatedArray(userArr, userTarget);

    if (searchIndex == -1)
    {
        cout << "The target element was not found in the array." << endl;
    }
    else
    {
        cout << "The target element was found at index " << searchIndex << "." << endl;
    }

    return 0;
}

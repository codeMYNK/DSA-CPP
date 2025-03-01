#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int> &arr, int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int element = arr[mid];

        if (element == target)
        {
            return mid;
        }
        else if (target < element)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int userLength, targetValue;

    cout << "Enter the length of array : ";
    cin >> userLength;

    vector<int> userArr(userLength);

    cout << "Enter the array elements : " << endl;
    for (int i = 0; i < userLength; i++)
    {
        cin >> userArr[i];
    }

    cout << "Enter the target value: ";
    cin >> targetValue;

    int indexOfTarget = binarySearch(userArr, userLength, targetValue);

    if (indexOfTarget == -1)
    {
        cout << "The element is not present in the array." << endl;
    }
    else
    {
        cout << "The element is present at " << indexOfTarget + 1 << "th position." << endl;
    }
}
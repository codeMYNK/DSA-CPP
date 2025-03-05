#include <iostream>
#include <vector>

using namespace std;

int pivotElementFinder(const vector<int> &arr, int arrLength)
{
    int start = 0;
    int end = arrLength - 1;

    if (arr[start] <= arr[end])
        return arr[end];

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid < arrLength - 1 && arr[mid] > arr[mid + 1])
            return arr[mid];
        if (mid > 0 && arr[mid] < arr[mid - 1])
            return arr[mid - 1];

        if (arr[mid] >= arr[start])
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
    int userArrayLength;

    cout << "Enter the length of the array: ";
    cin >> userArrayLength;

    vector<int> userArr(userArrayLength);

    cout << "Enter the elements: ";
    for (int i = 0; i < userArrayLength; i++)
    {
        cin >> userArr[i];
    }

    int pivotElement = pivotElementFinder(userArr, userArrayLength);

    if (pivotElement == -1)
    {
        cout << "No pivot element found" << endl;
    }
    else
    {
        cout << "The pivot element is: " << pivotElement << endl;
    }

    return 0;
}
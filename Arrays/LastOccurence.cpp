#include <iostream>
#include <vector>

using namespace std;

int lastOccurenceFinder(vector<int> arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    int result = -1;

    while (start <= end)
    {
        if (arr[mid] == target)
        {
            result = mid;
            start = mid + 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return result;
}

int main()
{
    int userLength, targetVal;

    cout << "Enter the length of the array: ";
    cin >> userLength;

    vector<int> userArr(userLength);

    cout << "Enter the elements of the array : " << endl;

    for (int i = 0; i < userLength; i++)
    {
        cin >> userArr[i];
    }

    cout << "Enter the target value: ";
    cin >> targetVal;

    int lastOccurence = lastOccurenceFinder(userArr, targetVal);

    if (lastOccurence == -1)
    {
        cout << "The element is not present in the array." << endl;
    }
    else
    {
        cout << "The last occurence of the element is at: " << lastOccurence + 1 << "th position" << endl;
    }
}
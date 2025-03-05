#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    int arraySize;
    cout << "Enter the Array Size : ";
    cin >> arraySize;

    vector<int> arr(arraySize);
    vector<int> arr2;
    int firstElement = INT_MIN;

    cout << "Enter the array elements : ";
    for (int i = 0; i < arraySize; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < arraySize; i++)
    {
        if (i == 0)
        {
            firstElement = arr[i];
        }
        else
        {
            arr2.push_back(arr[i]);
        }
    }

    arr2.push_back(firstElement);

    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
}
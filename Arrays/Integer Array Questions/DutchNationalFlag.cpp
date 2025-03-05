#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arrayLength;
    cout << "Enter the length of the array : ";
    cin >> arrayLength;

    vector<int> arr(arrayLength);

    cout << "Enter the values(only 0s and 1s) : " << endl;
    for (int i = 0; i < arrayLength; i++)
    {
        cin >> arr[i];
    }

    int start = 0;
    int end = arrayLength - 1;
    int i = 0;

    while (start <= end)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[start]);
            i++;
            start++;
        }
        else
        {
            swap(arr[i], arr[end]);
            end--;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
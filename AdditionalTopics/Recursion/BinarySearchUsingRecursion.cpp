#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int &k, int &start, int &end)
{
    if (start > end)
    {
        return -1;
    }
    int mid = start + (end - start) / 2;

    if (arr[mid] == k)
    {
        return mid;
    }
    if (arr[mid] < k)
    {
        start = mid + 1;
        return binarySearch(arr, k, start, end);
    }
    else
    {
        end = mid - 1;
        return binarySearch(arr, k, start, end);
    }
}

int main()
{

    int userLength;
    cout << "Enter the length of the array : ";
    cin >> userLength;

    vector<int> userArr(userLength);

    cout << "Enter the array elements : " << endl;

    for (int i = 0; i < userLength; i++)
    {
        cin >> userArr[i];
    }
    int start = 0;
    int end = userLength - 1;
    int userKey;
    cout << "Enter the key you want to search : ";
    cin >> userKey;

    int result = binarySearch(userArr, userKey, start, end);

    if (result == -1)
    {
        cout << "Key not found in the array." << endl;
    }
    else
    {
        cout << "The key is present at " << result + 1 << "th place in the array";
    }
}
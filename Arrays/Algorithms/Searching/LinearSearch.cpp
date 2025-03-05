#include <iostream>

using namespace std;

bool linearSearch(int arr[], int length, int key)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[5] = {2, 10, 5, 7, 9};

    int userKey;
    cout << "Enter the key you want to search : " << endl;
    cin >> userKey;

    bool isPresent = linearSearch(arr, 5, userKey);

    if (isPresent)
    {
        cout << "The key is present in the array." << endl;
    }
    else
    {
        cout << "The key is not present in the array." << endl;
    }
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int length;

    cout << "Enter the length of the array : ";
    cin >> length;

    vector<int> arr(length);

    cout << "Enter the elements(only 0/1/2's): " << endl;

    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j], arr[i]);
            }
        }
    }

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}
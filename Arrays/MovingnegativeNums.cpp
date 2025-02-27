#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int userLength;

    cout << "Enter the length of the array : ";
    cin >> userLength;

    vector<int> arr(userLength);

    cout << "Enter the elements of the array : " << endl;

    for (int i = 0; i < userLength; i++)
    {
        cin >> arr[i];
    }

    int j = userLength - 1;
    int i = 0;

    while (i < j)
    {
        if (arr[i] < 0)
        {
            if (arr[j] > 0)
            {
                swap(arr[i], arr[j]);
            }
            j--;
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < userLength; i++)
    {
        cout << arr[i] << " ";
    }
}
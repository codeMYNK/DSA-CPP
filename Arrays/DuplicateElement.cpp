#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int userLength;

    cout << "Enter the length of the array : ";
    cin >> userLength;

    vector<int> arr(userLength);

    cout << "Enter the elements: " << endl;
    for (int input = 0; input < userLength; input++)
    {
        cin >> arr[input];
    }
    int duplicateItem = 0;
    for (int i = 0; i < userLength; i++)
    {
        for (int j = userLength - 1; j > i; j--)
        {
            if (arr[i] == arr[j])
            {
                duplicateItem = arr[i];
                break;
            }
        }
    }
    if (duplicateItem == 0)
    {
        cout << "No duplicate elements found in your input." << endl;
    }
    else
    {
        cout << "The first duplicate element is : " << duplicateItem << endl;
    }
}
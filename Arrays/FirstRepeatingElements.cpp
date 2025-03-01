#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int userLength;
    cout << "Enter the array length: ";
    cin >> userLength;

    vector<int> arr(userLength);
    cout << "Enter the array elements: " << endl;

    for (int i = 0; i < userLength; i++)
    {
        cin >> arr[i];
    }

    int repeatingElement = 0;
    bool found = false;

    for (int i = 0; i < userLength; i++)
    {
        for (int j = i + 1; j < userLength; j++)
        {
            if (arr[i] == arr[j])
            {
                repeatingElement = arr[i];
                found = true;
                break;
            }
            if (found)
            {
                break;
            }
        }
    }

    if (repeatingElement != 0)
    {
        cout << "The first repeating element in the array is : " << repeatingElement << endl;
    }
    else
    {
        cout << "No repeating element was found!" << endl;
    }
}
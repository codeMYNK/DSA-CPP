#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int arraySizeOne, arraySizeTwo;

    cout << "Enter the size of the 1st Array: ";
    cin >> arraySizeOne;
    cout << "Enter the size of the 2nd Array:  ";
    cin >> arraySizeTwo;

    vector<int> arr1(arraySizeOne);
    vector<int> arr2(arraySizeTwo);
    vector<int> intersected;

    cout << "Enter the elements of 1st Array : " << endl;
    for (int i = 0; i < arraySizeOne; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the elements of 2nd Array : " << endl;
    for (int i = 0; i < arraySizeTwo; i++)
    {
        cin >> arr2[i];
    }

    for (int i = 0; i < arraySizeOne; i++)
    {
        bool isSame = false;
        for (int j = 0; j < arraySizeTwo; j++)
        {
            if (arr1[i] == arr2[j])
            {
                isSame = true;
                break;
            }
        }
        if (isSame)
        {
            // Check to avoid adding duplicates
            if (find(intersected.begin(), intersected.end(), arr1[i]) == intersected.end())
            {
                intersected.push_back(arr1[i]);
            }
        }
    }

    cout << "The intersected elements of the two arrays are : ";
    for (int i = 0; i < intersected.size(); i++)
    {
        cout << intersected[i] << " ";
    }
}
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int userLengthOne, userLengthTwo, userLengthThree;

    cout << "Enter the length of the first array: ";
    cin >> userLengthOne;
    cout << "Enter the length of the second array: ";
    cin >> userLengthTwo;
    cout << "Enter the length of third array: ";
    cin >> userLengthThree;

    vector<int> arr1(userLengthOne);
    vector<int> arr2(userLengthTwo);
    vector<int> arr3(userLengthThree);

    cout << "Enter the elements of first array: ";
    for (int i = 0; i < userLengthOne; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the elements of second array: ";
    for (int i = 0; i < userLengthTwo; i++)
    {
        cin >> arr2[i];
    }

    cout << "Enter the elements of third array: ";
    for (int i = 0; i < userLengthThree; i++)
    {
        cin >> arr3[i];
    }

    vector<int> commonElements;

    for (int i = 0; i < userLengthOne; i++)
    {
        bool foundInSecond = false, foundInThird = false;

        for (int j = 0; j < userLengthTwo; j++)
        {
            if (arr1[i] == arr2[j])
            {
                foundInSecond = true;
                break;
            }
        }

        for (int k = 0; k < userLengthThree; k++)
        {
            if (arr1[i] == arr3[k])
            {
                foundInThird = true;
                break;
            }
        }

        if (foundInSecond && foundInThird)
        {
            bool alreadyAdded = false;
            for (int x : commonElements)
            {
                if (x == arr1[i])
                {
                    alreadyAdded = true;
                    break;
                }
            }
            if (!alreadyAdded)
            {
                commonElements.push_back(arr1[i]);
            }
        }
    }

    if (commonElements.empty())
    {
        cout << "No common elements found!" << endl;
    }
    else
    {
        cout << "The common elements in the 3 arrays are: ";
        for (int element : commonElements)
        {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int arraySize;

    cout << "Enter the size of the array : ";
    cin >> arraySize;

    vector<int> arr(arraySize);
    vector<int> elements;
    int bigger = INT_MIN;
    int biggerIndex;

    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < arraySize; i++)
    {
        int temp = 0;
        for (int j = i + 1; j < arraySize; j++)
        {
            if (arr[j] == arr[i])
            {
                temp++;
            }
        }
        elements.push_back(temp);
    }

    for (int i = 0; i < elements.size(); i++)
    {
        if (elements[i] > bigger)
        {
            bigger = elements[i];
            biggerIndex = i;
        }
    }

    cout << "The element that has occured the most is " << arr[biggerIndex] << " " << ", it has occured " << bigger + 1 << " times." << endl;
}
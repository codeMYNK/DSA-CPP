#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arrayLength;
    bool op = false;
    cout << "Enter the length of the array : ";
    cin >> arrayLength;

    int value;
    cout << "Enter the value for which you want to search the pair : ";
    cin >> value;

    vector<int> arr(arrayLength);
    for (int i = 0; i < arrayLength; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < arrayLength; i++)
    {
        for (int j = i + 1; j < arrayLength; j++)
        {
            if (arr[i] + arr[j] == value)
            {
                cout << "The pair that satisifies the value is : " << "(" << arr[i] << ", " << arr[j] << ")" << endl;
                op = true;
            }
        }
    }
    if (!op)
    {
        cout << "Sorry I cannot find any pair that will satisify the underlined value";
    }
}
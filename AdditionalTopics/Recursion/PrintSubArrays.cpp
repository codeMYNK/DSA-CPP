#include <iostream>
#include <vector>

using namespace std;

void subArrayFinder_util(vector<int> &arr, int i, int j)
{
    if (j == arr.size())
    {
        return;
    }

    for (int z = 0; z <= j; z++)
    {
        cout << arr[z] << " ";
    }
    cout << endl;

    subArrayFinder_util(arr, i, j + 1);
}

void subArrayFinder(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int j = i;
        subArrayFinder_util(arr, i, j);
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
    int startPointer = 0;
    int elementPrintingPointer = 0;

    subArrayFinder(userArr);

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int s, int e)
{
    // Step 1: Choose pivot element
    int pivotIndex = s;
    int pivotElement = arr[pivotIndex];

    // Step 2: Find right position for pivot and place it there
    int count = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < pivotElement)
        {
            count++;
        }
    }
    int correctIndex = count + s;
    swap(arr[pivotIndex], arr[correctIndex]);
    pivotIndex = correctIndex;
    // Step 3 : Ensuring that the values less then the pivot index should be on the left and greater on the right
    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivotElement)
        {
            i++;
        }
        while (arr[j] > pivotElement)
        {
            j--;
        }

        // There will be 2 cases

        // A. Swapping Case
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
        // B. No swap case
    }
    return pivotIndex;
}

void quickSort(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    // partition logic
    int p = partition(arr, s, e);

    // recursive calls
    // left
    quickSort(arr, s, p - 1);
    // right
    quickSort(arr, p + 1, e);
}

int main()
{
    int userLength;
    cout << "Enter the length of the array : ";
    cin >> userLength;

    vector<int> userArr(userLength);
    cout << "Enter the elements : " << endl;
    for (int i = 0; i < userLength; i++)
    {
        cin >> userArr[i];
    }
    int start = 0;
    int end = userLength - 1;
    quickSort(userArr, start, end);
    cout << "The sorted array is : " << endl;
    for (int i = 0; i < userLength; i++)
    {
        cout << userArr[i] << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    vector<int> leftArr(len1, 0);
    vector<int> rightArr(len2, 0);

    int k = s;
    for (int i = 0; i < len1; i++)
    {
        leftArr[i] = arr[k];
        k++;
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        rightArr[i] = arr[k];
        k++;
    }

    // merge logic

    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrIndex = s;

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (leftArr[leftIndex] < rightArr[rightIndex])
        {
            arr[mainArrIndex++] = leftArr[leftIndex++];
        }
        else
        {
            arr[mainArrIndex++] = rightArr[rightIndex++];
        }
    }

    // copy logic for left and right arrays :

    while (leftIndex < len1)
    {
        arr[mainArrIndex++] = leftArr[leftIndex++];
    }

    while (rightIndex < len2)
    {
        arr[mainArrIndex++] = rightArr[rightIndex++];
    }
}

void mergeSort(vector<int> &arr, int s, int e)
{

    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    // left part
    mergeSort(arr, s, mid);

    // right part
    mergeSort(arr, mid + 1, e);

    // merging the arrays
    merge(arr, s, e);
}

int main()
{
    int userLength;
    cout << "Enter the length of the array : ";
    cin >> userLength;

    vector<int> userArr(userLength);

    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < userLength; i++)
    {
        cin >> userArr[i];
    }

    int start = 0;
    int end = userLength - 1;

    mergeSort(userArr, start, end);

    for (int i = 0; i < userLength; i++)
    {
        cout << userArr[i] << " ";
    }

    return 0;
}
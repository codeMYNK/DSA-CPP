#include <iostream>
#include <vector>

using namespace std;

void mergeInPlace(vector<int> &arr, int start, int mid, int end)
{
    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            left++;
        }
        else
        {

            int temp = arr[right];
            for (int i = right; i > left; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[left] = temp;

            left++;
            mid++;
            right++;
        }
    }
}

void mergeSortInPlace(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    mergeSortInPlace(arr, start, mid);
    mergeSortInPlace(arr, mid + 1, end);

    mergeInPlace(arr, start, mid, end);
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSortInPlace(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

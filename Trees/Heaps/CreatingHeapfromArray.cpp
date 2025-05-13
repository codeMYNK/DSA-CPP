#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int index = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;
    int largest = index;

    if (leftIndex <= n && arr[leftIndex] > arr[largest])
        largest = leftIndex;

    if (rightIndex <= n && arr[rightIndex] > arr[largest])
        largest = rightIndex;

    if (index != largest)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(vector<int> &arr, int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
}

int main()
{
    int userLength;
    cout << "Enter the number of elements in the array: ";
    cin >> userLength;

    vector<int> userArr(userLength + 1, -1); // Incorporating -1 at the start index

    cout << "Enter the elements of the array:\n";
    for (int i = 1; i <= userLength; i++)
        cin >> userArr[i];

    buildHeap(userArr, userLength);

    cout << "Max-Heap: ";
    for (int i = 1; i <= userLength; i++)
        cout << userArr[i] << " ";
    cout << endl;

    return 0;
}

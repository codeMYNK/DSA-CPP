#include <iostream>

using namespace std;

int main()
{

    int arr[6] = {1, 5, 6, 7, 8, 10};

    int length = 6;

    int start = 0;
    int end = length - 1;

    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}
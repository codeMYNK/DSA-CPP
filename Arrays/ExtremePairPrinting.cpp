#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {1, 4, 6, 8, 9, 10, 67, 90, 13, 23};

    int length = 10;

    int start = 0;
    int end = length - 1;

    while (start <= end)
    {
        cout << arr[start] << " ";
        if (start != end)
        {
            cout << arr[end] << " ";
        }
        start++;
        end--;
    }
}
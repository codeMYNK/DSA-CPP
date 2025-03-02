#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[7] = {1, 2, 3, 4, 6, 7, 8};

    int start = 0;
    int end = 6;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == mid + 1)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start) / 2;
    }

    cout << "The missing element is : " << start + 1 << endl;
}
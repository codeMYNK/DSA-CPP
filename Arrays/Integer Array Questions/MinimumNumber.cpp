#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int arr[12] = {2, 56, 78, -1, 3, -90, 67, 56, 9, 0, 11, -100};

    int length = 12;

    int minNum = INT_MAX;

    for (int i = 0; i < length; i++)
    {
        if (arr[i] < minNum)
        {
            minNum = arr[i];
        }
    }

    cout << "The minimum number in the array is : " << minNum << endl;
}
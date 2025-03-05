#include <iostream>
#include <climits>

using namespace std;

int main()
{
    int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int maxElement = INT_MIN;
    int minElement = INT_MAX;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] > maxElement)
            {
                maxElement = arr[i][j];
            }
            if (arr[i][j] < minElement)
            {
                minElement = arr[i][j];
            }
        }
    }

    cout << "The max and min elements are : " << maxElement << " " << minElement;
}
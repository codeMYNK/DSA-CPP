#include <iostream>

using namespace std;

int main()
{
    int arr[4][4] = {{1, 34, 56, 78}, {2, 67, 89, 90}, {3, 150, 145, 167}, {4, 890, 765, 143}};
    int transposeArr[4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            transposeArr[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << transposeArr[i][j] << " ";
        }
        cout << endl;
    }
}
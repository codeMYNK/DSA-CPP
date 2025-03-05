#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int userRowLength, userColLength;

    cout << "Enter the no of rows : ";
    cin >> userRowLength;

    cout << "Enter the number of columns : ";
    cin >> userColLength;

    vector<vector<int>> userArr(userRowLength, vector<int>(userColLength));

    cout << "Enter the elements of the array,(Row-Wise) : " << endl;
    for (int i = 0; i < userRowLength; i++)
    {
        for (int j = 0; j < userColLength; j++)
        {
            cin >> userArr[i][j];
        }
    }

    for (int j = 0; j < userColLength; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < userRowLength; i++)
            {
                cout << userArr[i][j] << " ";
            }
        }
        else
        {
            for (int i = userRowLength - 1; i >= 0; i--)
            {
                cout << userArr[i][j] << " ";
            }
        }
    }
}
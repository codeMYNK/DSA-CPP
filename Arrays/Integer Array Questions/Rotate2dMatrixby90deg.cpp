#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int userLengthRow, userLengthCol;
    cout << "Enter the no of rows: ";
    cin >> userLengthRow;

    cout << "Enter the no of cols : ";
    cin >> userLengthCol;

    vector<vector<int>> userMatrix(userLengthRow, vector<int>(userLengthCol));
    vector<vector<int>> rotatedMatrix(userLengthCol, vector<int>(userLengthRow));

    cout << "Enter the elements of the matrix(Row wise): " << endl;
    for (int i = 0; i < userLengthRow; i++)
    {
        for (int j = 0; j < userLengthCol; j++)
        {
            cin >> userMatrix[i][j];
        }
    }

    for (int row = userLengthRow - 1; row >= 0; row--)
    {
        for (int col = 0; col < userLengthCol; col++)
        {
            rotatedMatrix[col][userLengthRow - 1 - row] = userMatrix[row][col];
        }
    }

    cout << "The rotated matrix by 90 deg is : " << endl;

    for (int i = 0; i < userLengthCol; i++)
    {
        for (int j = 0; j < userLengthRow; j++)
        {
            cout << rotatedMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
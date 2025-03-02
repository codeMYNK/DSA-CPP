#include <iostream>
#include <vector>

using namespace std;

vector<int> binarySearch2DArray(const vector<vector<int>> &arr, int rows, int cols, int target)
{
    int start = 0;
    int end = rows * cols - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int currRow = mid / cols;
        int currCol = mid % cols;

        if (arr[currRow][currCol] == target)
        {
            return {currRow, currCol};
        }
        if (arr[currRow][currCol] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return {-1, -1};
}

int main()
{
    int userRows, userCols;

    cout << "Enter the number of rows : ";
    cin >> userRows;

    cout << "Enter the number of cols: ";
    cin >> userCols;

    vector<vector<int>> userArr(userRows, vector<int>(userCols));
    int target;

    cout << "Enter the elements of the array(Row-wise) : " << endl;

    for (int i = 0; i < userRows; i++)
    {
        for (int j = 0; j < userCols; j++)
        {
            cin >> userArr[i][j];
        }
    }

    cout << "Enter the target value : ";
    cin >> target;

    vector<int> searchResult = binarySearch2DArray(userArr, userRows, userCols, target);

    int searchRow = searchResult[0];
    int searchCol = searchResult[1];

    if (searchRow == -1)
    {
        cout << "The target element is not found in the array.";
    }
    else
    {
        cout << "The target " << target << " is found at " << searchRow << "th row and " << searchCol << "th column." << endl;
    }
}
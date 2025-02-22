#include <iostream>

using namespace std;

int main()
{
    int noOfLines;

    cout << "Enter the number of lines : " << endl;
    cin >> noOfLines;

    for (int row = 0; row < noOfLines; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            cout << row + 1;
            if (row != col)
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    for (int row = 0; row < noOfLines; row++)
    {
        for (int col = 0; col < noOfLines - row; col++)
        {
            cout << (noOfLines - row);
            if (col != noOfLines - row - 1)
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}
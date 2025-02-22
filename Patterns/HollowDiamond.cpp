#include <iostream>

using namespace std;

int main()
{
    int noOfLines;
    cout << "Enter the number of lines : " << endl;
    cin >> noOfLines;

    for (int row = 0; row < noOfLines; row++)
    {
        for (int i = 0; i < noOfLines - row - 1; i++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * row + 1; j++)
        {
            if (j == 0 || j == 2 * row)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    for (int row = 0; row < noOfLines; row++)
    {
        for (int colSpace = 0; colSpace < row; colSpace++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * noOfLines - 2 * row - 1; j++)
        {
            if (j == 0 || j == 2 * noOfLines - 2 * row - 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
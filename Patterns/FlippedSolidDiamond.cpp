#include <iostream>

using namespace std;

int main()
{
    int noOfLines;

    cout << "Enter the number of lines: " << endl;
    cin >> noOfLines;

    for (int row = 0; row < noOfLines; row++)
    {
        for (int i = 0; i < noOfLines - row; i++)
        {
            cout << "*";
        }

        for (int spacePyr = 0; spacePyr < 2 * row + 1; spacePyr++)
        {
            cout << " ";
        }
        for (int i = 0; i < noOfLines - row; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int row = 0; row < noOfLines; row++)
    {
        for (int i = 0; i < row + 1; i++)
        {
            cout << "*";
        }

        for (int spacePyr = 0; spacePyr < 2 * noOfLines - 2 * row - 1; spacePyr++)
        {
            cout << " ";
        }

        for (int i = 0; i < row + 1; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
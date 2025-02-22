#include <iostream>

using namespace std;

int main()
{
    int noOfLines;
    cout << "Enter the number of lines: " << endl;
    cin >> noOfLines;

    for (int row = 0; row < noOfLines; row++)
    {
        if (row == 0)
        {
            for (int i = 0; i < noOfLines; i++)
            {
                cout << "* ";
            }
        }
        else
        {
            cout << "* ";
            for (int sp = 0; sp < noOfLines - row - 2; sp++)
            {
                cout << "  ";
            }
            if (row != noOfLines - 1)
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
}
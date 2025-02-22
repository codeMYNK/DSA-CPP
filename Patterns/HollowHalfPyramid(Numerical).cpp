#include <iostream>

using namespace std;

int main()
{
    int noOfLines;
    cout << "Enter the number of lines: ";
    cin >> noOfLines;

    for (int row = 0; row < noOfLines; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            if (col == 0)
            {
                cout << "1 ";
            }
            else if (col == row || row == noOfLines - 1)
            {
                cout << col + 1 << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}

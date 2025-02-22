#include <iostream>

using namespace std;

int main()
{
    int noOfLines;
    cout << "Enter the number of lines : ";
    cin >> noOfLines;

    for (int row = 0; row < noOfLines; row++)
    {
        for (int col = 0; col < noOfLines - row; col++)
        {
            if (row == 0)
            {
                cout << col + 1 << " ";
            }
            else if (col == 0)
            {
                cout << 1 << " ";
            }
            else if (col == noOfLines - row - 1)
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
}
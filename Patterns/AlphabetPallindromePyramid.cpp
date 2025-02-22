#include <iostream>

using namespace std;

int main()
{
    int noOfLines;

    cout << "Enter the no of lines : " << endl;
    cin >> noOfLines;

    for (int row = 0; row < noOfLines; row++)
    {
        int col;

        for (col = 0; col < row + 1; col++)
        {
            int ans = col + 1;
            char ch = ans + 'A' - 1;
            cout << ch;
        }

        col = col - 1;

        for (; col >= 1; col--)
        {
            int ans = col;
            char ch = ans + 'A' - 1;
            cout << ch;
        }

        cout << endl;
    }
}
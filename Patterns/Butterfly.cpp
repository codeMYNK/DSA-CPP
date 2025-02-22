#include <iostream>

using namespace std;

int main()
{
    int noOfLines;
    cout << "Enter the number of lines : ";
    cin >> noOfLines;

    for (int row = 0; row < noOfLines; row++)
    {

        for (int fir = 0; fir < row + 1; fir++)
        {
            cout << "* ";
        }

        for (int sp = 0; sp < 2 * (noOfLines - row - 1); sp++)
        {
            cout << "  ";
        }

        for (int sec = 0; sec < row + 1; sec++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    for (int row = 0; row < noOfLines; row++)
    {

        for (int invFir = 0; invFir < noOfLines - row; invFir++)
        {
            cout << "* ";
        }

        for (int invSp = 0; invSp < 2 * row; invSp++)
        {
            cout << "  ";
        }

        for (int invSec = 0; invSec < noOfLines - row; invSec++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}

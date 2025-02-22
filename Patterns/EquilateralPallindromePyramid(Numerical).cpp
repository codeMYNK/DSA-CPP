#include <iostream>

using namespace std;

int main()
{
    int noOfLines;
    cout << "Enter the number of lines : ";
    cin >> noOfLines;

    for (int row = 0; row < noOfLines; row++)
    {
        for (int sp = 0; sp < noOfLines - row - 1; sp++)
        {
            cout << "  ";
        }
        for (int st = 0; st < row + 1; st++)
        {
            cout << st + 1 << " ";
        }
        for (int backCount = row; backCount >= 1; backCount--)
        {
            cout << backCount << " ";
        }
        cout << endl;
    }
}
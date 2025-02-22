#include <iostream>

using namespace std;

int main()
{
    int noOfLines, flagToPrint = 1;

    cout << "Enter the no of lines : ";
    cin >> noOfLines;

    for (int row = 0; row < noOfLines; row++)
    {
        for (int col = 0; col < row + 1; col++)
        {
            cout << flagToPrint << " ";
            flagToPrint++;
        }
        cout << endl;
    }
}
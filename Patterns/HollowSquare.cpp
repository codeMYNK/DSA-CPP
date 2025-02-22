#include <iostream>

using namespace std;

int main()
{
    int noOfLines;

    cout << "Enter the number of lines : " << endl;
    cin >> noOfLines;

    for (int row = 0; row < noOfLines; row++)
    {
        if (row == 0 || row == noOfLines - 1)
        {
            for (int star = 0; star < noOfLines; star++)
            {
                cout << "*";
            }
        }
        else
        {
            cout << "* ";
            for (int space = 0; space < noOfLines - 1; space++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
}
#include <iostream>

using namespace std;

int main()
{
    int noOfLines;
    cout << "Enter the number of lines: " << endl;
    cin >> noOfLines;

    for (int i = 0; i < noOfLines; i++)
    {
        for (int j = 0; j < noOfLines - i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < i + 1; k++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int row = 0; row < noOfLines; row++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < noOfLines - row; k++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
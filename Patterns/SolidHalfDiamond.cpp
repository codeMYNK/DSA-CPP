#include <iostream>

using namespace std;

int main()
{
    int noOfLines;
    cout << "Enter the number of lines : ";
    cin >> noOfLines;

    for (int row = 0; row < noOfLines; row++)
    {
        for (int pOne = 0; pOne < row + 1; pOne++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    for (int row = 0; row < noOfLines; row++)
    {
        for (int pTwo = 0; pTwo < noOfLines - row; pTwo++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
#include <iostream>

using namespace std;

int main()
{
    int noOfRows;

    cout << "Enter the no of rows: " << endl;
    cin >> noOfRows;

    for (int i = 0; i < noOfRows; i++)
    {
        for (int j = 0; j < noOfRows - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
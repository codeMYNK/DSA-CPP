#include <iostream>

using namespace std;

int main()
{
    int noOfRows, noOfStars;

    cout << "Enter the number of rows: " << endl;
    cin >> noOfRows;

    cout << "Enter the number of stars per line : " << endl;
    cin >> noOfStars;

    for (int i = 0; i < noOfRows; i++)
    {
        if (i == 0 || i == noOfRows - 1)
        {
            for (int j = 0; j < noOfStars; j++)
            {
                cout << "* ";
            }
        }
        else
        {
            cout << "* ";
            for (int z = 0; z < noOfStars - 2; z++)
            {
                cout << "  ";
            }
            cout << "* ";
        }
        cout << endl;
    }
}
#include <iostream>

using namespace std;

int main()
{
    int noOfRows, noOfStars;

    cout << "Enter the number of rows: " << endl;
    cin >> noOfRows;

    cout << "Enter the number of Stars in each row: " << endl;
    cin >> noOfStars;

    for (int i = 0; i < noOfRows; i++)
    {
        for (int j = 0; j < noOfStars; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
#include <iostream>

using namespace std;

int main()
{
    int noOfRows;

    cout << "Enter the number of rows: " << endl;
    cin >> noOfRows;

    for (int i = 0; i < noOfRows; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}
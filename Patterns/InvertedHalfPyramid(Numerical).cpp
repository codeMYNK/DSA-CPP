#include <iostream>

using namespace std;

int main()
{
    int noOfLines;

    cout << "Enter the number of lines: " << endl;
    cin >> noOfLines;

    for (int i = 0; i < noOfLines; i++)
    {
        for (int j = 0; j < noOfLines - i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}
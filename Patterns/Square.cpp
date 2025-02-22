#include <iostream>

using namespace std;

int main()
{

    int lengthOfSideOfSquare;

    cout << "Enter the length of the side: " << endl;

    cin >> lengthOfSideOfSquare;

    for (int i = 0; i < lengthOfSideOfSquare; i++)
    {
        for (int j = 0; j < lengthOfSideOfSquare; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
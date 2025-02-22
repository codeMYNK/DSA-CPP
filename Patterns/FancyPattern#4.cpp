#include <iostream>

using namespace std;

int main()
{
    int noOfLines;
    cout << "Enter the number of lines : ";
    cin >> noOfLines;

    for (int i = 0; i < noOfLines; i++)
    {
        int condition = i <= noOfLines / 2 ? 2 * i : 2 * (noOfLines - i - 1);
        for (int j = 0; j <= condition; j++)
        {
            if (j <= condition / 2)
            {
                if (j == 0)
                {
                    cout << "*";
                }
                cout << j + 1;
            }
            else
            {

                cout << condition - j + 1;
            }
        }
        cout << "*";
        cout << endl;
    }
}

/*
Expected Output for n = 7

*1*
*121*
*12321*
*1234321*
*12321*
*121*
*1*


*/
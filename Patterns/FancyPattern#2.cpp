#include <iostream>
#include <assert.h>

using namespace std;

int main()
{
    int noOfLines;

    cout << "Enter the number of lines : ";
    cin >> noOfLines;
    assert(noOfLines <= 9);

    for (int row = 0; row < noOfLines; row++)
    {
        int start_num_index = 8 - row;
        int num = row + 1;
        int count_num = num;
        for (int j = 0; j < 17; j++)
        {
            if (j == start_num_index && count_num > 0)
            {
                cout << num;
                start_num_index = start_num_index + 2;
                count_num--;
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}

// output : noOfLines = 5
/*
 ********1********
 *******2*2*******
 ******3*3*3******
 *****4*4*4*4*****
 ****5*5*5*5*5****
 */
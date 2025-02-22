// Formula : C = C * (i - j)/j;
// i = [1, N]
// j = [1, i]

#include <iostream>

using namespace std;

int main()
{
    int noOfLines;
    cout << "Enter the number of lines: ";
    cin >> noOfLines;

    for (int i = 0; i < noOfLines; i++)
    {
        int C = 1;
        for (int j = 0; j <= i; j++)
        {
            cout << C << " ";
            C = C * (i - j) / (j + 1);
        }
        cout << endl;
    }

    return 0;
}
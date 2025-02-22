#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of lines: ";
    cin >> n;

    int num = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (j % 2 == 0)
            {
                cout << num << " ";
                num++;
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }

    int k = 2 * n - 1;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        for (; j < 2 * (n - i) - 1; j++)
        {
            if (j % 2 == 0)
            {
                cout << k << " ";
                k++;
            }
            else
            {
                cout << "* ";
            }
        }
        k = k - j;
        cout << endl;
    }

    return 0;
}
/*
Expected Output for n = 4

1
2 * 3
4 * 5 * 6
7 * 8 * 9 * 10
7 * 8 * 9 * 10
4 * 5 * 6
2 * 3
1



*/
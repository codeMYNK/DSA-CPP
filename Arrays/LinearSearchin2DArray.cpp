#include <iostream>

using namespace std;

int main()
{
    int key;

    cout << "Enter the key you want to search :  ";
    cin >> key;
    bool isFound = false;
    int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] == key)
            {
                isFound = true;
            }
        }
    }
    if (isFound)
    {
        cout << "The element is present" << endl;
    }
    else
    {
        cout << "The element is not present" << endl;
    }
}
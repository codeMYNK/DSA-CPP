#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int getLengthOfString(char arr[])
{
    int count = 0;
    int i = 0;

    while (arr[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

int main()
{
    char userInputArr[100];
    char userChar;

    cout << "Enter the string : ";
    cin.getline(userInputArr, 99);

    cout << "Enter the character you want to replace the space with :  ";
    cin >> userChar;

    int lengthOfString = getLengthOfString(userInputArr);

    if (lengthOfString > 90)
    {
        cout << "Warning : String characters are going out of bounds." << endl;
    }

    for (int i = 0; i < lengthOfString; i++)
    {
        if (userInputArr[i] == ' ')
        {
            userInputArr[i] = userChar;
        }

        cout << userInputArr[i];
    }

    return 0;
}
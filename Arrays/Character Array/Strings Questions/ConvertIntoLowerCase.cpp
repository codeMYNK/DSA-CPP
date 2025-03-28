#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

int main()
{
    char userArr[100];
    cout << "Enter the string you want to convert into lowercase: ";
    cin.getline(userArr, 100);

    int stringLength = strlen(userArr);

    for (int i = 0; i < stringLength; i++)
    {
        if (userArr[i] >= 'A' && userArr[i] <= 'Z' && userArr[i] != ' ')
        {

            userArr[i] = userArr[i] - 'A' + 'a';
        }
    }

    cout << "Here is your lowercase string : " << userArr << endl;

    return 0;
}
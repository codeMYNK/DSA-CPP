#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char myArr[80];

    cout << "Enter the string to reverse : ";
    cin.getline(myArr, 80);
    int counter = 0;
    int i = 0;
    while (myArr[i] != '\0')
    {
        counter++;
        i++;
    }

    while (counter > 0)
    {
        cout << myArr[counter - 1];
        counter--;
    }
    return 0;
}
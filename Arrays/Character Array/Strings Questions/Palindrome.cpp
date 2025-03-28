#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

bool palindromeChecker(char arr[], int length)
{
    int i = 0;
    int end = length - 1;

    while (i < end)
    {
        if (arr[i] != arr[end])
        {
            return false;
        }
        else
        {
            i++;
            end--;
        }
    }
    return true;
}

int main()
{
    char userInputArr[20];

    cout << "Enter the word to check if its a palindrome or not : ";
    cin >> userInputArr;

    int lengthOfString = strlen(userInputArr);

    bool palindromValidator = palindromeChecker(userInputArr, lengthOfString);

    if (palindromValidator)
    {
        cout << "The given word is a pallindrome." << endl;
    }
    else
    {
        cout << "The given word is not a pallindrome." << endl;
    }
}
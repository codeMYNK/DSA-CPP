#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

bool palindromeChecker(string &str, int i, int j, int &n)
{
    if (i > j)
    {
        return true;
    }
    if (str[i] != str[j])
    {
        return false;
    }
    return palindromeChecker(str, i + 1, j - 1, n);
}

int main()
{
    string userStr;
    cout << "Enter the string : ";
    getline(cin, userStr);

    int length = userStr.length();
    int counterStart = 0;
    int counterEnd = length - 1;

    bool result = palindromeChecker(userStr, counterStart, counterEnd, length);

    if (result)
    {
        cout << "The given string is a palindrome." << endl;
    }
    else
    {
        cout << "The given string is not a palindrome." << endl;
    }

    return 0;
}
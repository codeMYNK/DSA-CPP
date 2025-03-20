#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

string reverseString(string &str, int j, int n)
{

    if (j < 0)
    {
        return "";
    }

    return str[j] + reverseString(str, j - 1, n);
}

int main()
{
    string userStr;

    cout << "Enter the string you want to reverse : ";
    getline(cin, userStr);

    int length = userStr.size();
    int counter = length - 1;

    string reversed = reverseString(userStr, counter, length);

    cout << "The reversed string is : " << reversed << endl;
    return 0;
}
#include <iostream>
#include <limits.h>
#include <string.h>
#include <cstring>
#include <algorithm>

using namespace std;

int lastOccurenceFinder(string &str, char x, int i, int n, int maxi)
{
    if (i == n)
    {
        return maxi;
    }

    if (str[i] == x)
    {
        maxi = max(i, maxi);
    }

    return lastOccurenceFinder(str, x, i + 1, n, maxi);
}

int main()
{
    string userInput;
    cout << "Enter the string : ";
    getline(cin, userInput);

    char userChar;
    cout << "Enter the character you want to find: ";
    cin >> userChar;

    int counter = 0;
    int length = userInput.length();
    int maxi = INT_MIN;

    int ans = lastOccurenceFinder(userInput, userChar, counter, length, maxi);

    if (ans < 0)
    {
        cout << "The character is not present in the string. ";
    }
    else
    {
        cout << "The last occurence of the character " << userChar << " is at " << ans + 1 << "th position." << endl;
    }

    return 0;
}
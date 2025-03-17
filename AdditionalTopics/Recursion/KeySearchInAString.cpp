#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int keySearcher(string str, int n, char key, int i, int &numOfOccurence)
{
    if (i >= n)
    {
        return numOfOccurence;
    }
    if (str[i] == key)
    {
        cout << "Found at " << i + 1 << "th position" << endl;
        numOfOccurence++;
    }
    return keySearcher(str, n, key, i + 1, numOfOccurence);
}

int main()
{
    string userStr;
    cout << "Enter the string : ";
    getline(cin, userStr);

    char userKey;
    cout << "Enter the character you want to search in the string : ";
    cin >> userKey;

    int strLen = userStr.length();
    int counter = 0;
    int numOfOccurences = 0;

    int result = keySearcher(userStr, strLen, userKey, counter, numOfOccurences);

    if (result > 0)
    {
        cout << "The character " << userKey << " is present in the string " << numOfOccurences << " times, check above for exact positions." << endl;
    }
    else
    {
        cout << "The character is not present in the string." << endl;
    }
}
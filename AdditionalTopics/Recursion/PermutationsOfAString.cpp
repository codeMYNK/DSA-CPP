#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

void getPermutation(string &str, int s, int i)
{
    if (i == s - 1)
    {
        cout << str << " ";
        return;
    }

    for (int j = i; j < s; j++)
    {
        swap(str[i], str[j]);

        getPermutation(str, s, i + 1);

        swap(str[i], str[j]);
    }
}

int main()
{
    string userString;

    cout << "Enter the string you want the permutation of : ";
    getline(cin, userString);
    int sizeOfString = userString.length();
    int counter = 0;
    getPermutation(userString, sizeOfString, counter);

    return 0;
}
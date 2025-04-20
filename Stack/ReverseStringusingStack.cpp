#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int main()
{
    string str;
    cout << "Enter the string you want to reverse : ";
    getline(cin, str);

    int strLen = str.length();

    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    cout << "Here is the reversed string : " << endl;

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}
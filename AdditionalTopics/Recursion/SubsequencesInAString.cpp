#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void printSubSequences(string str, int i, string &output)
{
    if (i >= str.length())
    {
        cout << output << endl;
        return;
    }

    // exclude
    printSubSequences(str, i + 1, output);

    // include
    output.push_back(str[i]);
    printSubSequences(str, i + 1, output);
}

int main()
{
    string userStr;
    cout << "Enter the string : ";
    getline(cin, userStr);
    int counter = 0;
    string outputString = "";

    printSubSequences(userStr, counter, outputString);

    return 0;
}
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string userInput;

    cout << "Enter the string: ";
    getline(cin, userInput);

    unordered_map<char, int> mp;

    for (int i = 0; i < userInput.length(); i++)
    {
        char ch = userInput[i];

        mp[ch]++;
    }

    for (auto i : mp)
    {
        cout << "Character " << i.first << " is repeated " << i.second << " times." << endl;
    }

    return 0;
}
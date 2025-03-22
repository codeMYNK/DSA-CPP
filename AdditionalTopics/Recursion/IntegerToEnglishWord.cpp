// Leetcode Problem No : 273 - Integer to English Words(Hard)

/*
Convert a non-negative integer num to its English words representation.



Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"


Constraints:

0 <= num <= 231 - 1
*/

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, string>> mp = {
    {1000000000, "Billion"},
    {1000000, "Million"},
    {1000, "Thousand"},
    {100, "Hundred"},
    {90, "Ninety"},
    {80, "Eighty"},
    {70, "Seventy"},
    {60, "Sixty"},
    {50, "Fifty"},
    {40, "Forty"},
    {30, "Thirty"},
    {20, "Twenty"},
    {19, "Nineteen"},
    {18, "Eighteen"},
    {17, "Seventeen"},
    {16, "Sixteen"},
    {15, "Fifteen"},
    {14, "Fourteen"},
    {13, "Thirteen"},
    {12, "Twelve"},
    {11, "Eleven"},
    {10, "Ten"},
    {9, "Nine"},
    {8, "Eight"},
    {7, "Seven"},
    {6, "Six"},
    {5, "Five"},
    {4, "Four"},
    {3, "Three"},
    {2, "Two"},
    {1, "One"}};

string numToWords(int num)
{
    if (num == 0)
        return "Zero";

    string result = "";

    for (auto it : mp)
    {
        if (num >= it.first)
        {
            if (num >= 100)
            {
                result += numToWords(num / it.first) + " ";
            }

            result += it.second;

            num %= it.first;

            if (num > 0)
                result += " ";
        }
    }

    return result;
}

int main()
{
    int userNum;
    cout << "Enter the number you want to convert into English form: ";
    cin >> userNum;

    if (userNum < 0)
    {
        cout << "Negative numbers are not supported!" << endl;
        return 0;
    }

    string result = numToWords(userNum);
    cout << "In words: " << result << endl;

    return 0;
}

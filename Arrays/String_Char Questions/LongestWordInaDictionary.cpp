// Leetcode Problem No 524 : Longest Word In a Dictionary through Deletion(Medium)

/*
Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.



Example 1:

Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
Example 2:

Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"


Constraints:

1 <= s.length <= 1000
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 1000
s and dictionary[i] consist of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static bool customcompare(string word1, string word2)
    {
        if (word1.length() == word2.length())
        {
            return word1 < word2;
        }
        return word1.length() > word2.length();
    }
    bool isSubSequence(string word, string s)
    {
        int i = 0, j = 0;
        while (i < word.length() && j < s.length())
        {
            if (word[i] == s[j])
            {
                i++;
            }
            j++;
        }
        return i == word.length();
    }
    string findLongestWord(string s, vector<string> &dictionary)
    {
        sort(dictionary.begin(), dictionary.end(), customcompare);

        for (const string &word : dictionary)
        {
            if (isSubSequence(word, s))
            {
                return word;
            }
        }
        return "";
    }
};
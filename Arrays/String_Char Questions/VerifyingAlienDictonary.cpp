// Leetcode Problem No :  953 : Verifying an Alien Dictonary(Easy)

/*
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.



Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isSorted(string word1, string word2, unordered_map<char, int> &freq)
    {
        int len1 = word1.length();
        int len2 = word2.length();
        for (int i = 0; i < min(len1, len2); i++)
        {
            if (freq[word1[i]] < freq[word2[i]])
                return true;
            if (freq[word1[i]] > freq[word2[i]])
                return false;
        }
        return len1 <= len2;
    }

    bool isAlienSorted(vector<string> &words, string order)
    {
        unordered_map<char, int> freq;
        for (int i = 0; i < order.length(); i++)
        {
            freq[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; i++)
        {
            if (!isSorted(words[i], words[i + 1], freq))
            {
                return false;
            }
        }
        return true;
    }
};
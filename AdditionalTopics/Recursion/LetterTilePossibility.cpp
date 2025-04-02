// Leetcode Problem No : 1079 - Letter Tile Possibilites (Medium)

/*
You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.



Example 1:

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: tiles = "AAABBC"
Output: 188
Example 3:

Input: tiles = "V"
Output: 1


Constraints:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void backtrack(vector<int> &freq, int &count)
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                count++;
                freq[i]--;
                backtrack(freq, count);
                freq[i]++;
            }
        }
    }

    int numTilePossibilities(string tiles)
    {
        vector<int> freq(26, 0);
        for (char c : tiles)
            freq[c - 'A']++;

        int count = 0;
        backtrack(freq, count);
        return count;
    }
};

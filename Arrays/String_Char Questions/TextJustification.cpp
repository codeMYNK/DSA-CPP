// Leetcode Problem No 68 : Text Justification(Hard)

/*
Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.


Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]


Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result;
        vector<string> currentLine;
        int currentLength = 0;

        for (string &word : words)
        {
            if (currentLength + currentLine.size() + word.length() > maxWidth)
            {
                string justifiedLine = justify(currentLine, maxWidth, currentLength);
                result.push_back(justifiedLine);

                currentLine.clear();
                currentLength = 0;
            }

            currentLine.push_back(word);
            currentLength += word.length();
        }

        string lastLine = leftJustify(currentLine, maxWidth);
        result.push_back(lastLine);

        return result;
    }

    string justify(vector<string> &words, int maxWidth, int currentLength)
    {
        int gaps = words.size() - 1;
        int extraSpaces = maxWidth - currentLength;

        if (gaps == 0)
            return words[0] + string(extraSpaces, ' ');

        int minSpaces = extraSpaces / gaps;
        int additionalSpaces = extraSpaces % gaps;

        string result;
        for (int i = 0; i < words.size(); i++)
        {
            result += words[i];
            if (i < gaps)
            {
                result += string(minSpaces + (i < additionalSpaces ? 1 : 0), ' ');
            }
        }
        return result;
    }

    string leftJustify(vector<string> &words, int maxWidth)
    {
        string result = "";
        for (int i = 0; i < words.size(); i++)
        {
            result += words[i];
            if (i != words.size() - 1)
                result += " ";
        }

        result += string(maxWidth - result.length(), ' ');
        return result;
    }
};

// Gfg Problem - Word Ladder - II (Hard)

/*
Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
Keep the following conditions in mind:

A word can only consist of lowercase characters.
Only one letter can be changed in each transformation.
Each transformed word must exist in the wordList including the targetWord.
startWord may or may not be part of the wordList.
Return an empty list if there is no such transformation sequence.
The first part of this problem can be found here.


Example 1:

Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}
Output:
der dfr dfs
der des dfs
Explanation:
The length of the smallest transformation is 3.
And the following are the only two ways to get
to targetWord:-
"der" -> "des" -> "dfs".
"der" -> "dfr" -> "dfs".
Example 2:

Input:
startWord = "gedk", targetWord = "geek",
wordList = {"geek", "gefk"}
Output:
"gedk" -> "geek"

Your Task:
You don't need to read or print anything, Your task is to complete the function findSequences() which takes startWord, targetWord and wordList as input parameter and returns a list of list of strings of the shortest transformation sequence from startWord to targetWord.
Note: You don't have to return -1 in case of no possible sequence. Just return the Empty List.


Expected Time Compelxity: O(N*(logN * M * 26))
Expected Auxiliary Space: O(N * M) where N = length of wordList and M = |wordListi|


Constraints:
1 ≤ N ≤ 100
1 ≤ M ≤ 10


*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        int level = 0;
        usedOnLevel.push_back(beginWord);
        vector<vector<string>> ans;

        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }

            string word = vec.back();
            if (word == endWord)
            {
                if (ans.empty())
                {
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }

            for (int i = 0; i < word.length(); i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

/*
    Alternative solution for leetcode version: Combining the approach of word ladder 1 and then backtracking
    to reduce the number of paths to explore.

class Solution {
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;
private:
    void dfs(string word, vector<string> &seq){
        if(word == b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mp[word];
         for(int i = 0; i < word.length(); i++){
            char orignal = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(mp.find(word) != mp.end() && mp[word] + 1 == steps){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = orignal;
        }

    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        b = beginWord;
        q.push({beginWord});
        mp[beginWord] = 1;
        int sz = beginWord.length();
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front();
            int steps = mp[word];
            q.pop();
            if(word == endWord) break;
            for(int i = 0; i < sz; i++){
                char orignal = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mp[word] = steps + 1;
                    }
                }
                word[i] = orignal;
            }
        }
        if(mp.find(endWord) != mp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};
*/
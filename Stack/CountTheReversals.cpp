// Gfg Problem : Count The Reversals (Medium)

/*
Given a string s consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression. A reversal means changing '{' to '}' or vice-versa.

Examples:

Input: s = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
Input: s = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
Constraints:
1 ≤ |s| ≤ 105
*/

#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

class Solution
{
public:
    int countMinReversals(string s)
    {
        if (s.size() & 1)
            return -1;

        int ans = 0;
        stack<char> st;

        for (char ch : s)
        {
            if (ch == '{')
            {
                st.push(ch);
            }
            else
            {
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
        }

        while (!st.empty())
        {
            char a = st.top();
            st.pop();
            char b = st.top();
            st.pop();

            if (a == b)
            {
                ans += 1;
            }
            else
            {
                ans += 2;
            }
        }

        return ans;
    }
};
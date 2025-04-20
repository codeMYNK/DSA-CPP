#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    string removeBrackets(string s)
    {
        stack<char> st;

        for (char ch : s)
        {
            if (ch == ')')
            {
                bool hasOperator = false;

                while (!st.empty() && st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                        hasOperator = true;
                    st.pop();
                }

                // pop the opening bracket '('
                if (!st.empty())
                    st.pop();

                // if no operator found, then brackets were redundant
                if (!hasOperator)
                    return "Yes";
            }
            else
            {
                st.push(ch);
            }
        }

        return "No"; // no redundant brackets
    }
};
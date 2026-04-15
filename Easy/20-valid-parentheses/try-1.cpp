/*
 * Problem #20: Valid Parentheses
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/18/2024, 6:47:03 PM
 * Link: https://leetcode.com/problems/valid-parentheses/
 */

class Solution
{
    public:
        bool isValid(string s)
        {
            stack<char> st;

            for (char c: s)
            {
                if (c == '(' || c == '[' || c == '{')
                {
                    st.push(c);
                }
                else
                {
                    if (st.empty()) return false;
                    if (c == ')' && st.top() != '(') return false;
                    if (c == ']' && st.top() != '[') return false;
                    if (c == '}' && st.top() != '{') return false;
                    st.pop();
                }
            }

            return st.empty();
        }
};

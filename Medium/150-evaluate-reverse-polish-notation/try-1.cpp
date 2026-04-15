/*
 * Problem #150: Evaluate Reverse Polish Notation
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/2/2025, 3:01:54 AM
 * Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
 */

class Solution
{
    public:
        int evalRPN(vector<string> &exp)
        {
            stack<string> st;
            int i = 0;
            int n = exp.size();
            while (i < n)
            {
                if (exp[i] != "+" && exp[i] != "-" && exp[i] != "*" && exp[i] != "/")
            {
                    st.push(exp[i]);
                }
                else
                {
                    int t1 = stoi(st.top());
                    st.pop();
                    int t2 = stoi(st.top());
                    st.pop();
                    int ans = 0;
                    if (exp[i] == "/")
                    {
                        ans = t2 / t1;
                    }
                    else if (exp[i] == "*")
                    {
                        ans = t2 * t1;
                    }
                    else if (exp[i] == "+")
                    {
                        ans = t2 + t1;
                    }
                    else if (exp[i] == "-")
                    {
                        ans = t2 - t1;
                    }

                    st.push(to_string(ans));
                }
                i++;
            }

            return stoi(st.top());
        }
};

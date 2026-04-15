/*
 * Problem #1717: Maximum Score From Removing Substrings
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/23/2025, 2:36:00 PM
 * Link: https://leetcode.com/problems/maximum-score-from-removing-substrings/
 */

class Solution
{
    public:
        int maximumGain(string s, int x, int y)
        {
            int ans = 0;
            stack<char> st;
            if (x > y)
            {
                for (char c: s)
                {
                    if (!st.empty() && st.top() == 'a' && c == 'b')
                    {
                        st.pop();
                        ans += x;
                    }
                    else
                    {
                        st.push(c);
                    }
                }
                int cnt = 0;
                while (!st.empty())
                {
                    char c = st.top();
                    st.pop();
                    if (c == 'a')
                    {
                        cnt++;
                    }
                    else if (c == 'b')
                    {
                        if (cnt)
                        {
                            cnt--;
                            ans += y;
                        }
                    }
                    else
                    {
                        cnt = 0;
                    }
                }
            }
            else
            {
                for (char c: s)
                {
                    if (!st.empty() && st.top() == 'b' && c == 'a')
                    {
                        st.pop();
                        ans += y;
                    }
                    else
                    {
                        st.push(c);
                    }
                }
                int cnt = 0;
                while (!st.empty())
                {
                    char c = st.top();
                    st.pop();
                    if (c == 'b')
                    {
                        cnt++;
                    }
                    else if (c == 'a')
                    {
                        if (cnt)
                        {
                            cnt--;
                            ans += x;
                        }
                    }
                    else
                    {
                        cnt = 0;
                    }
                }
            }

            return ans;
        }	// aaababbb
};

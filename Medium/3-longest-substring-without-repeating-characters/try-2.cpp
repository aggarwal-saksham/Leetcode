/*
 * Problem #3: Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/24/2025, 5:51:23 PM
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            set<char> st;
            int l = 0, r = 0, maxi = 0;
            int n = s.size();
            while (r < n)
            {
                if (st.find(s[r]) == st.end())
                {
                    st.insert(s[r]);
                    r++;
                }
                else
                {
                    st.erase(s[l]);
                    l++;
                }
                maxi = max(maxi, r - l);
            }

            return maxi;
        }
};

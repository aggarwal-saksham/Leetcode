/*
 * Problem #3: Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Submission: Try 5
 * status: Accepted
 * Language: cpp
 * Date: 12/24/2025, 1:26:05 AM
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int n = s.size();
            int l = 0, r = 0;
            unordered_set<int> st;
            int maxi = 0;
            while (l <= r && r < n)
            {
                if (st.find(s[r]) == st.end())
                {
                    st.insert(s[r]);
                    maxi = max(maxi, r - l + 1);
                    r++;
                }
                else
                {
                    st.erase(s[l]);
                    l++;
                }
            }
            return maxi;
        }
};

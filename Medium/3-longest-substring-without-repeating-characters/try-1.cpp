/*
 * Problem #3: Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/3/2025, 5:13:18 PM
 * Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            map<char, int> mpp;
            int n = s.length();
            if(n == 0 || n == 1) return n;
            int l = 0, r = 0;
            int maxLen = 0;
            while (r < n)
            {
                if (mpp.find(s[r]) == mpp.end() || mpp[s[r]] < l)
                {
                    int len = r - l + 1;
                    maxLen = max(maxLen, len);
                    mpp[s[r]] = r;
                    r++;
                }
                else
                {
                    l = mpp[s[r]] + 1;
                    mpp[s[r]] = r;
                    r++;
                }
            }
            return maxLen;
        }
};

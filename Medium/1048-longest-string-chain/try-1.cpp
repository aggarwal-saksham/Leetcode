/*
 * Problem #1048: Longest String Chain
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/4/2025, 5:58:14 PM
 * Link: https://leetcode.com/problems/longest-string-chain/
 */

class Solution
{
    public:

    bool check(string &s1, string &s2)
    {
        if (s1.size() + 1 != s2.size()) return false;
        for (int i = 0; i < s2.size(); i++)
        {
            string temp = s2;
            temp.erase(i, 1);
            if (temp == s1) return true;
        }
        return false;
    }

    static bool comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }
    
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (check(words[j], words[i]))
                {
                    dp[i] = max(1 + dp[j], dp[i]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

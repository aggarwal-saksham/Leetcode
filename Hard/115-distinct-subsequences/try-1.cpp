/*
 * Problem #115: Distinct Subsequences
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/30/2025, 11:50:06 PM
 * Link: https://leetcode.com/problems/distinct-subsequences/
 */

class Solution
{
    public:
        int numDistinct(string s, string t)
        {
            int n = s.size();
            int m = t.size();
            vector<vector < double>> dp(n + 1, vector<double> (m + 1));
            for (int j = 0; j < m + 1; j++) dp[0][j] = 0;
            for (int i = 0; i < n + 1; i++) dp[i][0] = 1;

            for (int i = 1; i < n + 1; i++)
            {
                for (int j = 1; j < m + 1; j++)
                {
                    if (s[i - 1] == t[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
            return (int)dp[n][m];
        }
};

/*
 * Problem #583: Delete Operation for Two Strings
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/30/2025, 2:13:50 PM
 * Link: https://leetcode.com/problems/delete-operation-for-two-strings/
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int j = 0; j < m + 1; j++)
            dp[0][j] = 0;
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0;

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return {n + m - (2 *  dp[n][m])};
    }
};

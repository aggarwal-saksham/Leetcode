/*
 * Problem #62: Unique Paths
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/8/2025, 8:42:25 PM
 * Link: https://leetcode.com/problems/unique-paths/
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } 
                else {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m-1][n-1];
    }
};

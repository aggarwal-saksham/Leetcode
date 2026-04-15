/*
 * Problem #931: Minimum Falling Path Sum
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2025, 4:43:59 PM
 * Link: https://leetcode.com/problems/minimum-falling-path-sum/
 */

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp,
              vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (i > m - 1 || j > n - 1 || i < 0 || j < 0)
            return 1e9;

        if (i == m - 1)
            return matrix[i][j];

        if (dp[i][j] != -1e9)
            return dp[i][j];

        return dp[i][j] = min({matrix[i][j] + solve(i + 1, j, dp, matrix),
                               matrix[i][j] + solve(i + 1, j + 1, dp, matrix),
                               matrix[i][j] + solve(i + 1, j - 1, dp, matrix)});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1e9));

        int mini = 1e9;

        for (int j = 0; j < n; j++) {
            mini = min(mini, solve(0, j, dp, matrix));
        }

        return mini;
    }
};

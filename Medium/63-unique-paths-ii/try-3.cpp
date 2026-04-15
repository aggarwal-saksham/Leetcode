/*
 * Problem #63: Unique Paths II
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2025, 2:44:12 PM
 * Link: https://leetcode.com/problems/unique-paths-ii/
 */

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp,
              vector<vector<int>>& obstacleGrid) {
        if (i < 0 || j < 0)
            return 0;
        if (obstacleGrid[i][j] == 1)
            return 0;
        else {
            if (i == 0 && j == 0)
                return 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = solve(i - 1, j, dp, obstacleGrid) +
                          solve(i, j - 1, dp, obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, dp, obstacleGrid);
    }
};

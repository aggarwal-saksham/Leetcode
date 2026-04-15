/*
 * Problem #64: Minimum Path Sum
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2025, 3:02:08 PM
 * Link: https://leetcode.com/problems/minimum-path-sum/
 */

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp,
              vector<vector<int>>& grid) {
        if (i < 0 || j < 0)
            return 1e9;

        if (i == 0 && j == 0)
            return grid[0][0];

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = min(grid[i][j] + solve(i - 1, j, dp, grid),
                              grid[i][j] + solve(i, j - 1, dp, grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, dp, grid);
    }
};

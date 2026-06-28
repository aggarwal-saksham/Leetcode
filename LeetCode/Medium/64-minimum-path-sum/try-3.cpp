/*
 * Problem #64: Minimum Path Sum
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/27/2026, 2:30:07 PM
 * Link: https://leetcode.com/problems/minimum-path-sum/
 */

class Solution {
public:
    int rec(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(r < 0 || c < 0) return 1e9;
        if(r == 0 && c == 0) return grid[0][0];

        if(dp[r][c] != -1) return dp[r][c];

        int left = grid[r][c] + rec(r, c - 1, grid, dp);
        int up =  grid[r][c] + rec(r - 1, c, grid, dp);
        return dp[r][c] = min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return rec(n - 1, m- 1, grid, dp);
    }
};

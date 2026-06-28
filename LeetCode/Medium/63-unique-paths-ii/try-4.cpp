/*
 * Problem #63: Unique Paths II
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/27/2026, 12:57:33 PM
 * Link: https://leetcode.com/problems/unique-paths-ii/
 */

class Solution {
public:
    int rec(int r, int c, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(r < 0 || c < 0) return 0;
        if(obstacleGrid[r][c] == 1) return 0;
        if(r == 0 && c == 0) return 1;

        if(dp[r][c] != -1) return dp[r][c];

        int left = 0, up = 0;

        if(c > 0 && obstacleGrid[r][c - 1] == 0)
            left = rec(r, c - 1, obstacleGrid, dp);

        if(r > 0 && obstacleGrid[r - 1][c] == 0)
            up = rec(r - 1, c, obstacleGrid, dp);
        return dp[r][c] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return rec(n - 1, m- 1, obstacleGrid, dp);
    }
};

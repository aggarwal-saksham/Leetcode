/*
 * Problem #64: Minimum Path Sum
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/27/2026, 2:44:13 PM
 * Link: https://leetcode.com/problems/minimum-path-sum/
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[0][0] = grid[0][0];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 && j == 0) continue;
                int right  = 1e9, down = 1e9;
                if(i > 0) down = grid[i][j] + dp[i - 1][j];
                if(j > 0) right = grid[i][j] + dp[i][j - 1];
                dp[i][j] = min(right, down);
            }
        }
        return dp[n-1][m-1];
    }
};

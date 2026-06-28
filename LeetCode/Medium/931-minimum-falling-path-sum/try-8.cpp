/*
 * Problem #931: Minimum Falling Path Sum
 * Difficulty: Medium
 * Submission: Try 8
 * status: Accepted
 * Language: cpp
 * Date: 6/27/2026, 5:06:37 PM
 * Link: https://leetcode.com/problems/minimum-falling-path-sum/
 */

class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        int n = matrix.size();
        int m = matrix[0].size();

        if(j >= m || j < 0) return 1e9;
        if(i == n - 1) return matrix[i][j];

        if(dp[i][j] != -1e9) return dp[i][j];

        int diagR = matrix[i][j] + rec(i + 1, j + 1, matrix, dp);
        int diagL = matrix[i][j] + rec(i + 1, j - 1, matrix, dp);
        int down = matrix[i][j] + rec(i + 1, j, matrix, dp);

        return dp[i][j] = min({diagL, diagR, down}); 
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1e9));
        int ans = 1e9;
        for(int j = 0; j < m; j++){
            ans = min(ans, rec(0, j, matrix, dp));
        }
        return ans;
    }
};

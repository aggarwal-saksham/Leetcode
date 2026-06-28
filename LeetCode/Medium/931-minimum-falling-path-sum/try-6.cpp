/*
 * Problem #931: Minimum Falling Path Sum
 * Difficulty: Medium
 * Submission: Try 6
 * status: Accepted
 * Language: cpp
 * Date: 6/27/2026, 4:39:31 PM
 * Link: https://leetcode.com/problems/minimum-falling-path-sum/
 */

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[n-1] = matrix[n-1];
        for(int i = n - 2; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int diagL = 1e9, diagR = 1e9;
                int up = matrix[i][j] + dp[i + 1][j];
                if(j < m - 1)  diagR = matrix[i][j] + dp[i + 1][j + 1];
                if(j > 0)  diagL = matrix[i][j] + dp[i + 1][j - 1];
                dp[i][j] = min({up, diagL, diagR});
            }
        }
        int ans = 1e9;
        for(int a : dp[0]){
            ans = min(a, ans);
        }
        return ans;
    }
};

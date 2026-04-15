/*
 * Problem #931: Minimum Falling Path Sum
 * Difficulty: Medium
 * Submission: Try 5
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2025, 5:32:01 PM
 * Link: https://leetcode.com/problems/minimum-falling-path-sum/
 */

class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1e9));

        for (int j = 0; j < n; j++) {
            dp[m - 1][j] = matrix[m - 1][j];
        }

        for(int i = m - 2; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int up = dp[i + 1][j];

                int leftdiag = (j >= 1) ? dp[i + 1][j - 1] : 1e9;

                int rightdiag = (j <= n - 2) ? dp[i + 1][j + 1] : 1e9;

                dp[i][j] = matrix[i][j] + min({up, leftdiag, rightdiag});
            }
        }

        int mini = 1e9;
       
        for(int j = 0; j < n; j++){
            mini = min(mini, dp[0][j]);
        }

        return mini;
    }
};

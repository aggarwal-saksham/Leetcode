/*
 * Problem #62: Unique Paths
 * Difficulty: Medium
 * Submission: Try 5
 * status: Accepted
 * Language: cpp
 * Date: 6/27/2026, 12:42:07 PM
 * Link: https://leetcode.com/problems/unique-paths/
 */

class Solution {
public:
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;
                int right  = 0, down = 0;
                if(j > 0) right = dp[i][j - 1];
                if(i > 0) down = dp[i - 1][j];
                dp[i][j] = right + down;
            }
        }
        return dp[m - 1][n - 1];
    }
};

/*
 * Problem #62: Unique Paths
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/27/2026, 12:22:56 PM
 * Link: https://leetcode.com/problems/unique-paths/
 */

class Solution {
public:
    int rec(int r, int c, int &m, int &n, vector<vector<int>> &dp){
        if(r == 0 && c == 0) return 1;
        if(r < 0 || c < 0) return 0; 
        if(dp[r][c] != -1) return dp[r][c];
        int left = rec(r, c - 1, m , n, dp);
        int up = rec(r - 1, c, m , n, dp);
        return dp[r][c] = left + up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return rec(n - 1, m- 1, m, n, dp);
    }
};

/*
 * Problem #3989: Maximum Consistent Columns in a Grid
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/12/2026, 8:40:23 AM
 * Link: https://leetcode.com/problems/maximum-consistent-columns-in-a-grid/
 */

class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m, 1);
        int ans = 1;

        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < i; j++){
                bool f = true;
                for(int k = 0; k < n && f; k++){
                    if(abs(grid[k][j] - grid[k][i]) > limit)f = false;
                }
                if(f) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

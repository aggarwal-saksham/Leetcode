/*
 * Problem #3882: Minimum XOR Path in a Grid
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/28/2026, 8:27:57 PM
 * Link: https://leetcode.com/problems/minimum-xor-path-in-a-grid/
 */

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) {
                    dp[i][j].push_back(grid[0][0]);
                } 
                else {
                    if (i > 0) {
                        for (auto x : dp[i - 1][j])
                            dp[i][j].push_back(x ^ grid[i][j]);
                    }
                    if (j > 0) {
                        for (auto x : dp[i][j - 1])
                            dp[i][j].push_back(x ^ grid[i][j]);
                    }

                    sort(dp[i][j].begin(), dp[i][j].end());
                    dp[i][j].erase(unique(dp[i][j].begin(), dp[i][j].end()), dp[i][j].end());
                }
            }
        }

        int ans = 1e9;
        for (auto x : dp[m - 1][n - 1])
            ans = min(ans, x);

        return ans;
    }
};

/*
 * Problem #120: Triangle
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2025, 4:46:07 PM
 * Link: https://leetcode.com/problems/triangle/
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int j = 0; j < n; j++) {
            dp[m - 1][j] = triangle[m - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {

                dp[i][j] = min(triangle[i][j] + dp[i + 1][j],
                               triangle[i][j] + dp[i + 1][j + 1]);
            }
        }

        return dp[0][0];
    }
};

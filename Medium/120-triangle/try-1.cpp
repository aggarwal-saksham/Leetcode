/*
 * Problem #120: Triangle
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/5/2025, 3:19:24 PM
 * Link: https://leetcode.com/problems/triangle/
 */

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp,
              vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();

        if (i > m - 1 || j > i)
            return 1e9;

        if (i == m - 1)
            return triangle[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] =
                   min(triangle[i][j] + solve(i + 1, j, dp, triangle),
                       triangle[i][j] + solve(i + 1, j + 1, dp, triangle));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, dp, triangle);
    }
};

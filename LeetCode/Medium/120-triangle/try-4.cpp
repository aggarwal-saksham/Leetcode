/*
 * Problem #120: Triangle
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/27/2026, 4:30:31 PM
 * Link: https://leetcode.com/problems/triangle/
 */

class Solution {
public:
   
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[n-1] = triangle[n-1];
        for(int i = n - 2; i >= 0; i--){
            for(int j = triangle[i].size() - 1; j >= 0; j--){
                int up = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][ j + 1];
                dp[i][j] = min(up, diag);
            }
        }

        return dp[0][0];


    }
};

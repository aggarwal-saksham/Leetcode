/*
 * Problem #221: Maximal Square
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/26/2026, 7:50:32 PM
 * Link: https://leetcode.com/problems/maximal-square/
 */

class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m));
        for(int i = 0; i <n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = matrix[i][j] - '0';
                    ans = max(ans, dp[i][j] * dp[i][j]);
                    continue;
                }
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                    ans = max(ans, dp[i][j] * dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        return ans;
    }
};

/*
 * Problem #1143: Longest Common Subsequence
 * Difficulty: Medium
 * Submission: Try 5
 * status: Accepted
 * Language: cpp
 * Date: 6/29/2026, 2:34:08 PM
 * Link: https://leetcode.com/problems/longest-common-subsequence/
 */

class Solution {
public:
    int rec(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int take = 0, notake = 0;
        if(s1[i] == s2[j]){
            take = 1 + rec(i - 1, j - 1, s1, s2, dp);
        }
        else{
            notake = max(rec(i - 1, j, s1, s2, dp), rec(i, j - 1, s1, s2,dp));
        }
        return dp[i][j] =  max(take, notake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        for(int j = 1; j <= m; j++){
            dp[0][j] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

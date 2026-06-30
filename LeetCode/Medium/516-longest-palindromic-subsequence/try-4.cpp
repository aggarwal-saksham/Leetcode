/*
 * Problem #516: Longest Palindromic Subsequence
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/29/2026, 5:50:10 PM
 * Link: https://leetcode.com/problems/longest-palindromic-subsequence/
 */

class Solution {
public:
    int longestCommonSubsequence(string &s) {
        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        for(int j = 1; j <= n; j++){
            dp[0][j] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == s[n - j]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][n];
    }
    int longestPalindromeSubseq(string s) {
        
        return longestCommonSubsequence(s);
    }
};

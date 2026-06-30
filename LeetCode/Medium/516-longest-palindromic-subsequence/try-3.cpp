/*
 * Problem #516: Longest Palindromic Subsequence
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/29/2026, 5:48:05 PM
 * Link: https://leetcode.com/problems/longest-palindromic-subsequence/
 */

class Solution {
public:
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
                if(text1[i - 1] == text2[m - j]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        
        return longestCommonSubsequence(s, s);
    }
};

/*
 * Problem #1143: Longest Common Subsequence
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/29/2026, 11:50:24 AM
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
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return rec(m - 1, n - 1, text1, text2, dp);
    }
};

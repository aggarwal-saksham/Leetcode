/*
 * Problem #1143: Longest Common Subsequence
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/9/2025, 7:59:21 PM
 * Link: https://leetcode.com/problems/longest-common-subsequence/
 */

class Solution {
public:
    int lcs(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp){
        if(idx1 < 0 || idx2 < 0) return 0;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(s1[idx1] == s2[idx2]){
            return dp[idx1][idx2] =  1 + lcs(idx1 - 1, idx2 - 1, s1, s2, dp);
        }

        else{
            return dp[idx1][idx2] = max(lcs(idx1, idx2 - 1, s1, s2, dp), lcs(idx1 - 1, idx2, s1, s2, dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return lcs(m - 1, n - 1, text1, text2, dp);
    }
};

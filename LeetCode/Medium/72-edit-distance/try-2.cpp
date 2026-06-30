/*
 * Problem #72: Edit Distance
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2026, 3:17:31 PM
 * Link: https://leetcode.com/problems/edit-distance/
 */

class Solution {
public:
    int rec(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = rec(i - 1, j - 1, word1, word2, dp);
        int insert = 1 + rec(i, j - 1, word1, word2, dp);
        int replace = 1 + rec(i - 1, j - 1, word1, word2, dp);
        int del = 1 + rec(i - 1, j, word1, word2, dp);
        return dp[i][j] =  min({insert, replace, del});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return rec(n - 1, m - 1, word1, word2, dp);

    }
};

/*
 * Problem #72: Edit Distance
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 7/12/2026, 11:39:17 PM
 * Link: https://leetcode.com/problems/edit-distance/
 */

class Solution {
public:
    int rec(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return 0;
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            return dp[i][j] = rec(word1, word2, i - 1, j - 1, dp);
        }
        else{
            int replace = 1 + rec(word1, word2, i - 1, j - 1, dp);
            int insert = 1 + rec(word1, word2, i, j - 1, dp);
            int del = 1 + rec(word1, word2, i - 1, j, dp);
            return dp[i][j] = min({replace, insert, del});
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m , -1));
        return rec(word1, word2, n  -1, m - 1, dp);
    }
};

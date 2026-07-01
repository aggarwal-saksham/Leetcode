/*
 * Problem #72: Edit Distance
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2026, 3:24:49 PM
 * Link: https://leetcode.com/problems/edit-distance/
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for(int i = 0; i <= n; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j <= m; j++){
            dp[0][j] = j;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else{
                    int insert = 1 + dp[i][j - 1];
                    int replace = 1 + dp[i - 1][j - 1];
                    int del = 1 + dp[i - 1][j];
                    dp[i][j] =  min({insert, replace, del});
                }
            }
        }
        return dp[n][m];

    }
};

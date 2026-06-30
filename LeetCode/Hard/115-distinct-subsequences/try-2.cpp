/*
 * Problem #115: Distinct Subsequences
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2026, 1:03:25 PM
 * Link: https://leetcode.com/problems/distinct-subsequences/
 */

class Solution {
public:
    int rec(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j]){
            return dp[i][j] = rec(i - 1, j - 1, s, t, dp) + rec(i - 1, j, s, t, dp);
        }
        else return dp[i][j] = rec(i - 1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return rec(n - 1, m - 1, s, t, dp);
    }
};

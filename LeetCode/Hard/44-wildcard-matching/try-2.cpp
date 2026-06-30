/*
 * Problem #44: Wildcard Matching
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2026, 2:00:33 PM
 * Link: https://leetcode.com/problems/wildcard-matching/
 */

class Solution {
public:
    bool rec(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true;
        if(i >= 0 && j < 0) return false;
        if(i < 0 && j >= 0){
            for(int  k = j; k >= 0; k--){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(p[j] == '*'){
             if(rec(i, j - 1, s, p, dp) || rec(i  -1, j, s, p, dp)) return dp[i][j] = true;
        }
        else if(p[j] == '?' || p[j] == s[i]){
             if(rec(i - 1, j - 1, s, p, dp)) return dp[i][j] = true;
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return rec(n - 1, m - 1, s, p, dp);
    }
};

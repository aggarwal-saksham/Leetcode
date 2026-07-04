/*
 * Problem #115: Distinct Subsequences
 * Difficulty: Hard
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2026, 1:32:57 PM
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
        vector<vector<double>> dp(n, vector<double>(m, -1));
        dp[0][0] = (s[0] == t[0]);
        for(int i = 1; i < n; i++){
            dp[i][0] = t[0] == s[i] ? 1 + dp[i - 1][0] : dp[i - 1][0];
        }
        for(int j = 1; j < m; j++){
            dp[0][j] = 0;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return (int)dp[n - 1][m - 1];
    }
};

/*
 * Problem #1312: Minimum Insertion Steps to Make a String Palindrome
 * Difficulty: Hard
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/29/2026, 5:53:51 PM
 * Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
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
                if(text1[i - 1] == text2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
    //leetcode
    //edocteel
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(s.begin(), s.end());
        return n - longestCommonSubsequence(t, s);
    }
};

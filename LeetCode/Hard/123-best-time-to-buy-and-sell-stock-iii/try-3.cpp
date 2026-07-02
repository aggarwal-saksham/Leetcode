/*
 * Problem #123: Best Time to Buy and Sell Stock III
 * Difficulty: Hard
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2026, 10:21:43 PM
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(5, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 4; j++) {
                if (j == 0) {
                    dp[i][j] = 0;
                } 
                else if (j == 2 || j == 4) {
                    int buy = -prices[i] + dp[i + 1][j - 1];
                    int leave = dp[i + 1][j];
                    dp[i][j] = max(buy, leave);
                } 
                else {
                    int sell = prices[i] + dp[i + 1][j - 1];
                    int leave = dp[i + 1][j];
                    dp[i][j] = max(sell, leave);
                }
            }
        }

        return dp[0][4];
    }
};

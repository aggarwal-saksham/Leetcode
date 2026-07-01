/*
 * Problem #309: Best Time to Buy and Sell Stock with Cooldown
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2026, 10:25:46 PM
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k <= 2; k++) {
                if (k == 0) {
                    dp[i][k] = 0;
                } 
                else if (k == 2) {
                    int buy = -prices[i] + dp[i + 1][k - 1];
                    int leave = dp[i + 1][k];
                    dp[i][k] = max(buy, leave);
                } 
                else {
                    int sell = prices[i] + dp[i + 2][k + 1];
                    int leave = dp[i + 1][k];
                    dp[i][k] = max(sell, leave);
                }
            }
        }

        return dp[0][2];
    }
};

/*
 * Problem #714: Best Time to Buy and Sell Stock with Transaction Fee
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/2/2025, 12:45:25 AM
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int buy = 0; buy < 2; buy++) {
            dp[n][buy] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                if (buy) {
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } 
                else {
                    dp[i][buy] = max(prices[i] + dp[i + 1][1] - fee, dp[i + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

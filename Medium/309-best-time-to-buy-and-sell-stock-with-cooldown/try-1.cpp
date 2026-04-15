/*
 * Problem #309: Best Time to Buy and Sell Stock with Cooldown
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/2/2025, 12:43:32 AM
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int buy = 0; buy < 2; buy++) {
            dp[n][buy] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                if (buy) {
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } 
                else {
                    dp[i][buy] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

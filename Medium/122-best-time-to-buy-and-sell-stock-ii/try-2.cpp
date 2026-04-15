/*
 * Problem #122: Best Time to Buy and Sell Stock II
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 3/23/2026, 8:45:47 AM
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
                    dp[i][buy] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

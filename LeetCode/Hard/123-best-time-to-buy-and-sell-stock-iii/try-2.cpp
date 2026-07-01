/*
 * Problem #123: Best Time to Buy and Sell Stock III
 * Difficulty: Hard
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2026, 7:59:50 PM
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 */

class Solution {
public:
    int rec(int i, int k, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size())
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        if (k == 0) {
            return 0;
        } 
        else if (k == 4 || k == 2) {
            int buy = -prices[i] + rec(i + 1, k - 1, prices, dp);
            int leave = rec(i + 1, k, prices, dp);
            return dp[i][k] = max(buy, leave);
        } 
        else {
            int sell = prices[i] + rec(i + 1, k - 1, prices, dp);
            int leave = rec(i + 1, k, prices, dp);
            return dp[i][k] = max(sell, leave);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5, -1));
        return rec(0, 4, prices, dp);
    }
};

/*
 * Problem #714: Best Time to Buy and Sell Stock with Transaction Fee
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2026, 10:11:13 PM
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 */

class Solution {
public:
    int rec(int i, int k, vector<int>& prices, vector<vector<int>>& dp, int &fee) {
        if (i == prices.size())
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        if (k == 0) {
            return 0;
        } 
        else if (k == 2) {
            int buy = -prices[i] + rec(i + 1, k - 1, prices, dp, fee);
            int leave = rec(i + 1, k, prices, dp, fee);
            return dp[i][k] = max(buy, leave);
        } 
        else {
            int sell = -fee + prices[i] + rec(i + 1, k + 1, prices, dp, fee);
            int leave = rec(i + 1, k, prices, dp, fee);
            return dp[i][k] = max(sell, leave);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, -1));
        return rec(0, 2, prices, dp, fee);
    }
};

/*
 * Problem #121: Best Time to Buy and Sell Stock
 * Difficulty: Easy
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/22/2025, 4:45:20 PM
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = 1e9;
        int profit = 0;
        for(int i = 0; i < n; i++){
            mini = min(mini, prices[i]);
            profit = max(profit, prices[i] - mini);
        }
        return profit;
    }
};

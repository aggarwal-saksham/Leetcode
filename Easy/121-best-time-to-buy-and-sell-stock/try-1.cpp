/*
 * Problem #121: Best Time to Buy and Sell Stock
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/10/2024, 3:44:43 PM
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        for(int  i = 0; i < prices.size(); i++){
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini,prices[i]);
        }
        return profit;
    }
};

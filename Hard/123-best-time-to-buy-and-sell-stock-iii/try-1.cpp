/*
 * Problem #123: Best Time to Buy and Sell Stock III
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/2/2025, 12:16:38 AM
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int buy = 0; buy < 2; buy++) {
            dp[n][buy][0] = 0;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int cap = 1; cap < 3; cap++) {
                    if (buy) {
                        dp[i][buy][cap] = max(-prices[i] + dp[i + 1][0][cap],
                                              dp[i + 1][1][cap]);
                    } 
                    else {
                        dp[i][buy][cap] = max(prices[i] + dp[i + 1][1][cap - 1],
                                              dp[i + 1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};

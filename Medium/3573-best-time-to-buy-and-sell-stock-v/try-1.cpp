/*
 * Problem #3573: Best Time to Buy and Sell Stock V
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/7/2025, 9:27:14 PM
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/
 */

class Solution {
public:
    long long maximumProfit(vector<int>& a, int k) {
        int n = a.size();
        vector<vector<long long>> dp(k + 1, vector<long long>(3, LLONG_MIN));
        for (int i = 0; i <= k; ++i)
            dp[i][0] = 0;

        for (int p : a) {
            for (int i = k; i > 0; --i) {
                if (dp[i][1] != LLONG_MIN)
                    dp[i][0] = max(dp[i][0], dp[i][1] + p);
                if (dp[i][2] != LLONG_MIN)
                    dp[i][0] = max(dp[i][0], dp[i][2] - p);
                dp[i][1] = max(dp[i][1], dp[i - 1][0] - p);
                dp[i][2] = max(dp[i][2], dp[i - 1][0] + p);
            }
        }

        long long res = 0;
        for (int i = 0; i <= k; ++i)
            res = max(res, dp[i][0]);
        return res;
    }
};

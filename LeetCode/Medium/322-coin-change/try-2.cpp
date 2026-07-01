/*
 * Problem #322: Coin Change
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/28/2026, 9:05:53 PM
 * Link: https://leetcode.com/problems/coin-change/
 */

class Solution {
public:
    int rec(int i, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(target == 0) return 0;
        if(target < 0) return 1e9;
        if(i < 0) return 1e9;
        if(dp[i][target] != -1) return dp[i][target];
        return dp[i][target] = min(1 + rec(i, target - arr[i], arr, dp), rec(i - 1, target, arr, dp));
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return rec(n - 1, amount, coins, dp) >= 1e9 ? -1 : rec(n - 1, amount, coins, dp);
    }
};

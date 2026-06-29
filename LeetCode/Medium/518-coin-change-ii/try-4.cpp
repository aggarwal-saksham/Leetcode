/*
 * Problem #518: Coin Change II
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/28/2026, 11:40:59 PM
 * Link: https://leetcode.com/problems/coin-change-ii/
 */

class Solution {
public:
    int rec(int i, vector<int> &arr, int target, vector<vector<uint64_t>> &dp){
        if(i < 0) return target == 0;
        if(target < 0) return 0;

        if(dp[i][target] != -1) return dp[i][target];

        return dp[i][target] = rec(i, arr, target - arr[i], dp) +
                            rec(i - 1, arr, target, dp);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<uint64_t>> dp(n, vector<uint64_t>(amount + 1, -1));
        return rec(n - 1, coins, amount, dp);
    }
};

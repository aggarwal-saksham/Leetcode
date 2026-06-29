/*
 * Problem #322: Coin Change
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/28/2026, 11:24:51 PM
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
        for(int i = 0; i < n; i++){
            dp[i][0] = 0;
        }
        for(int j = 1; j <= amount; j++){
            if(j % coins[0] == 0) dp[0][j] = j / coins[0];
            else dp[0][j] = 1e9;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= amount ;j++){
                int take = 1e9;
                if(coins[i] <= j) take = 1 + dp[i][j - coins[i]];
                int notake = dp[i - 1][j];
                dp[i][j] = min(take, notake);
            }
        }
        return dp[n - 1][amount] >= 1e9 ? -1 : dp[n - 1][amount];
    }
};

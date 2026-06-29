/*
 * Problem #518: Coin Change II
 * Difficulty: Medium
 * Submission: Try 5
 * status: Accepted
 * Language: cpp
 * Date: 6/28/2026, 11:51:53 PM
 * Link: https://leetcode.com/problems/coin-change-ii/
 */

class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<uint64_t>> dp(n, vector<uint64_t>(amount + 1, -1));
        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }
        for(int j = 1; j <= amount; j++){
            if(j % coins[0] == 0) dp[0][j] = 1;
            else dp[0][j] = 0;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= amount ;j++){
                uint64_t take = 0;
                if(coins[i] <= j) take = dp[i][j - coins[i]];
                uint64_t notake = dp[i - 1][j];
                dp[i][j] = take + notake;
            }
        }
        return dp[n - 1][amount];
    }
};

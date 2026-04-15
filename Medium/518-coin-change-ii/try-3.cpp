/*
 * Problem #518: Coin Change II
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/8/2025, 11:48:20 PM
 * Link: https://leetcode.com/problems/coin-change-ii/
 */

class Solution {
public:
   int countSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<uint64_t>> dp(n, vector<uint64_t>(sum+ 1, 0));
        
        for(int j = 0; j <= sum; j++){
            if(j % arr[0] == 0){
                dp[0][j] = 1;
            }
        }
        for(int i = 1; i < n; i++){
            
            for(int j = 0; j <= sum; j++){
                uint64_t notake = dp[i - 1][j];
                
                uint64_t take = 0;
                if(arr[i] <= j){
                    take = dp[i][j - arr[i]];
                }
                
                dp[i][j] = take + notake;
            }
        }
        
        return dp[n - 1][sum];
    }
    int change(int amount, vector<int>& coins) {
        return countSum(coins, amount);
    }
};

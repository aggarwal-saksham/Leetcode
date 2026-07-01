/*
 * Problem #494: Target Sum
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/28/2026, 7:50:09 PM
 * Link: https://leetcode.com/problems/target-sum/
 */

class Solution {
public:
    int perfectSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+ 1, 0));
        
        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }
        if (arr[0] <= sum) {
            dp[0][arr[0]] += 1;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= sum; j++){
                int notake = dp[i - 1][j];
                
                int take = 0;
                if(arr[i] <= j){
                    take = dp[i - 1][j - arr[i]];
                }
                
                dp[i][j] = take + notake;
            }
        }
        
        return dp[n - 1][sum];
    }
    int findTargetSumWays(vector<int>& arr, int diff) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        if(abs(diff) > total) return 0;
        if((total + diff) & 1) return 0;
        return perfectSum(arr, (total + diff) / 2);
    }
};

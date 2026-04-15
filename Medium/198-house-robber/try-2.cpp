/*
 * Problem #198: House Robber
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/4/2025, 2:35:39 AM
 * Link: https://leetcode.com/problems/house-robber/
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            int take = nums[i];
            if(i > 1) take += dp[i - 2];

            int notake = dp[i - 1];

            dp[i] = max(take, notake);
        }
        return dp[n - 1];
    }
};

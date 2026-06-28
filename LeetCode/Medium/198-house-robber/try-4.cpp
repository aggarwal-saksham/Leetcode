/*
 * Problem #198: House Robber
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/27/2026, 12:09:43 AM
 * Link: https://leetcode.com/problems/house-robber/
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2, 0);

        for(int i = n - 1; i >= 0; i--) {
            int take = nums[i] + dp[i + 2];
            int noTake = dp[i + 1];
            dp[i] = max(take, noTake);
        }

        return dp[0];
    }
};

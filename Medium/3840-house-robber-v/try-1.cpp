/*
 * Problem #3840: House Robber V
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/14/2026, 8:33:39 PM
 * Link: https://leetcode.com/problems/house-robber-v/
 */

class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        vector<long long> dp(n, -1);

        dp[0] = nums[0];

        for (int i = 1; i < n; i++) {
            long long take = nums[i];

            if (colors[i] == colors[i - 1]) {
                if (i > 1)
                    take += dp[i - 2];
            } else {
                take += dp[i - 1];
            }

            long long notake = dp[i - 1];

            dp[i] = max(take, notake);
        }

        return dp[n - 1];
    }
};

/*
 * Problem #213: House Robber II
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/4/2025, 7:27:53 PM
 * Link: https://leetcode.com/problems/house-robber-ii/
 */

class Solution {
public:
    int rec(vector<int>& nums, int n, vector<int>& dp) {
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if (i > 1)
                take += dp[i - 2];

            int notake = dp[i - 1];

            dp[i] = max(take, notake);;
        }
        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> num1(nums.begin(), nums.end() - 1);
        vector<int> num2(nums.begin() + 1, nums.end());

        vector<int> dp1(num1.size() + 1, -1);
        vector<int> dp2(num2.size() + 1, -1);

        return max(rec(num1, num1.size(), dp1), rec(num2, num2.size(), dp2));
    }
};

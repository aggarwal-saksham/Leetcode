/*
 * Problem #300: Longest Increasing Subsequence
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/14/2025, 3:20:23 PM
 * Link: https://leetcode.com/problems/longest-increasing-subsequence/
 */

class Solution {
public:
    int solve(int idx, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx == nums.size())
            return 0;

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int take = 0;
        if (prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + solve(idx + 1, idx, nums, dp);
        }

        int notake = solve(idx + 1, prev, nums, dp);

        return dp[idx][prev + 1] = max(take, notake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, -1, nums, dp);
    }
};

/*
 * Problem #300: Longest Increasing Subsequence
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2026, 11:29:51 PM
 * Link: https://leetcode.com/problems/longest-increasing-subsequence/
 */

class Solution {
public:
    int rec(int i, int prevIdx, vector<int>& nums, vector<vector<int>> &dp){
        if(i == nums.size()) return 0;

        if(dp[i][prevIdx + 1] != -1) return dp[i][prevIdx + 1];

        if(prevIdx == -1 || nums[i] > nums[prevIdx]){
            return dp[i][prevIdx + 1] = max(
                1 + rec(i + 1, i, nums, dp),
                rec(i + 1, prevIdx, nums, dp)
            );
        }

        return dp[i][prevIdx + 1] = rec(i + 1, prevIdx, nums, dp);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return rec(0, -1, nums, dp);
    }
};

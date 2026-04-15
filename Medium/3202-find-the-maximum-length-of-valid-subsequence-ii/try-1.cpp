/*
 * Problem #3202: Find the Maximum Length of Valid Subsequence II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/16/2025, 7:49:07 PM
 * Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/
 */

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, 1));
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int x = (nums[i] + nums[j]) % k;
                dp[i][x] = max(dp[i][x], dp[j][x] + 1);
                maxi = max(maxi, dp[i][x]);
            }
        }
        return maxi;
    }
};

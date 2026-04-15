/*
 * Problem #1027: Longest Arithmetic Subsequence
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/17/2025, 12:36:29 AM
 * Link: https://leetcode.com/problems/longest-arithmetic-subsequence/
 */

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1001, 1));
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int x = nums[j] - nums[i] + 500;
                dp[i][x] = max(dp[i][x], dp[j][x] + 1);
                maxi = max(maxi, dp[i][x]);
            }
        }
        return maxi;
    }
};

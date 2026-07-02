/*
 * Problem #300: Longest Increasing Subsequence
 * Difficulty: Medium
 * Submission: Try 5
 * status: Accepted
 * Language: cpp
 * Date: 6/30/2026, 11:49:31 PM
 * Link: https://leetcode.com/problems/longest-increasing-subsequence/
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = n - 1; i >= 0; i --){
            for(int prev = i - 1; prev >= -1; prev--){
                if(prev == -1 || nums[i] > nums[prev]){
                    dp[i][prev + 1] = max(dp[i + 1][prev+ 1], 1 + dp[i + 1][i + 1]);
                }
                else dp[i][prev + 1] = dp[i + 1][prev+ 1];
            }
        }

        return dp[0][0];
    }
};

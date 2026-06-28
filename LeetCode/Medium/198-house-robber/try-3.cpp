/*
 * Problem #198: House Robber
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/26/2026, 11:59:56 PM
 * Link: https://leetcode.com/problems/house-robber/
 */

class Solution {
public:
    int rec(int i, vector<int> &nums, vector<int> &dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + rec(i + 2, nums, dp);
        int noTake = rec(i + 1, nums, dp);
        return dp[i] = max(take, noTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , -1);
        
        return rec(0, nums, dp);
    }
};

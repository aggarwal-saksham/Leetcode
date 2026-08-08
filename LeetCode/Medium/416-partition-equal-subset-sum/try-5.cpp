/*
 * Problem #416: Partition Equal Subset Sum
 * Difficulty: Medium
 * Submission: Try 5
 * status: Accepted
 * Language: cpp
 * Date: 8/5/2026, 3:08:36 PM
 * Link: https://leetcode.com/problems/partition-equal-subset-sum/
 */

class Solution {
public:
    bool rec(vector<int>& nums, int target, int idx, vector<vector<int>> &dp){
        if(idx == nums.size()){
            return target == 0;
        }
        if(target == 0){
            return true;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        bool take = false;
        if(target >= nums[idx]){
            take = rec(nums, target - nums[idx], idx + 1, dp);
        }
        bool noTake= rec(nums, target, idx + 1, dp);
        return dp[idx][target] = take | noTake;
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(1 + total / 2, -1));
        return rec(nums, total / 2, 0, dp);
    }
};

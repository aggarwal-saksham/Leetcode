/*
 * Problem #39: Combination Sum
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/7/2026, 8:15:48 PM
 * Link: https://leetcode.com/problems/combination-sum/
 */

class Solution {
public:
    void backtrack(vector<int>& nums, vector<int> &curr, int idx, int target, vector<vector<int>> &ans){
        if(target < 0) return;
        if(idx == nums.size()){
            if(target == 0) ans.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        backtrack(nums, curr, idx, target - nums[idx], ans);
        curr.pop_back();

        backtrack(nums, curr, idx + 1, target, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(nums, curr, 0, target, ans);
        return ans;
    }
};

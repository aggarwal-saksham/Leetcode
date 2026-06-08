/*
 * Problem #40: Combination Sum II
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/8/2026, 12:49:44 AM
 * Link: https://leetcode.com/problems/combination-sum-ii/
 */

class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& curr, int idx, int target, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int j = idx; j < nums.size(); j++) {
            if (j > idx && nums[j] == nums[j - 1]) {
                continue;
            }

            if (nums[j] > target) {
                break;
            }

            curr.push_back(nums[j]);
            backtrack(nums, curr, j + 1, target - nums[j], ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        backtrack(nums, curr, 0, target, ans);

        return ans;
    }
};

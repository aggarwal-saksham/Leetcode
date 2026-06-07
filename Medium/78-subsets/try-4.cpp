/*
 * Problem #78: Subsets
 * Difficulty: Medium
 * Submission: Try 4
 * status: Accepted
 * Language: cpp
 * Date: 6/7/2026, 7:34:36 PM
 * Link: https://leetcode.com/problems/subsets/
 */

class Solution {
public:
    void backtrack(vector<int>& nums, vector<int> &curr, int idx, vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        backtrack(nums, curr, idx + 1, ans);
        curr.pop_back();

        backtrack(nums, curr, idx + 1, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(nums, curr, 0, ans);
        return ans;
    }
};

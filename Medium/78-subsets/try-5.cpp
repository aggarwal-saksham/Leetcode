/*
 * Problem #78: Subsets
 * Difficulty: Medium
 * Submission: Try 5
 * status: Accepted
 * Language: cpp
 * Date: 6/8/2026, 1:48:04 AM
 * Link: https://leetcode.com/problems/subsets/
 */

class Solution {
public:
    void backtrack(vector<int>& nums, vector<int> &curr, int idx, vector<vector<int>> &ans){
        ans.push_back(curr);

        for(int j = idx; j < nums.size(); j++){
            curr.push_back(nums[j]);
            backtrack(nums, curr, j + 1, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(nums, curr, 0, ans);
        return ans;
    }
};

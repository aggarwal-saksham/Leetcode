/*
 * Problem #90: Subsets II
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 6/8/2026, 1:50:16 AM
 * Link: https://leetcode.com/problems/subsets-ii/
 */

class Solution {
public:
    void backtrack(vector<int>& nums, int idx, vector<int> &curr, vector<vector<int>> &ans){
        ans.push_back(curr);

        for(int j = idx; j < nums.size(); j++){
            if(j != idx && nums[j] == nums[j - 1]) continue;
            curr.push_back(nums[j]);
            backtrack(nums, j + 1, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(nums, 0, curr, ans);
        return ans;
    }
};

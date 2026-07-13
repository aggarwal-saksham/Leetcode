/*
 * Problem #46: Permutations
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/13/2026, 12:23:29 AM
 * Link: https://leetcode.com/problems/permutations/
 */

class Solution {
public:
    void backtrack(vector<int> &curr, vector<vector<int>> &ans, vector<int>& nums, vector<int> &vis){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int j = 0; j < nums.size(); j++){
            if(vis[j]) continue;
            
            vis[j] = 1;
            curr.push_back(nums[j]);
            backtrack(curr, ans, nums, vis);
            curr.pop_back();
            vis[j] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> curr;
        vector<int> vis(n, 0);
        backtrack(curr, ans, nums, vis);
        return ans;
    }
};

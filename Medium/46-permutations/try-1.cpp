/*
 * Problem #46: Permutations
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/15/2024, 7:56:50 PM
 * Link: https://leetcode.com/problems/permutations/
 */

class Solution {
public:
    void helper(vector<int> &nums, map<int, int> &mp,
                vector<vector<int>> &ans,
                vector<int> &perm){
        if(perm.size() == nums.size()){
            ans.push_back(perm);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(mp[nums[i]] == 0){
                mp[nums[i]] = 1;
                perm.push_back(nums[i]);
                helper(nums, mp, ans, perm);
                mp[nums[i]] = 0;
                perm.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mp[i] = 0;
        }
        vector<vector<int>> ans;
        vector<int> perm;
        helper(nums, mp, ans, perm);
        return ans;
    }
};

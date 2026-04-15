/*
 * Problem #47: Permutations II
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/1/2025, 11:16:28 PM
 * Link: https://leetcode.com/problems/permutations-ii/
 */

class Solution {
public:
    void backtrack(vector<int>& nums, unordered_map<int, int>& freq,
                   unordered_map<int, int>& mp, set<vector<int>>& ans,
                   vector<int>& perm) {
        if (perm.size() == nums.size()) {
            ans.insert(perm);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]] < freq[nums[i]]) {
                mp[nums[i]]++;
                perm.push_back(nums[i]);
                backtrack(nums, freq, mp, ans, perm);
                mp[nums[i]]--;
                perm.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        unordered_map<int, int> mp;
        set<vector<int>> ans;
        vector<int> perm;
        backtrack(nums, freq, mp, ans, perm);

        vector<vector<int>> res;
        for(auto i : ans){
            res.push_back(i);
        }
        return res;
    }
};

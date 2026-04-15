/*
 * Problem #3810: Minimum Operations to Reach Target Array
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/17/2026, 8:20:25 PM
 * Link: https://leetcode.com/problems/minimum-operations-to-reach-target-array/
 */

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != target[i]) mpp[nums[i]]++;
        }
        int ans = mpp.size();
        //for(auto it : mpp) ans += it.second;
        return ans;
    }
};

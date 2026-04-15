/*
 * Problem #1: Two Sum
 * Difficulty: Easy
 * Submission: Try 6
 * status: Accepted
 * Language: cpp
 * Date: 4/15/2026, 6:47:53 PM
 * Link: https://leetcode.com/problems/two-sum/
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            mpp[nums[i]] = i;

        }
        for(int i = 0; i < n; i++){
            if(mpp.find(target - nums[i]) != mpp.end() && i != mpp[target - nums[i]]){
                return {i, mpp[target - nums[i]]};
            }
        }
        return {0, 0};
    }
};

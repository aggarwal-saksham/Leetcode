/*
 * Problem #217: Contains Duplicate
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/6/2025, 12:32:37 AM
 * Link: https://leetcode.com/problems/contains-duplicate/
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int num : nums){
            mpp[num]++;
        }
        for(auto it : mpp){
            if(it.second >= 2) return true;
        }
        return false;
    }
};

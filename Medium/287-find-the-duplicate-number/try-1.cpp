/*
 * Problem #287: Find the Duplicate Number
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/22/2025, 8:14:45 PM
 * Link: https://leetcode.com/problems/find-the-duplicate-number/
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int num : nums){
            mpp[num]++;
        }

        for(auto it : mpp){
            if(it.second > 1) return it.first;
        }
        return -1;
    }
};

/*
 * Problem #2161: Partition Array According to Given Pivot
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/8/2026, 5:14:56 PM
 * Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/
 */

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < pivot) ans.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == pivot) ans.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > pivot) ans.push_back(nums[i]);
        }

        return ans;
    }
};

/*
 * Problem #3819: Rotate Non Negative Elements
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/25/2026, 4:27:43 PM
 * Link: https://leetcode.com/problems/rotate-non-negative-elements/
 */

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> copy = nums;
        vector<int> nonneg;

        for(int x : nums){
            if(x >= 0) nonneg.push_back(x);
        }

        int pos = nonneg.size();
        if(pos == 0) return nums;

        k %= pos;

        int idx = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                copy[i] = nonneg[(idx + k) % pos];
                idx++;
            }
        }
        return copy;
    }
};


/*
 * Problem #3925: Concatenate Array With Reverse
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/20/2026, 12:59:17 AM
 * Link: https://leetcode.com/problems/concatenate-array-with-reverse/
 */

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans = nums;
        int n = nums.size();
        int l  = n  - 1;
        while(l >= 0){
            ans.push_back(nums[l]);
            l--;
        }
        return ans;
    }
};

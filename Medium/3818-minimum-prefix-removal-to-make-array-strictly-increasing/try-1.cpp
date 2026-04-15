/*
 * Problem #3818: Minimum Prefix Removal to Make Array Strictly Increasing
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/25/2026, 4:08:31 PM
 * Link: https://leetcode.com/problems/minimum-prefix-removal-to-make-array-strictly-increasing/
 */

class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int i;
        for( i = n - 1; i > 0; i--){
            if(nums[i -1] >= nums[i]) break;
        }
        return i;
    }
};

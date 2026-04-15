/*
 * Problem #3828: Final Element After Subarray Deletions
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/4/2026, 8:39:23 PM
 * Link: https://leetcode.com/problems/final-element-after-subarray-deletions/
 */

class Solution {
public:
    int finalElement(vector<int>& nums) {
        //012345678987654321
        return max(nums[0], nums[nums.size()-1]);
    }
};

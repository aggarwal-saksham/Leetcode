/*
 * Problem #34: Find First and Last Position of Element in Sorted Array
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/3/2026, 9:03:47 PM
 * Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first =
            lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (first == nums.size() || nums[first] != target)
            return {-1, -1};
        int last =
            upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {first, last};
    }
};

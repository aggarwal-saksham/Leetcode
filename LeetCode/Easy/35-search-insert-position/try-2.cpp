/*
 * Problem #35: Search Insert Position
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/3/2026, 4:13:30 PM
 * Link: https://leetcode.com/problems/search-insert-position/
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it - nums.begin();
    }
};

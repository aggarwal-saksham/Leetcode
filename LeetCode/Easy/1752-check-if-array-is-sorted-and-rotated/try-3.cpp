/*
 * Problem #1752: Check if Array Is Sorted and Rotated
 * Difficulty: Easy
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 7/3/2026, 5:41:18 PM
 * Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
 */

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                cnt++;
            }
        }
        if (nums[0] < nums[nums.size() - 1]) {
            cnt++;
        }
        return (cnt <= 1); 
    }
};

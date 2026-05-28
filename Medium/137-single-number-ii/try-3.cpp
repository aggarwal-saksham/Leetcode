/*
 * Problem #137: Single Number II
 * Difficulty: Medium
 * Submission: Try 3
 * status: Accepted
 * Language: cpp
 * Date: 5/28/2026, 2:50:40 PM
 * Link: https://leetcode.com/problems/single-number-ii/
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int n : nums) {
            ones = (n ^ ones) & ~twos;
            twos = (twos ^ n) & ~ones;
        }
        return ones;
    }
};

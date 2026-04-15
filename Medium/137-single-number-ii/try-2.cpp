/*
 * Problem #137: Single Number II
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 9/30/2024, 11:44:33 PM
 * Link: https://leetcode.com/problems/single-number-ii/
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i = 0; i < nums.size(); i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
        
    }
};

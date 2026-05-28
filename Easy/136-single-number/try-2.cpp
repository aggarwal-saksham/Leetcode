/*
 * Problem #136: Single Number
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/28/2026, 1:58:33 PM
 * Link: https://leetcode.com/problems/single-number/
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR = 0;
        for(int i = 0; i < nums.size(); i++){
            XOR = XOR ^ nums[i];

        }
        return XOR;
    }
};

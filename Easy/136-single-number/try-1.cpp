/*
 * Problem #136: Single Number
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/9/2024, 2:12:52 AM
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

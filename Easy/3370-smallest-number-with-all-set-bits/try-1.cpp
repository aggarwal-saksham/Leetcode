/*
 * Problem #3370: Smallest Number With All Set Bits
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/6/2025, 7:43:24 PM
 * Link: https://leetcode.com/problems/smallest-number-with-all-set-bits/
 */

class Solution {
public:
    int smallestNumber(int n) {
        int num = 1;
        while(n >= num){
            num *= 2;
        }
        return num - 1;
    }
};

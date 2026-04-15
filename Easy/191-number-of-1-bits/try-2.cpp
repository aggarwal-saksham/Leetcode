/*
 * Problem #191: Number of 1 Bits
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 1/15/2026, 10:58:09 PM
 * Link: https://leetcode.com/problems/number-of-1-bits/
 */

class Solution {
public:
    int hammingWeight(int n) {
       int cnt = 0;
       while(n > 0){
        if(n & 1) cnt++;
        n >>= 1;
       }
       return cnt; 
    }
};

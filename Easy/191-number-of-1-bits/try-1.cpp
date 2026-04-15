/*
 * Problem #191: Number of 1 Bits
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 10/7/2024, 10:40:11 PM
 * Link: https://leetcode.com/problems/number-of-1-bits/
 */

class Solution {
public:
    int hammingWeight(int n) {
       int cnt = 0;
       while(n > 0){
        if(n & 1) cnt++;
        n = n>>1;
       }
       return cnt; 
    }
};

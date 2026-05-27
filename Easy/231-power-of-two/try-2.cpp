/*
 * Problem #231: Power of Two
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/28/2026, 2:40:18 AM
 * Link: https://leetcode.com/problems/power-of-two/
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return ((n & (n-1)) == 0);
        
    }
};

/*
 * Problem #371: Sum of Two Integers
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/26/2026, 6:28:44 PM
 * Link: https://leetcode.com/problems/sum-of-two-integers/
 */

class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0, c = 0; 
        int x = 0, y = 0;
        for (int i=0; i<32; i++) {
            x = 1 & a; a = a >> 1; 
            y = 1 & b; b = b >> 1;
            sum = sum | (((x ^ y) ^ c) << i);
            c = (x&y | y&c | c&x);
        }
        return sum;
    }
};

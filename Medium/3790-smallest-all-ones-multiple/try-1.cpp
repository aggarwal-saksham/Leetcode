/*
 * Problem #3790: Smallest All-Ones Multiple
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/28/2025, 2:51:36 PM
 * Link: https://leetcode.com/problems/smallest-all-ones-multiple/
 */

class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k % 2 == 0 || k % 5 == 0) return -1;
        int len = 0, rem = 0;
        while(len <= k){
            rem = (rem * 10 + 1) % k;
            len++;
            if(rem == 0) return len;
        }
        return -1;
    }
};

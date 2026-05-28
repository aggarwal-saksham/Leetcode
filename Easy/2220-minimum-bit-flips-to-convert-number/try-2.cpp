/*
 * Problem #2220: Minimum Bit Flips to Convert Number
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 5/28/2026, 1:50:19 PM
 * Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
 */

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorr = start ^ goal;
        int cnt = 0;
        while(xorr){
            xorr &= (xorr - 1);
            cnt++;
        }
        return cnt;
    }
};

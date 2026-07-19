/*
 * Problem #3993: Maximum Value of an Alternating Sequence
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/18/2026, 11:46:15 PM
 * Link: https://leetcode.com/problems/maximum-value-of-an-alternating-sequence/
 */

class Solution {
public:
    //3,8,7,12,11,16,15,20
    //3 2 7
    long long maximumValue(int n, int s, int m) {
        //7 14
        if(n == 1) return 0LL + s;
        if(n % 2 == 0){
            return 0LL + s + m + (1LL * (m - 1) * (n/2 - 1));
        }
        else return 1LL + s + (1LL * (m - 1) * (n / 2));
    
    }
};

/*
 * Problem #263: Ugly Number
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/28/2025, 2:17:19 AM
 * Link: https://leetcode.com/problems/ugly-number/
 */

class Solution {
public:

    bool isUgly(int n) {
        if(n == 0) return false;
        while(n % 2 == 0){
            n /= 2;
        }
        while(n % 3 == 0){
            n /= 3;
        }
        while(n % 5 == 0){
            n /= 5;
        }

        return n == 1;
    }
};

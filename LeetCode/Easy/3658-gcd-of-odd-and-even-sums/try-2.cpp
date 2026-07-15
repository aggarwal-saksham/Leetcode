/*
 * Problem #3658: GCD of Odd and Even Sums
 * Difficulty: Easy
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 7/15/2026, 2:43:26 PM
 * Link: https://leetcode.com/problems/gcd-of-odd-and-even-sums/
 */

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a = n * n;
        int b = n * n + n;
        while(a > 0 && b > 0){
            if(a > b) a = a%b;
            else b = b%a;
        }

        if(a == 0) return b;
        else return a;
    }
};

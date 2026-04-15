/*
 * Problem #2894: Divisible and Non-divisible Sums Difference
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 5/27/2025, 6:06:27 PM
 * Link: https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/
 */

class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long num1 = 0;
        long long num2 = 0;
        for(int i = 1; i <= n; i++){
            if(i % m != 0) num1 += i;
            else num2 += i;
        }
        return num1 - num2;
    }
};

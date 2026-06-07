/*
 * Problem #3954: Sum of Compatible Numbers in Range I
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/7/2026, 8:04:56 AM
 * Link: https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/
 */

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;

        for (int x = 1; x <= n + k; x++) {
            if (abs(n - x) <= k && ((n & x) == 0)) {
                sum += x;
            }
        }

        return sum;
    }
};

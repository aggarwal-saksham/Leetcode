/*
 * Problem #1922: Count Good Numbers
 * Difficulty: Medium
 * Submission: Try 2
 * status: Accepted
 * Language: cpp
 * Date: 6/4/2026, 11:43:45 PM
 * Link: https://leetcode.com/problems/count-good-numbers/
 */

class Solution {
public:
    int M = 1e9 + 7;
    long long findpow(long long x, long long n) {
        if (n == 0) {
            return 1;
        }
        long long ans = findpow(x, n / 2);
        ans *= ans;
        ans %= M;
        if (n % 2 == 1) {
            ans *= x;
            ans %= M;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        return (long long)findpow(5, (n + 1) / 2) * findpow(4, n / 2) % M;
    }
};

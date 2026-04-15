/*
 * Problem #2550: Count Collisions of Monkeys on a Polygon
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 1/22/2026, 8:12:04 PM
 * Link: https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/
 */

class Solution {
public:
    int monkeyMove(int n) {
     int MOD = 1e9 + 7;
        long long res = 1, base = 2;

        while (n > 0) {
            if (n & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            n >>= 1;
        }

        return (res - 2 + MOD) % MOD;
    }
};


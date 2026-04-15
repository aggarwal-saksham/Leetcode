/*
 * Problem #2147: Number of Ways to Divide a Long Corridor
 * Difficulty: Hard
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 2/20/2026, 2:07:46 PM
 * Link: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
 */

class Solution {
public:
    int numberOfWays(string corridor) {
        // Store 1000000007 in a variable for convenience
        const int MOD = 1e9 + 7;

        // Initial values of three variables
        int zero = 0;
        int one = 0;
        int two = 1;

        // Compute using derived equations
        for (char thing : corridor) {
            if (thing == 'S') {
                zero = one;
                swap(one, two);
            } else {
                two = (two + zero) % MOD;
            }
        }

        // Return the result
        return zero;
    }
};

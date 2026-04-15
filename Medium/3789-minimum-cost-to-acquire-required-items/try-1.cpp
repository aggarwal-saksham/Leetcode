/*
 * Problem #3789: Minimum Cost to Acquire Required Items
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 12/28/2025, 2:39:16 PM
 * Link: https://leetcode.com/problems/minimum-cost-to-acquire-required-items/
 */

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long a1 = ((long long)cost1 * need1) + ((long long)cost2 * need2);
        long long a2 = (long long)costBoth * max(need1, need2);
        long long a3;
        if (need1 > need2) {
            a3 = ((long long)costBoth * need2) +
                 ((long long)cost1 * (need1 - need2));

        } else {
            a3 = ((long long)costBoth * need1) +
                 ((long long)cost2 * (need2 - need1));
        }

        return min(a1, min(a2, a3));
    }
};

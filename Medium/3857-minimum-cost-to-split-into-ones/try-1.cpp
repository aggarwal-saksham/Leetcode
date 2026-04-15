/*
 * Problem #3857: Minimum Cost to Split into Ones
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/1/2026, 7:24:12 PM
 * Link: https://leetcode.com/problems/minimum-cost-to-split-into-ones/
 */

class Solution {
public:
    int minCost(int n) {
       if(n == 1) return 0;
        if(n == 2) return 1;
        if(n == 3) return 3;
        return (n - 1) + minCost(n - 1);
    }
};

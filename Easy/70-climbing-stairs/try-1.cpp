/*
 * Problem #70: Climbing Stairs
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 3/13/2025, 12:07:03 AM
 * Link: https://leetcode.com/problems/climbing-stairs/
 */

class Solution {
public:
    int sol(int n, vector<int> &t){
        if(n <= 2) return n;
        if(t[n] != -1) return t[n];

        return t[n] =  sol(n - 1, t) + sol(n - 2, t);
    }
    int climbStairs(int n) {
        vector<int> t(n + 1, -1);
        return sol(n, t);
    }
};

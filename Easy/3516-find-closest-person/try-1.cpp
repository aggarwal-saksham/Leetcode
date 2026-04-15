/*
 * Problem #3516: Find Closest Person
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 9/4/2025, 2:25:00 PM
 * Link: https://leetcode.com/problems/find-closest-person/
 */

class Solution {
public:
    int findClosest(int x, int y, int z) {
        if(abs(x - z) < abs(y-z)) return 1;
        else if (abs(x - z) > abs(y-z)) return 2;
        else return 0;
    }
};

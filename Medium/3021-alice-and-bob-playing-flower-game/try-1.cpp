/*
 * Problem #3021: Alice and Bob Playing Flower Game
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/29/2025, 2:39:54 PM
 * Link: https://leetcode.com/problems/alice-and-bob-playing-flower-game/
 */

class Solution {
public:
    long long flowerGame(int n, int m) {
        //n = 2, m = 6
        //1,2 1,4 1,6
        //2,1 2,3 2,5
        long long ans = 0;
        ans = (1LL *m * n) / 2;
        return ans;
    }
};

/*
 * Problem #4034: Minimum Bishop Moves to Reach Target
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 8/29/2026, 8:07:54 PM
 * Link: https://leetcode.com/problems/minimum-bishop-moves-to-reach-target/
 */

class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if((source[0] + source[1] + target[0] + target[1]) % 2 != 0) return -1;
        if(source == target) return 0;
        if((source[1] + source[0] == target[1] + target[0]) || (source[1] - source[0]) == (target[1] - target[0])) return 1;
        else return 2;
    }
};

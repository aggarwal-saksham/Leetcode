/*
 * Problem #3968: Maximum Manhattan Distance After All Moves
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 6/25/2026, 12:24:25 AM
 * Link: https://leetcode.com/problems/maximum-manhattan-distance-after-all-moves/
 */

class Solution {
public:
    int maxDistance(string s) {
        int v = 0, h = 0, cnt = 0;
        for(char c : s){
            if(c == 'R') h++;
            else if(c == 'L') h--;
            else if(c == 'U') v++;
            else if(c == 'D') v--;
            else {
                cnt++;
            }
            
        }
        if(h < 0) h *= -1;
        if(v < 0) v *= -1;
        return v + h + cnt;
    }
};

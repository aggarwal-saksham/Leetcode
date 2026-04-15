/*
 * Problem #926: Flip String to Monotone Increasing
 * Difficulty: Medium
 * Submission: Try 1
 * status: Accepted
 * Language: cpp
 * Date: 7/18/2025, 12:52:35 AM
 * Link: https://leetcode.com/problems/flip-string-to-monotone-increasing/
 */

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0, flips = 0;
        for(char c : s){
            if(c == '1') ones++;
            else{
                flips++;
                flips = min(flips, ones);
            }
        }
        return flips;
    }
};
